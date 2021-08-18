#!/bin/bash
csv_file=$1
log_dir=$2
print_header=$3

# Print header
if [ -n "$print_header" ] && "$print_header"; then
  echo Index,Timestamp,Shards,Tablets_per_shard,Machine_type,SSD_size,VtGate_count,GCE_node_count,Workload,RunTime_ms,Thoughput_ops_per_sec,Threads,Phase,Operations,Average_Latency_us,Min_Latency_us,Max_Latency_us,P95_Latency_ms,P99_Latency_ms,Num_YCSB_Runners
fi

# Split into separate runner files
cat $csv_file | awk -F, -v var=$log_dir '{print > var"/"$2".csv"}'
for i in $log_dir/*.csv; do
  basename=${i%%.*}
  cat $i | awk -F, -v var=$basename '{print > var$NF".csv"}'
  num_runners=`ls ${basename}runner-*.csv | wc -l`

  # Sum, Average, Min, Max certain columns:
  # Sum columns 11, 14  (Throughput, Operations)
  # Average column 15 (Avg latency)
  # Min column 16 (Min latency)
  # Max columns 17, 18, 19 (max, p95, p99 latencies)
  awk -F, -v var=$num_runners '{cnt++;c9[$1]=$9;c10[$1]+=$10;c11[$1]+=$11;c12[$1]=$12;c13[$1]=$13;c14[$1]+=$14;c15[$1]+=$14*$15;c16[$1][cnt]=$16;c17[$1][cnt]=$17;c18[$1][cnt]=$18;c19[$1][cnt]=$19} END {for (i=0;i<FNR;i++) {asort(c16[i]);c17i=asort(c17[i]);c18i=asort(c18[i]);c19i=asort(c19[i]); print i,$2,$3,$4,$5,$6,$7,$8,c9[i],c10[i]/var,c11[i],c12[i],c13[i],c14[i],c15[i]/c14[i],c16[i][1],c17[i][c17i],c18[i][c18i],c19[i][c19i],var}}' OFS=',' ${basename}runner-*.csv
done

