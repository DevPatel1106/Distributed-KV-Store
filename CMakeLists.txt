# CMakeList.txt : CMake project for distributedKV, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set the path to the vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "D:/Projects/distributedKV/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project ("distributedKV")
#set(CMAKE_PREFIX_PATH "D:/Projects/distributedKV/vcpkg/installed/x64-windows")
find_package(RocksDB CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(prometheus-cpp CONFIG REQUIRED)

# Add source to this project's executable.
#add_executable (distributedKV "distributedKV.cpp" "distributedKV.h")

add_executable(kvstore src/main.cpp "src/kvstore.h" "src/kvstore.cpp")

target_link_libraries(kvstore
    PRIVATE
        RocksDB::rocksdb
        gRPC::grpc++
        protobuf::libprotoc
        spdlog::spdlog
        prometheus-cpp::core
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET kvstore PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
