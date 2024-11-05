# 04/11/2024 - Created by ChatGPT

# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(HashTableProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_library(HashTable HashTable.cpp)

# Add GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add executable for the main application
add_executable(Milestone3 Milestone3.cpp)
# Link the main executable with the HashTable library
target_link_libraries(Milestone3 HashTable)

# Add executable for running tests
add_executable(HashTableTest HashTableTest.cpp)
# Link the test executable with HashTable and GoogleTest libraries
target_link_libraries(HashTableTest HashTable ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()

# Add a test to be run by CTest
add_test(NAME HashTableTests COMMAND HashTableTest)