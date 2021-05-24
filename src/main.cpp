#include <iostream>
#include "Compiler.h"

int main(int argc, char *argv[]) {
    Compiler tiny_compiler;

    rpg.addSource("../test1.tiny");

    int exit_code = rpg.compile();

    exit(exit_code);
}