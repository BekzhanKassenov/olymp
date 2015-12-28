cmake_minimum_required(VERSION 3.3)
project(BigInt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BigInt.h)
add_executable(BigInt ${SOURCE_FILES})