cmake_minimum_required(VERSION 3.15)

project(imgui_2d_draw)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build app with unit tests" ON)

option(LEVELDB_BUILD_TESTS "Build LevelDB's unit tests" OFF)
option(LEVELDB_BUILD_BENCHMARKS "Build LevelDB's benchmarks" OFF)
option(LEVELDB_INSTALL "Install LevelDB's header and library" OFF)

add_subdirectory(third_party/leveldb)

add_subdirectory(src)

if (${BUILD_TESTS})
    add_subdirectory(third_party/googletest)
    add_subdirectory(tests)
endif()
