#!/bin/bash

# This script loops through the cluster configurations specified in
# clusters.json, bringing up the cluster as defined and then running
# all the YCSB benchmarks against it, and then pulls the results.

# ensure google cloud project is set
project_id=`gcloud config list project | sed -n 2p | cut -d " " -f 3`
if [ -z $project_id ]
then
  echo Project ID not set, use 'gcloud config set project PROJECT' to set it
  exit -1
fi

GKE_ZONE=${GKE_ZONE:-'us-east1-a'} # zone for ycsb-runners, gke cluster
BENCHMARKS_BASE_DIR=${BENCHMARKS_BASE_DIR:-~/ycsb_benchmarks} # where to save results
CLUSTERS_CONFIG=${CLUSTERS_CONFIG:-'cluster-replicas.json'}
WORKLOAD_CONFIG=${WORKLOAD_CONFIG:-'workloads-replicas.json'}
YCSB_RUNNER_NAME=${YCSB_RUNNER_NAME:-'ycsb-runner'}
SKIP_CLUSTER=${SKIP_CLUSTER:-'false'}

function json_to_params() {
  json=$1
  json=`echo $json | perl -pe "s/(,)(?=(?:[^']|'[^']*')*$)/;/g"` # Replace non quoted , with ;
  json=`echo $json | perl -pe "s/: /:/g"` # Remove extra whitespace
  json=`echo "${json:1:-1}"`  # Get rid of open/close brackets
  params=''
  for i in `echo $json | tr ";" " "`; do
    param_name=`echo $i | cut -f1 -d ':'`
    val=`echo $i | cut -f2 -d ':'`
    params="$params ${param_name:2:-1}=${val:2:-1}"
  done
  echo $params
}

git clone https://github.com/youtube/vitess.git

gke_config=`python -c "import json;obj=json.load(open('$CLUSTERS_CONFIG'));print obj['gke_cluster']"`
gke_params=`json_to_params "$gke_config"`

if ! $SKIP_CLUSTER; then
  echo Bringing up k8s cluster
  cd vitess/examples/kubernetes
  eval $gke_params GKE_ZONE=$GKE_ZONE ./cluster-up.sh 2>&1 | tee cluster-up.txt
  cd ../../..
  echo k8s cluster is up
fi

num_scenarios=`python -c "import json;obj=json.load(open('$CLUSTERS_CONFIG'));print len(obj['scenarios'])"`
max_ycsb_runners=0
for i in `seq 0 $(($num_scenarios-1))`; do
  num_ycsb_runners=`python -c "import json;obj=json.load(open('$CLUSTERS_CONFIG'));print obj['scenarios'][$i]['NUM_YCSB_RUNNERS']"`
  max_ycsb_runners=$(($num_ycsb_runners > $max_ycsb_runners ? $num_ycsb_runners : $max_ycsb_runners))
done

echo Bringing up $max_ycsb_runners YCSB instances

# Bring up YCSB runners and reuse them for all cluster configurations
for i in `seq 1 $max_ycsb_runners`; do
  YCSB_RUNNER_NAME=${YCSB_RUNNER_NAME}$i GKE_ZONE=$GKE_ZONE ./ycsb-runner-up.sh &
done
wait

echo YCSB instances are up

for i in `seq 0 $(($num_scenarios-1))`; do
  # Convert json line format into environment variable line format
  # e.g. {u'TABLETS_PER_SHARD': u'3', u'SHARDS': u'-80,80-'} becomes
  # TABLETS_PER_SHARD=3 SHARDS=-80,80-
  config=`python -c "import json;obj=json.load(open('$CLUSTERS_CONFIG'));print obj['scenarios'][$i]['cluster']"`
  params=`json_to_params "$config"`
  num_ycsb_runners=`python -c "import json;obj=json.load(open('$CLUSTERS_CONFIG'));print obj['scenarios'][$i]['NUM_YCSB_RUNNERS']"`

  benchmarks_dir=`date +"$BENCHMARKS_BASE_DIR/%Y_%m_%d_%H_%M"`
  mkdir -p $benchmarks_dir

  # Bring up the cluster
  cd vitess/examples/kubernetes
  cp cluster-up.txt $benchmarks_dir/cluster-up.txt
  eval $params GKE_ZONE=$GKE_ZONE ./vitess-up.sh 2>&1 | tee $benchmarks_dir/vitess-up.txt
  cd ../../..

  WORKLOAD_CONFIG=$WORKLOAD_CONFIG BENCHMARKS_DIR=$benchmarks_dir GKE_ZONE=$GKE_ZONE NUM_YCSB_RUNNERS=$num_ycsb_runners ./run-all-benchmarks.sh

  # Cleanup - tear down the cluster
  cd vitess/examples/kubernetes
  eval $params GKE_ZONE=$GKE_ZONE ./vitess-down.sh 2>&1 | tee $benchmarks_dir/vitess-down.txt
  cd ../../..
done


cd vitess/examples/kubernetes
eval $gke_params ./cluster-down.sh
cd ../../..

rm -rf vitess

for i in `seq 1 $max_ycsb_runners`; do
  YCSB_RUNNER_NAME=${YCSB_RUNNER_NAME}$i GKE_ZONE=$GKE_ZONE ./ycsb-runner-down.sh &
done
wait
