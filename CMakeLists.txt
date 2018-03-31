cmake_minimum_required (VERSION 3.11)

project(LeetCode)

# put executable into directory bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# solutions write in .hpp
include_directories(src/)

# include and link googletest for all executables
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(${GTEST_LIBRARY_DIRS})
link_libraries(${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

# add make test
enable_testing()
# for gtest_discover_tests(<TARGET>)
include(GoogleTest)

# add executable for each test
file(GLOB TEST_CASE_DIRS "test/*")
foreach(TEST_CASE_DIR ${TEST_CASE_DIRS})
    # only visit directories
    if(IS_DIRECTORY ${TEST_CASE_DIR})
        # take the relative path to the test directory from <project root>/test,
        # e.g., TEST_CASE_DIR is ".../leetcode/test/two-sum",
        #       then TEST_CASE_PATH is set to "two-sum"
        file(RELATIVE_PATH TEST_CASE_PATH "${CMAKE_CURRENT_LIST_DIR}/test" ${TEST_CASE_DIR})
        string(REGEX REPLACE "[()]" "_" TEST_CASE_PATH_PARSED ${TEST_CASE_PATH})
        set(TEST_CASE_NAME "${TEST_CASE_PATH_PARSED}.test")
        # glob all source
        file(GLOB_RECURSE TEST_CASE_SRCS "${TEST_CASE_DIR}/*")
        add_executable(${TEST_CASE_NAME} ${TEST_CASE_SRCS})
        # add to make test
        gtest_discover_tests(${TEST_CASE_NAME})
    endif(IS_DIRECTORY ${TEST_CASE_DIR})
endforeach()
