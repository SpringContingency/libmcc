cmake_minimum_required(VERSION 3.10)
project(libmcc)

set(CMAKE_CXX_STANDARD 20)

add_library(libmcc STATIC ./src/libmcc.cpp)

target_include_directories(libmcc PUBLIC ./include)
