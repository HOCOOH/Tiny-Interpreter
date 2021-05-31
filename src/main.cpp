#include <iostream>
#include "Interpreter.h"

int main(int argc, char *argv[]) {
    // 检查参数
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <sourcecode filename>";
        exit(-1);
    }

    Interpreter tiny_interpreter;

    tiny_interpreter.addSource(argv[1]);
    // tiny_interpreter.addSource("../tinysrc/test1.tiny");

    tiny_interpreter.interpret();
    
    return 0;
}