package com.yahoo.ycsb.db;

import com.yahoo.ycsb.ByteArrayByteIterator;
import com.yahoo.ycsb.ByteIterator;
import com.yahoo.ycsb.DB;
import com.yahoo.ycsb.DBException;
import com.yahoo.ycsb.Status;

import com.youtube.vitess.client.Context;
import com.youtube.vitess.client.VTGateConn;
import com.youtube.vitess.client.VTGateTx;
import com.youtube.vitess.client.cursor.Cursor;
import com.youtube.vitess.client.cursor.Row;
import com.youtube.vitess.client.grpc.GrpcClientFactory;
import com.youtube.vitess.proto.Query.Field;
import com.youtube.vitess.proto.Topodata.TabletType;
import com.youtube.vitess.proto.Vtrpc.CallerID;

import org.joda.time.Duration;

import java.util.Arrays;
import java.util.HashMap;
import java.net.InetSocketAddress;
import java.util.List;
import java.util.Set;
import java.util.Vector;

/**
 * Vitess client for YCSB framework.
 */
public class VitessClient extends DB {
  private Context ctx;
  private VTGateConn vtgate;
  private QueryCreator queryCreator;
  private String vtgateAddress;
  private String keyspace;
  private TabletType readTabletType;
  private TabletType writeTabletType;
  private String privateKeyField;
  private boolean serverAutoCommitEnabled;
  private boolean debugMode;

  private static final CallerID CALLER_ID =
      CallerID.newBuilder()
          .setPrincipal("ycsb_principal")
          .setComponent("ycsb_component")
          .setSubcomponent("ycsb_subcomponent")
          .build();

  private static final String DEFAULT_CREATE_TABLE =
      "CREATE TABLE usertable(YCSB_KEY BIGINT(20) UNSIGNED PRIMARY KEY, "
      + "field0 TEXT, field1 TEXT, field2 TEXT, field3 TEXT, field4 TEXT, "
      + "field5 TEXT, field6 TEXT, field7 TEXT, field8 TEXT, field9 TEXT"
      + ") Engine=InnoDB";
  private static final String DEFAULT_DROP_TABLE = "drop table if exists usertable";

  @Override
  public void init() throws DBException {
    vtgateAddress = getProperties().getProperty("hosts", "");
    String[] vtgateAddressSplit = vtgateAddress.split(":");
    keyspace = getProperties().getProperty("keyspace", "ycsb");
    String shardingColumnName = getProperties().getProperty(
        "vitess_sharding_column_name", "keyspace_id");
    boolean keyIsString = Boolean.parseBoolean(getProperties().getProperty(
        "vitess_key_is_string", "true"));
    writeTabletType = TabletType.MASTER;
    readTabletType = TabletType.REPLICA;
    privateKeyField = getProperties().getProperty("vitess_primary_key_field", "YCSB_KEY");
    debugMode = getProperties().getProperty("debug") != null;
    serverAutoCommitEnabled = Boolean.parseBoolean(getProperties().getProperty(
        "server_autocommit_enabled", "false"));

    ctx = Context.getDefault().withDeadlineAfter(Duration.millis(10000)).withCallerId(CALLER_ID);
    queryCreator = new QueryCreator(shardingColumnName, keyIsString);

    String createTable = getProperties().getProperty("createTable", DEFAULT_CREATE_TABLE);
    String dropTable = getProperties().getProperty("dropTable", DEFAULT_DROP_TABLE);
    vtgate = new VTGateConn((new GrpcClientFactory()).create(
        ctx, new InetSocketAddress(vtgateAddressSplit[0],
        Integer.parseInt(vtgateAddressSplit[1]))));

    if(Boolean.parseBoolean(getProperties().getProperty("doCreateTable", "false"))) {
      String[] shards = getProperties().getProperty("shards", "0").split(",");
      if (!"skip".equalsIgnoreCase(createTable)) {
        try {
          VTGateTx tx = vtgate.begin(ctx).checkedGet();
          if (debugMode) {
            System.out.println(dropTable);
          }
          tx.executeShards(
              ctx, dropTable, keyspace, Arrays.asList(shards),
              new HashMap<String, String>(), TabletType.MASTER).checkedGet();
          if (debugMode) {
            System.out.println(createTable);
          }
          tx.executeShards(
              ctx, createTable, keyspace, Arrays.asList(shards),
              new HashMap<String, String>(), TabletType.MASTER).checkedGet();
          tx.commit(ctx).checkedGet();
        } catch (Exception e) {
          e.printStackTrace();
        }
      }
    }
  }

