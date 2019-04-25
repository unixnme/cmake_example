cmake_minimum_required(VERSION 2.8.12)
project(cmake_example)

find_package(Python REQUIRED)

add_subdirectory(pybind11)
include_directories(pybind11/include)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(cmake_example src/main.cpp)
set_target_properties(cmake_example PROPERTIES CXX_VISIBILITY_PRESET "hidden")
set_property(TARGET cmake_example PROPERTY CXX_STANDARD 11)
target_link_libraries(cmake_example PRIVATE "-undefined dynamic_lookup")

#pybind11_add_module(cmake_example src/main.cpp)
