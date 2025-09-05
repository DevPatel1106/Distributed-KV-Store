## **Distributed KV**

A lightweight, single-node Key-Value (KV) store in C++ with RocksDB backend.  
This project serves as the foundation for a distributed KV system with replication, sharding, and visualization planned in later phases.

---

## **Phase 1: Foundation**

- **Objective:** Implement a local, persistent KV store with a clean C++ interface.
- **Features:**
  - `put(key, value)` → Insert or update a key-value pair.
  - `get(key)` → Retrieve a value safely; returns `std::optional<std::string>`.
  - `del(key)` → Delete a key-value pair.
- **Persistence:** Uses RocksDB to store data on disk.

---

## **Project Structure**

distributedKV/

├─ src/                  # Source code (.cpp) and headers (.h)

  ├-- `src/kvstore.h` 

  ├--  `src/kvstore.cpp` → KVStore class wrapping RocksDB. 

  ├-- `src/main.cpp` → Demonstration of basic KV operations.

├─ build/                # CMake build directory (ignored in git)

├─ .gitignore

├─ CMakeLists.txt

└─ README.md

---

## **Getting Started**

### Prerequisites

- **C++20** compatible compiler (MSVC, GCC, Clang)  
- **CMake** (>=3.20 recommended)  
- **RocksDB** installed and linked  

### Build Instructions

1. Clone the repository:

```bash
git clone https://github.com/<your-username>/distributedKV.git
cd distributedKV
````

2. Create a build directory and configure:

```bash
mkdir build && cd build
cmake ..
```

3. Build the project:

```bash
cmake --build . --config Debug
```

4. Run the executable:

```bash
./kvstore.exe   # On Windows
```

---

## **Usage**

* The KV store allows adding, retrieving, and deleting key-value pairs.
* Returns optional results to safely handle missing keys.

---

## **Next Steps (Planned Phases)**

* **Phase 2:** Add Raft replication for fault-tolerance.
* **Phase 3:** Implement sharding for horizontal scalability.
* **Phase 4:** Dynamic shard rebalancing.
* **Phase 5:** CLI and web dashboard for cluster monitoring.

---

## **License**

MIT License – feel free to use and modify for learning or experimentation.

---

