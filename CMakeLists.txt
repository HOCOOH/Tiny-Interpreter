cmake_minimum_required(VERSION 3.5.1)

project(Tiny)

execute_process(COMMAND  sh antlr-generate.sh WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src/antlr)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/tiny)
include_directories(src/generated)
include_directories(antlr-cpp-runtime/include/antlr4-runtime)

link_directories(antlr-cpp-runtime/lib)
# add_definitions(-DANTLR4CPP_STATIC)

add_executable(Tiny 
    src/main.cpp
    src/generated/TinyLexer.cpp
    src/generated/TinyParser.cpp
    src/tiny/Compiler.cpp
    src/tiny/Parser.cpp
)

target_link_libraries(Tiny antlr4-runtime.a -lrt -ldl -ltinfo -lpthread -lz -lm)

