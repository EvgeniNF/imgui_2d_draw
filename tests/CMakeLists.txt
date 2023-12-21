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

if (MSVC)
    target_link_libraries(${TEST_NAME} 
        PUBLIC
        gtest
        leveldb
        RTTR::Core_Lib
    )
else()
    target_link_libraries(${TEST_NAME} 
        PUBLIC
        gtest
        leveldb
        RTTR::Core
    )
endif()

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
