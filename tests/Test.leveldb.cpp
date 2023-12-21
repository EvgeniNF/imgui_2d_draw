#include <gtest/gtest.h>
#include <leveldb/db.h>

TEST(leveldb, create_db)
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

    ASSERT_TRUE(status.ok());
    db->Put(leveldb::WriteOptions(), "KEY", "VALUE");

    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    
    ASSERT_TRUE(it->status().ok());
    delete it;
    delete db;
}