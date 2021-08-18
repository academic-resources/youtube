#!/bin/bash

GKE_ZONE=${GKE_ZONE:-'us-east1-a'}
GKE_MACHINE_TYPE=${GKE_MACHINE_TYPE:-'n1-standard-16'}
YCSB_RUNNER_NAME=${YCSB_RUNNER_NAME:-'ycsb-runner'}

gcloud compute instances create $YCSB_RUNNER_NAME --machine-type $GKE_MACHINE_TYPE --zone $GKE_ZONE
sleep 30
gcloud compute ssh $YCSB_RUNNER_NAME --zone $GKE_ZONE --command 'bash -s' < ycsb-runner-setup.sh
if [ -n "$NEWRELIC_LICENSE_KEY" ]; then
  start_agent_file='./vitess/examples/kubernetes/newrelic_start_agent.sh'
  if [ -f "$start_agent_file" ]; then
    gcloud compute copy-files $start_agent_file $YCSB_RUNNER_NAME:~/
    gcloud compute ssh $YCSB_RUNNER_NAME --zone $GKE_ZONE --command "bash -c '~/newrelic_start_agent.sh ${NEWRELIC_LICENSE_KEY}'"
  fi
fi
