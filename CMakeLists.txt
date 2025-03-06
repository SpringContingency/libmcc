cmake_minimum_required(VERSION 3.0)
project(libmcc)

set(CMAKE_CXX_STANDARD 20)

add_library(libmcc STATIC ./src/libmcc.cpp "include/libmcc/module/halo3/memory/data.h")

target_include_directories(libmcc PUBLIC ./include)
