#include <iostream>
#include "Interpreter.h"

int main(int argc, char *argv[]) {
    Interpreter tiny_interpreter;

    // tiny_interpreter.addSource("../test1.tiny");
    tiny_interpreter.addSource("../test2.tiny");

    int exit_code = tiny_interpreter.interpret();

    exit(exit_code);
}