cmake_minimum_required(VERSION 3.27)
project(MyProjectTests)

# Find the Google Test package
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Add your test cpp file
add_executable(runUnitTests myclass_test.cpp)

# Link against Google Test and your code's library
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread mylib)

# Tell CMake to run this executable as a test
add_test(NAME that-test-I-made COMMAND runUnitTests)

