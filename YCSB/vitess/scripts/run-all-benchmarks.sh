#!/bin/bash

# This script runs all benchmarks against an existing cluster and grabs log files

BENCHMARKS_BASE_DIR=${BENCHMARKS_BASE_DIR:-~/ycsb_benchmarks}
GKE_ZONE=${GKE_ZONE:-'us-east1-a'} # zone for executing ycsb-runner
GKE_CLUSTER_NAME=${GKE_CLUSTER_NAME:-'example'}
BENCHMARKS_DIR=${BENCHMARKS_DIR:-`date +"$BENCHMARKS_BASE_DIR/%Y_%m_%d_%H_%M"`} # where to save results
VTGATE_HOST=${VTGATE_HOST:-''}
YCSB_RUNNER_NAME=${YCSB_RUNNER_NAME:-'ycsb-runner'}
NUM_YCSB_RUNNERS=${NUM_YCSB_RUNNERS:-1}
WORKLOAD_CONFIG=${WORKLOAD_CONFIG:-'workloads.json'}

# Get region from zone (everything to last dash)
gke_region=`echo $GKE_ZONE | sed "s/-[^-]*$//"`

mkdir -p $BENCHMARKS_DIR

if [ -z $VTGATE_HOST ]
then
  # get the external vtgate ip from the existing cluster
  vtgate_port=15001
  vtgate_pool=`vitess/examples/kubernetes/util/get_forwarded_pool.sh $GKE_CLUSTER_NAME $gke_region $vtgate_port`
  vtgate_ip=`gcloud compute forwarding-rules list | grep $vtgate_pool | awk '{print $3}'`
  if [ -z "$vtgate_ip" ]
  then
    echo No vtgate forwarding-rule found
    exit -1
  else
    VTGATE_HOST="$vtgate_ip:$vtgate_port"
  fi
fi

for i in `seq 1 $NUM_YCSB_RUNNERS`; do
  gcloud compute ssh ${YCSB_RUNNER_NAME}$i --zone $GKE_ZONE --command 'mkdir ~/workloadlogs'
done

# Create a temporary script which includes the proper vtgate ip and give it
# to the ycsb-runner instance to execute
python workload-runner-generator.py $VTGATE_HOST $NUM_YCSB_RUNNERS $WORKLOAD_CONFIG
paste -d"\n" workload-runner*.sh | sed /^$/d > workload-runner.sh
cnt=0
while read cmd; do
  if ! [ "`echo $cmd | grep 'CREATE TABLE'`" ] || [ "$(($cnt % $NUM_YCSB_RUNNERS))" -eq 0 ]; then
    ycsb_runner=${YCSB_RUNNER_NAME}$(($(($cnt  % $NUM_YCSB_RUNNERS)) + 1))
    echo running on $ycsb_runner
    gcloud compute ssh $ycsb_runner --zone $GKE_ZONE --command "$cmd" < /dev/null &
  fi
  if [ "$(($(($cnt + 1)) % $NUM_YCSB_RUNNERS))" -eq 0 ]; then
    wait
  fi
  let cnt=cnt+1
done < workload-runner.sh

# Save off data - benchmark results + gcloud information
for i in `seq 1 $NUM_YCSB_RUNNERS`; do
  mkdir $BENCHMARKS_DIR/runner-$i
  gcloud compute copy-files ${YCSB_RUNNER_NAME}$i:workloadlogs $BENCHMARKS_DIR/runner-$i --zone $GKE_ZONE
done
kubectl get pods > $BENCHMARKS_DIR/gcloud-pods.txt
gcloud compute instances list > $BENCHMARKS_DIR/gcloud-instances.txt

# Cleanup - tear down log directories, temporary scripts, etc.
for i in `seq 1 $NUM_YCSB_RUNNERS`; do
  gcloud compute ssh ${YCSB_RUNNER_NAME}$i --zone $GKE_ZONE --command 'rm -rf ~/workloadlogs'
done

cp workload-runner*.sh $BENCHMARKS_DIR
rm workload-runner*.sh
