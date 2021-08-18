#!/bin/bash

GKE_ZONE=${GKE_ZONE:-'us-east1-a'}
YCSB_RUNNER_NAME=${YCSB_RUNNER_NAME:-'ycsb-runner'}
gcloud compute instances delete $YCSB_RUNNER_NAME --zone $GKE_ZONE -q
