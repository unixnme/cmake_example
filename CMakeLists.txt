cmake_minimum_required(VERSION 2.8.12)
project(cmake_example)

find_package(Python REQUIRED)

add_subdirectory(pybind11)

add_library(cmake_example SHARED src/main.cpp)
target_include_directories(cmake_example
        PRIVATE ${PYBIND11_INCLUDE_DIR}  # from project CMakeLists.txt
        PRIVATE ${pybind11_INCLUDE_DIR}  # from pybind11Config
        PRIVATE ${PYTHON_INCLUDE_DIRS})

set_target_properties(cmake_example PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}")
set_target_properties(cmake_example PROPERTIES SUFFIX "${PYTHON_MODULE_EXTENSION}")
set_target_properties(cmake_example PROPERTIES CXX_VISIBILITY_PRESET "hidden")
target_link_libraries(cmake_example PRIVATE "-undefined dynamic_lookup")
target_compile_options(cmake_example PUBLIC ${PYBIND11_CPP_STANDARD})

#pybind11_add_module(cmake_example src/main.cpp)
