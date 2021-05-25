#include <iostream>
#include "tiny/Compiler.h"

int main(int argc, char *argv[]) {
    Compiler tiny_compiler;

    tiny_compiler.addSource("../test1.tiny");

    int exit_code = tiny_compiler.compile();

    exit(exit_code);
}