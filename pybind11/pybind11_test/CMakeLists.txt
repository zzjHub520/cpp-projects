cmake_minimum_required(VERSION 3.25)
project(pybind11_test)

set(CMAKE_CXX_STANDARD 17)
configure_file(test.py test.py)
find_package(pybind11 REQUIRED)
find_program(PROTOBUF_EXE protoc)
if(PROTOBUF_EXE)
    message("======   ${PROTOBUF_EXE}")
endif()
pybind11_add_module(example example.cpp)
execute_process(COMMAND ${PROTOBUF_EXE} --cpp_out=. demo.proto
        COMMAND_ERROR_IS_FATAL ANY
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/proto
        )


add_custom_command(TARGET example POST_BUILD
        COMMAND python3 test.py && ${CMAKE_COMMAND} -E remove example.cpython-311-x86_64-linux-gnu.so
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )

