cmake_minimum_required(VERSION 3.3)
project(m1_monad)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(m1_monad ${SOURCE_FILES})