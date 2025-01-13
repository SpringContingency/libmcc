cmake_minimum_required(VERSION 3.27)
project(libmcc)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(libmcc ${CMAKE_SOURCE_DIR}/src/libmcc.cpp)
