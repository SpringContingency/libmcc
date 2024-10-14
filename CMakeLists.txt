cmake_minimum_required(VERSION 3.27)
project(libmcc)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE LIBMCC_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(libmcc ${LIBMCC_SRC})
