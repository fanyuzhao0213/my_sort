#cmake ..\  -G "MinGW Makefiles"
# windows下使用这个编译   需要添加后面的参数
# CMAKE_CURRENT_SOURCE_DIR   定义：CMake 内置变量，指向 当前 CMakeLists.txt 所在的目录。
# PROJECT_SOURCE_DIR定义：CMake 内置变量，在 整个项目范围内指向 project() 命令所在的目录。
cmake_minimum_required(VERSION 3.0)
project(sort)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/inc)
# 搜索 src 目录下的源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
add_executable(app  ${SRC_LIST})

