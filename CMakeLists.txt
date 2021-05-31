# cmake最小版本要求
cmake_minimum_required(VERSION 3.5.1)

# 项目名称
project(Tiny)

# 执行Antlr脚本
# execute_process(COMMAND  sh antlr-generate.sh WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src/antlr)

# 设置C++编译标准
set(CMAKE_CXX_STANDARD 14)

# 添加include位置
include_directories(src)
include_directories(src/tiny)
include_directories(src/generated)
include_directories(antlr-cpp-runtime/include/antlr4-runtime)

# 添加链接库位置
link_directories(antlr-cpp-runtime/lib)
# add_definitions(-DANTLR4CPP_STATIC)

# 生成可执行文件
add_executable(Tiny 
    src/main.cpp
    src/generated/TinyLexer.cpp
    src/generated/TinyParser.cpp
    src/tiny/Interpreter.cpp
    src/tiny/Parser.cpp
    src/tiny/Function.cpp
)

# 添加链接库
target_link_libraries(Tiny antlr4-runtime.a)