cmake_minimum_required(VERSION 4.1)
project(truth_table)

set(CMAKE_CXX_STANDARD 14)

add_executable(truth_table
        main.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
