cmake_minimum_required(VERSION 3.3)
project(m2_builders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(m2_builders ${SOURCE_FILES})