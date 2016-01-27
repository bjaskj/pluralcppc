cmake_minimum_required(VERSION 3.3)
project(memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(memory ${SOURCE_FILES})