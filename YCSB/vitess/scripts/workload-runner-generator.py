import json
import sys

def main(unused_argv):
  vtgate_host = sys.argv[1]
  ycsb_count = int(sys.argv[2])
  workload_file = sys.argv[3] if len(sys.argv) > 3 else 'workloads.json'
  shards = sys.argv[4] or '0'
  with open(workload_file) as data_file:
    data = json.load(data_file)

  for i in xrange(ycsb_count):
    with open('workload-runner%d.sh' % i,'w') as cmd_file:
      for index, workload in enumerate(data["workloads"]):
        action = workload["action"]
        create_table = "'CREATE TABLE usertable (YCSB_KEY VARCHAR (255) PRIMARY KEY, field0 TEXT, field1 TEXT, keyspace_id BIGINT unsigned NOT NULL)'"
        cmd = 'YCSB/bin/ycsb %s vitess -P YCSB/workloads/workload%s -p hosts=%s -p shards=%s -p keyspace=test_keyspace -p insertorder=ordered -p fieldcount=2 -threads %s -s' % (
          action, workload["workload"], vtgate_host, shards, workload["threads"])
        if action == 'run':
          cmd += ' -p operationcount=%s' % workload['operationcount']
        else:
          cmd += ' -p recordcount=%s -p insertcount=%s -p insertstart=%d' % (workload['recordcount'], workload['recordcount'], i * int(workload['recordcount']))
        if workload.has_key('createtable') and workload['createtable'] == 'True':
          cmd += ' -p createTable=%s -p doCreateTable=true' % create_table
        if workload.has_key('maxexecutiontime'):
          cmd += ' -p maxexecutiontime=%s' % workload['maxexecutiontime']
        # sleep for 1 min before each run
        if action == 'run':
          cmd_file.write('sleep 60\n')
        cmd_file.write('%s > ~/workloadlogs/workload%s%02d.txt\n' % (cmd, workload["workload"], index))
        if action == 'load' and workload.has_key('wait'):
          cmd_file.write('sleep %s\n' % workload['wait'])


if __name__ == '__main__':
  main(sys.argv)
