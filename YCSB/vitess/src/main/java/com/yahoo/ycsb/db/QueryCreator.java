package com.yahoo.ycsb.db;

import com.google.common.hash.Hashing;
import com.google.common.primitives.Longs;
import com.google.common.primitives.UnsignedLong;

import com.yahoo.ycsb.ByteIterator;
import com.youtube.vitess.proto.Topodata.TabletType;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

/**
 * Helper class for generating YCSB queries.
 */
public class QueryCreator {
  /**
   * Class representing a query to pass to VTGate.
   */
  public class Query {
    private String query;
    private String keyspace;
    private TabletType tabletType;
    private List<byte[]> keyspaceId;
    private Map<String, Object> bindVars;

    public Query(String query, String keyspace, TabletType tabletType,
                 String key, String keyField) {
      this.query = query;
      this.keyspace = keyspace;
      this.tabletType = tabletType;
      this.bindVars = new HashMap<String, Object>();
      long hashedKeyspaceId = Hashing.murmur3_128().hashUnencodedChars(key).asLong();
      this.keyspaceId = Arrays.asList(Longs.toByteArray(hashedKeyspaceId));
      // YCSB keys are user#######, if using a numeric pk, trim first 4 chars
      Object bindKey = QueryCreator.keyIsString ? key : new Long(key.substring(4));
      addBindVar(keyField, bindKey);
      addBindVar(QueryCreator.shardingColumnName, UnsignedLong.fromLongBits(hashedKeyspaceId));
    }

    public void addBindVar(String key, Object value) {
      this.bindVars.put(key, value);
    }

    public String getQuery() {
      return query;
    }

    public String getKeyspace() {
      return keyspace;
    }

    public TabletType getTabletType() {
      return tabletType;
    }

    public List<byte[]> getKeyspaceId() {
      return keyspaceId;
    }

    public Map<String, Object> getBindVars() {
      return bindVars;
    }
  }

  private static String shardingColumnName;
  private static boolean keyIsString;

  public QueryCreator(String shardingColumnName, boolean keyIsString) {
    QueryCreator.shardingColumnName = shardingColumnName;
    QueryCreator.keyIsString = keyIsString;
  }

  public Query createInsertQuery(String keyspace,
      TabletType tabletType,
      String table,
      String keyField,
      String key,
      HashMap<String, ByteIterator> result) {
    StringBuilder sqlBuilder = new StringBuilder();

    sqlBuilder.append("insert into ");
    sqlBuilder.append(table);
    sqlBuilder.append("(");
    sqlBuilder.append(keyField);
    for (String field : result.keySet()) {
      sqlBuilder.append(", ");
      sqlBuilder.append(field);
    }
    sqlBuilder.append(")");
    sqlBuilder.append(" values(");
    sqlBuilder.append(":");
    sqlBuilder.append(keyField);
    for (String field : result.keySet()) {
      sqlBuilder.append(", :");
      sqlBuilder.append(field);
    }
    sqlBuilder.append(")");

    Query query = new Query(sqlBuilder.toString(), keyspace, tabletType, key, keyField);
    for (Entry<String, ByteIterator> val : result.entrySet()) {
      if (val.getKey() != keyField) {
        query.addBindVar(val.getKey(), val.getValue().toString());
      }
    }

    return query;
  }

  public Query createSelectQuery(String keyspace,
      TabletType tabletType,
      String table,
      String keyField,
      String key,
      Set<String> fields) {

    StringBuilder sqlBuilder = new StringBuilder();

    sqlBuilder.append("select ");
    if (fields == null) {
      sqlBuilder.append(" * ");
    } else {
      sqlBuilder.append(keyField);
      for (String field : fields) {
        sqlBuilder.append(", ");
        sqlBuilder.append(field);
      }
    }
    sqlBuilder.append(" from ");
    sqlBuilder.append(table);
    sqlBuilder.append(" where ");
    sqlBuilder.append(keyField);
    sqlBuilder.append(" = :");
    sqlBuilder.append(keyField);

    return new Query(sqlBuilder.toString(), keyspace, tabletType, key, keyField);
  }

  public Query createSelectScanQuery(String keyspace,
      TabletType tabletType,
      String table,
      String keyField,
      String key,
      Set<String> fields,
      int rowCount) {

    StringBuilder sqlBuilder = new StringBuilder();

    sqlBuilder.append("select ");
    if (fields == null) {
      sqlBuilder.append(" * ");
    } else {
      sqlBuilder.append(keyField);
      for (String field : fields) {
        sqlBuilder.append(", ");
        sqlBuilder.append(field);
      }
    }
    sqlBuilder.append(" from ");
    sqlBuilder.append(table);
    sqlBuilder.append(" where ");
    sqlBuilder.append(keyField);
    sqlBuilder.append(" >= :");
    sqlBuilder.append(keyField);
    sqlBuilder.append(" limit ");
    sqlBuilder.append(rowCount);

    return new Query(sqlBuilder.toString(), keyspace, tabletType, key, keyField);
  }

  public Query createUpdateQuery(String keyspace,
      TabletType tabletType,
      String table,
      String keyField,
      String key,
      HashMap<String, ByteIterator> result) {
    StringBuilder sqlBuilder = new StringBuilder();

    sqlBuilder.append("update ");
    sqlBuilder.append(table);
    sqlBuilder.append(" set ");
    boolean first = true;
    for (String field : result.keySet()) {
      if (first) {
        first = false;
      } else {
        sqlBuilder.append(", ");
      }
      sqlBuilder.append(field);
      sqlBuilder.append(" = :");
      sqlBuilder.append(field);
    }
    sqlBuilder.append(" where ");
    sqlBuilder.append(keyField);
    sqlBuilder.append(" = :");
    sqlBuilder.append(keyField);

    Query query = new Query(sqlBuilder.toString(), keyspace, tabletType, key, keyField);
    for (Entry<String, ByteIterator> val : result.entrySet()) {
      if (val.getKey() != keyField) {
        query.addBindVar(val.getKey(), val.getValue().toString());
      }
    }

    return query;
  }

  public Query createDeleteQuery(String keyspace, TabletType tabletType,
                                 String table, String keyField, String key) {
    StringBuilder sqlBuilder = new StringBuilder();

    sqlBuilder.append("delete from ");
    sqlBuilder.append(table);
    sqlBuilder.append(" where ");
    sqlBuilder.append(keyField);
    sqlBuilder.append(" = :");
    sqlBuilder.append(keyField);

    return new Query(sqlBuilder.toString(), keyspace, tabletType, key, keyField);
  }

}
