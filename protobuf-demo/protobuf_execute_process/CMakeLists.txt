cmake_minimum_required(VERSION 3.25)
project(protobuf_execute_process)

set(CMAKE_CXX_STANDARD 17)

add_executable(protobuf_execute_process main.cpp)


find_package(Protobuf 3 REQUIRED)


#设置输出路径
set(MESSAGE_DIR ${CMAKE_BINARY_DIR}/message)
if (EXISTS "${CMAKE_BINARY_DIR}/message" AND IS_DIRECTORY "${CMAKE_BINARY_DIR}/message")
    SET(DST_DIR ${MESSAGE_DIR})
else ()
    file(MAKE_DIRECTORY ${MESSAGE_DIR})
    SET(DST_DIR ${MESSAGE_DIR})
endif ()

#设置protoc的搜索路径
LIST(APPEND PROTO_FLAGS -I${CMAKE_SOURCE_DIR}/msg/message)

#获取需要编译的proto文件
file(GLOB_RECURSE MSG_PROTOS ${CMAKE_SOURCE_DIR}/msg/message/*.proto)
set(MESSAGE_SRC "")
set(MESSAGE_HDRS "")
foreach (msg ${MSG_PROTOS})
    get_filename_component(FIL_WE ${msg} NAME_WE)

    list(APPEND MESSAGE_SRC "${PROJECT_BINARY_DIR}/message/${FIL_WE}.pb.cc")
    list(APPEND MESSAGE_HDRS "${PROJECT_BINARY_DIR}/message/${FIL_WE}.pb.h")

    # 生成源码
    execute_process(
            COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} ${PROTO_FLAGS} --cpp_out=${DST_DIR} ${msg}
    )
endforeach ()
set_source_files_properties(${MESSAGE_SRC} ${MESSAGE_HDRS} PROPERTIES GENERATED TRUE)

