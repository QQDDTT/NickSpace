cmake_minimum_required(VERSION 3.10)
project(NickSpace)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# 包含头文件目录
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/utils
)

# 查找 src 目录下的所有 .cpp 文件
file(GLOB SOURCES
    "src/figurative/*.cpp"
    "src/instances/*.cpp"
    "src/main.cpp"
)

# 输出找到的源文件
message(STATUS "Found source files: ${SOURCES}")


# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 定义项目根目录路径
add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}")
