cmake_minimum_required(VERSION 3.15)

project(imgui_2d_draw)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build app with unit tests" ON)

option(LEVELDB_BUILD_TESTS "Build LevelDB's unit tests" OFF)
option(LEVELDB_BUILD_BENCHMARKS "Build LevelDB's benchmarks" OFF)
option(LEVELDB_INSTALL "Install LevelDB's header and library" OFF)

add_subdirectory(third_party/leveldb)

set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_DOCUMENTATION OFF CACHE BOOL "" FORCE)
set(BUILD_INSTALLER OFF CACHE BOOL "" FORCE)
set(BUILD_PACKAGE OFF CACHE BOOL "" FORCE)
set(USE_PCH OFF CACHE BOOL "" FORCE)
set(CUSTOM_DOXYGEN_STYLE OFF CACHE BOOL "" FORCE)
set(BUILD_WEBSITE_DOCU OFF CACHE BOOL "" FORCE)

if (MSVC)
    set(BUILD_WITH_STATIC_RUNTIME_LIBS ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(third_party/rttr)

add_subdirectory(src)

if (${BUILD_TESTS})
    add_subdirectory(third_party/googletest)
    add_subdirectory(tests)
endif()
