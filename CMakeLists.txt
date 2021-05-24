cmake_minimum_required(VERSION 3.5.1)
project(Tiny)

set(CMAKE_CXX_STANDARD 14)

set(LLVM_LINK_COMPONENTS
    Analysis
    Core
    Support
    )

# include_directories(include)
# include_directories(test/gtest)
include_directories(src)
include_directories(src/generated)
include_directories(antlr-cpp-runtime/include/antlr4-runtime)
# include_directories(/usr/include/llvm-11)

# link_directories(/usr/lib/llvm-11/lib)
add_definitions(-DANTLR4CPP_STATIC)

add_executable(Tiny 
    src/main.cpp
    src/generated/TinyLexer.cpp
    src/generated/TinyParser.cpp
)

target_link_libraries(rpg  antlr4-runtime.a -lLLVM-11 -lrt -ldl -ltinfo -lpthread -lz -lm)

