#include "kvstore.h"
#include <iostream>

KVStore::KVStore(const std::string& db_path) {
	rocksdb::Options options;
	options.create_if_missing = true;

	rocksdb::Status status = rocksdb::DB::Open(options, db_path, &db_);

	if (!status.ok()) {
		std::cerr << "Failed to open RocksDB: " << status.ToString() << std::endl;
		throw std::runtime_error("RocksDB open failed");
	}
}

KVStore::~KVStore() { delete db_; }

bool KVStore::put(const std::string& key, const std::string& value) {
	rocksdb::Status status = db_->Put(rocksdb::WriteOptions(), key, value);
	return status.ok();
}

std::optional<std::string> KVStore::get(const std::string& key) {
	std::string value;
	rocksdb::Status status = db_->Get(rocksdb::ReadOptions(), key, &value);

	if (status.IsNotFound()) return std::nullopt;

	if (!status.ok()) {
		std::cerr << "RocksDB get error: " << status.ToString() << std::endl;
		return std::nullopt;
	}

	return value;
}

bool KVStore::del(const std::string& key) {
	rocksdb::Status status = db_->Delete(rocksdb::WriteOptions(), key);
	return status.ok();
}