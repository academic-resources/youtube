#!/bin/bash

# This script performs the setup necessary to get a newly created instance
# ready to run the YCSB benchmarks

sudo apt-get update
sudo apt-get install openjdk-7-jdk -y
sudo apt-get install maven -y
sudo apt-get install git-core -y
export JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64
export PATH=$JAVA_HOME/bin:$PATH
git clone https://github.com/youtube/YCSB.git
export MAVEN_OPTS=-Xss16m
cd YCSB
mvn clean install -pl vitess -am -DskipTests
