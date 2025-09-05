#include "kvstore.h"
#include <iostream>

int main() {
	KVStore store("myrocksdb");

	store.put("name", "Alice");
	store.put("age", "30");

	auto name = store.get("name");
	if (name) std::cout << "Name: " << *name << std::endl;

	store.del("age");
	if (!store.get("age")) std::cout << "Age key deleted successfully" << std::endl;

	return 0;
}

