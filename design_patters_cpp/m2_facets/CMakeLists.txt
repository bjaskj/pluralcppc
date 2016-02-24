cmake_minimum_required(VERSION 3.3)
project(m2_facets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Person.cpp Person.h PersonBuilder.cpp PersonBuilder.h PersonAddressBuilder.h PersonJobBuilder.h)
add_executable(m2_facets ${SOURCE_FILES})