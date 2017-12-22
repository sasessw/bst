cmake_minimum_required(VERSION 3.6)
project(sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sources/Shell_sort.cpp)
add_executable(sort ${SOURCE_FILES})