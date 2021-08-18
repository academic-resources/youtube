#!/bin/bash

base_dir=$1
print_header=$2

function print_overall_metrics() {
  logfile=$1
  overall_runtime=`cat $logfile | awk '$2~/^RunTime/ {print $3}'`
  overall_throughput=`cat $logfile | awk '$2~/^Throughput/ {print $3}'`
  echo -n $overall_runtime,$overall_throughput,
}

function print_metrics () {
  logfile=$1
  phase=$2
  metrics=''
  for metric in Operations AverageLatency MinLatency MaxLatency 95th 99th; do
    metric_str=`cat $logfile | awk '$1=="['"$phase"']," && $2~/^'"$metric"'/ {print $3}'`
    metrics=$metrics,$metric_str
  done
  metrics=`echo $metrics | cut -c2-`
  echo -n $metrics
}

function print_cluster_metrics () {
  cluster_results_dir=$1
  num_runners=`ls -d $cluster_results_dir/*/ | wc -l`

  timestamp=`basename $cluster_results_dir`
  num_shards=`cat $cluster_results_dir/vitess-up.txt | awk '$2~/^Shards/ {print $3}' | tr ',' ' ' | wc -w`
  tablets_per_shard=`cat $cluster_results_dir/vitess-up.txt | awk '$2~/^Tablets/ {print $5}'`
  machine_type=`cat $cluster_results_dir/cluster-up.txt | awk '$2~/^Machine/ {print $4}'`
  ssd_size=`cat $cluster_results_dir/cluster-up.txt | awk '$2~/^SSD/ {print $4;exit;}'`
  num_vtgates=`cat $cluster_results_dir/vitess-up.txt | awk '$2~/^VTGate/ {print $4}'`
  num_nodes=`cat $cluster_results_dir/cluster-up.txt | awk '$2~/^Num/ {print $4;exit;}'`

  for runner in `ls -d $cluster_results_dir/*/`; do
    index=0
    workload_logs_dir="$runner/workloadlogs"
    for logfile in $workload_logs_dir/*; do
      command_line=`cat $logfile | awk 'NR==2'`
      num_threads=`echo $command_line | awk '/-threads/ { for (x=1;x<=NF;x++) if ($x~"-threads") print $(x+1) }'`
      if [ $num_threads -eq 1 ]; then continue; fi
      workload=`echo $command_line | awk '/YCSB/ { for (x=1;x<=NF;x++) if ($x~"YCSB") print $(x) }' | awk -F'/' '{print $3}'`
      for phase in INSERT UPDATE READ-MODIFY-WRITE READ SCAN; do
        has_metric=`cat $logfile | awk '$1=="['"$phase"']," && $2~/^Operations/ {print $3}'`
        if [ -z $has_metric ]; then
          continue
        else
          echo -n $index,$timestamp,$num_shards,$tablets_per_shard,$machine_type,$ssd_size,$num_vtgates,$num_nodes,$workload,
          print_overall_metrics $logfile
          echo -n $num_threads,$phase,
          print_metrics $logfile $phase
	  echo ",`basename $runner`"
	  let index=index+1
        fi
      done
    done
  done
}

if [ -n "$print_header" ] && "$print_header"; then
  echo Index,Timestamp,Shards,Tablets_per_shard,Machine_type,SSD_size,VtGate_count,GCE_node_count,Workload,RunTime_ms,Thoughput_ops_per_sec,Threads,Phase,Operations,Average_Latency_us,Min_Latency_us,Max_Latency_us,P95_Latency_ms,P99_Latency_ms,YCSB_Runner_Name
fi

for i in $base_dir/*; do
  if [ -d "$i" ]; then
    print_cluster_metrics $i
  fi
done
