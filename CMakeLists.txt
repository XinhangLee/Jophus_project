cmake_minimum_required(VERSION 3.10)  # 更改为兼容版本
project(project_linklist C)

set(CMAKE_C_STANDARD 11)  # 使用 C11 标准

# 添加头文件目录
include_directories(${CMAKE_SOURCE_DIR}/LinkList)

# 添加源文件并创建可执行文件
add_executable(project_linklist Josephus.c
        ${CMAKE_SOURCE_DIR}/LinkList/LinkList.c)
