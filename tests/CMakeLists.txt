set(TEST_NAME ${PROJECT_NAME}_test)

enable_testing()

file(GLOB TESTS ${LIB_PATH}
    LIB_PATH
    "*.hpp"
    "*.cpp")

add_executable(${TEST_NAME}
    Test.main.cpp
    ${TESTS}
)

target_link_libraries(${TEST_NAME} 
    PUBLIC
    gtest
)

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
