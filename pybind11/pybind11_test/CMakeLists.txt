cmake_minimum_required(VERSION 3.25)
project(pybind11_test)

set(CMAKE_CXX_STANDARD 17)
configure_file(test.py test.py)
find_package(pybind11 REQUIRED)
pybind11_add_module(example example.cpp)
add_custom_command(TARGET example POST_BUILD
        COMMAND python3 test.py && ${CMAKE_COMMAND} -E remove example.cpython-311-x86_64-linux-gnu.so
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )

