cmake_minimum_required(VERSION 3.25)
project(protobuf_generate_cpp)
set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_BINARY_DIR})
# 寻找Protobuf库和生成的文件
find_package(Protobuf REQUIRED)

# 设置Protobuf定义文件路径
set(PROTO_FILE foo.proto)

# 自动生成C++文件
# 有两个缺点
#要求protobuf_generate_cpp命令和生成add_executable() 或 add_library() 的命令必须在同一个CMakeList中.
#无法设置源码的生成路径,只能默认在相应的build中生成
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})

add_executable(protobuf_generate_cpp main.cpp ${PROTO_SRCS} ${PROTO_HDRS} )

# 链接Protobuf库
target_link_libraries(protobuf_generate_cpp protobuf::libprotobuf)
