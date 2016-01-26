cmake_minimum_required(VERSION 3.3)
project(libtest_project)

add_library(libtest SHARED test.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

install(TARGETS libtest DESTINATION lib)
install(FILES test.h DESTINATION include)
