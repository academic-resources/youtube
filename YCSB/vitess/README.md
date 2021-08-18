Vitess YCSB Driver
==================

# Test using the command line unit test tool

  ```sh
  export MAVEN_OPTS=-Xss16m
  mvn clean package -pl vitess -am
  mvn install -pl vitess -am
  java -cp vitess/target/vitess-binding-0.1.4.jar com.yahoo.ycsb.CommandLine \
      -db com.yahoo.ycsb.db.VitessClient \
      -p hosts=localhost:15007 \
      -p keyspace=test_keyspace \
      -p createTable="create table usertable (pri_key varbinary(50), first varbinary(50), last varbinary(50), keyspace_id varbinary(50) NOT NULL, primary key (pri_key)) Engine=InnoDB" \
      -p dropTable="drop table if exists usertable"
  insert brianfrankcooper first=brian last=cooper
  read brianfrankcooper
  ```

# Executing Workload

  ```sh
  # load the initial data. By default this drops and recreates the usertable with 9 fields and keyspace_id
  bin/ycsb load vitess -P workloads/workloada -p hosts=localhost:15007 -p keyspace=test_keyspace
  # Run the workload. Specify createTable=skip to avoid dropping and recreating the usertable, else the loaded data will be lost.
  bin/ycsb run vitess -P workloads/workloada -p hosts=localhost:15007 -p keyspace=test_keyspace -p createTable=skip
  ```
  Use -p debug=true to print the sql statements

