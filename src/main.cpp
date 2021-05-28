#include <iostream>
#include "Compiler.h"
#include <any>

void test() {
    int intVal = 7;
    antlrcpp::Any a = intVal;
    double retVal = double(a.as<int>());

}

int main(int argc, char *argv[]) {
    /*
    Compiler tiny_compiler;

    tiny_compiler.addSource("../test1.tiny");

    int exit_code = tiny_compiler.compile();

    exit(exit_code);
    */

   test();
   return 0;
}