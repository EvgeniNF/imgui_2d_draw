cmake_minimum_required(VERSION 3.15)

project(imgui_2d_draw)

option(BUILD_TESTS "Build app with unit tests" ON)


add_subdirectory(app)

if (${BUILD_TESTS})
    add_subdirectory(tests)
endif()