  @Override
  public Status delete(String table, String key) {
    QueryCreator.Query query =
        queryCreator.createDeleteQuery(keyspace, writeTabletType, table, privateKeyField, key);

    return applyMutation(query);
  }

  @Override
  public Status insert(String table, String key, HashMap<String, ByteIterator> result) {
    QueryCreator.Query query = queryCreator.createInsertQuery(keyspace,
        writeTabletType,
        table,
        privateKeyField,
        key,
        result);

    return applyMutation(query);
  }

  /**
   * @param query
   * @return
   */
  private Status applyMutation(QueryCreator.Query query) {
    try {
      if (serverAutoCommitEnabled) {
        vtgate.executeKeyspaceIds(
            ctx, query.getQuery(), query.getKeyspace(), query.getKeyspaceId(),
            query.getBindVars(), query.getTabletType()).checkedGet();
      } else {
        VTGateTx tx = vtgate.begin(ctx).checkedGet();
        tx.executeKeyspaceIds(
            ctx, query.getQuery(), query.getKeyspace(), query.getKeyspaceId(),
            query.getBindVars(), query.getTabletType()).checkedGet();
        tx.commit(ctx).checkedGet();
      }
    } catch (Exception e) {
      e.printStackTrace();
      return new Status("ERROR", e.getMessage());
    }
    return Status.OK;
  }

  @Override
  public Status read(String table, String key, Set<String> fields,
      HashMap<String, ByteIterator> result) {
    QueryCreator.Query query = queryCreator.createSelectQuery(keyspace,
        readTabletType,
        table,
        privateKeyField,
        key,
        fields);
    try {
      Cursor cursor = vtgate.executeKeyspaceIds(
          ctx, query.getQuery(), query.getKeyspace(), query.getKeyspaceId(),
          query.getBindVars(), query.getTabletType()).checkedGet();
      if (cursor.getRowsAffected() != 1) {
        return new Status("ERROR", "No rows returned");
      }
      List<Field> cursorFields = cursor.getFields();
      Row row = cursor.next();
      for (int i = 0; i < cursorFields.size(); i++) {
        byte[] value = row.getBytes(i);
        if (value == null) {
          value = new byte[] {};
        }
        result.put(cursorFields.get(i).getName(), new ByteArrayByteIterator(value));
      }
    } catch (Exception e) {
      e.printStackTrace();
      return new Status("ERROR", e.getMessage());
    }
    return Status.OK;
  }

  @Override
  public Status scan(String table, String key, int num, Set<String> fields,
      Vector<HashMap<String, ByteIterator>> result) {
    QueryCreator.Query query = queryCreator.createSelectScanQuery(keyspace,
        readTabletType,
        table,
        privateKeyField,
        key,
        fields,
        num);
    try {
      Cursor cursor = vtgate.executeKeyspaceIds(
          ctx, query.getQuery(), query.getKeyspace(), query.getKeyspaceId(),
          query.getBindVars(), query.getTabletType()).checkedGet();
      Row row = cursor.next();
      while (row != null) {
        HashMap<String, ByteIterator> rowResult = new HashMap<>();
        List<Field> cursorFields = cursor.getFields();
        for (int i = 0; i < cursorFields.size(); i++) {
          byte[] value = row.getBytes(i);
          if (value == null) {
            value = new byte[] {};
          }
          rowResult.put(cursorFields.get(i).getName(), new ByteArrayByteIterator(value));
        }
        result.add(rowResult);
        row = cursor.next();
      }
    } catch (Exception e) {
      e.printStackTrace();
      return new Status("ERROR", e.getMessage());
    }
    return Status.OK;
  }

  @Override
  public Status update(String table, String key, HashMap<String, ByteIterator> result) {
    QueryCreator.Query query = queryCreator.createUpdateQuery(keyspace,
        writeTabletType,
        table,
        privateKeyField,
        key,
        result);

    return applyMutation(query);
  }
}
