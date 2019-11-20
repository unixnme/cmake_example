cmake_minimum_required(VERSION 2.8.12)
project(cmake_example)

set(CMAKE_CXX_FLAGS "-g -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(pybind11)
pybind11_add_module(cmake_example SHARED src/main.cpp)
