cmake_minimum_required(VERSION 3.10)
project(NickSpace)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 定义 QuickJS 路径
set(QUICKJS_DIR "/usr/local/lib/quickjs")

# 包含头文件目录
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/utils
    ${QUICKJS_DIR}  # 添加 QuickJS 头文件路径
)

# 查找 src 目录下的所有 .cpp 文件
file(GLOB SOURCES
    "src/figurative/*.cpp"
    "src/instances/*.cpp"
    "src/main.cpp"
)

# 输出找到的源文件
message(STATUS "Found source files: ${SOURCES}")

# 手动指定 QuickJS（如果没有 FindQuickJS.cmake）
add_library(quickjs STATIC IMPORTED)
set_target_properties(quickjs PROPERTIES
    IMPORTED_LOCATION "${QUICKJS_DIR}/libquickjs.a"
    INTERFACE_INCLUDE_DIRECTORIES "${QUICKJS_DIR}"
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} quickjs)

# 定义项目根目录路径
add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}")
