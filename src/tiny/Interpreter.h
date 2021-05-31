#pragma once

#include <iostream>
#include <memory>
#include <cmath>
#include "antlr4-runtime.h"
#include "TinyLexer.h"
#include "TinyParser.h"
#include "TinyBaseVisitor.h"
#include "SymbolTable.h"
#include "Function.h"

class Interpreter;
class Interpreter {

public:
    Interpreter() {
        symbolTable = std::make_shared<SymbolTable>();
    }
    /* Start interpret */
    int interpret(void);
    /* Add source file */
    void addSource(const char* filename);
    /* Read source file */
    void readSource(const std::string  &filename,std::string &file_contents);

private:
    std::list<std::string> sources;             // 源文件列表
    std::shared_ptr<SymbolTable> symbolTable;   // 符号表

    friend class TinyDeclVisitor;
    friend class TinyCodeVisitor;
};
