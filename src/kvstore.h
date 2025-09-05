#pragma once
#include <rocksdb/db.h>
#include <rocksdb/options.h>
#include <optional>
#include <string>


class KVStore {
public:
	KVStore(const std::string& db_path);
	~KVStore();
	bool put(const std::string& key, const std::string& value);
	std::optional<std::string> get(const std::string& key);
	bool del(const std::string& key);

private:
	rocksdb::DB* db_;

};