cmake_minimum_required(VERSION 3.3)
project(oop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Person.cpp Person.h Address.h Employee.cpp Employee.h EmpFactory.h)
add_executable(oop ${SOURCE_FILES})