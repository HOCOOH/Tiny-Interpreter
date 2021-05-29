#pragma once

#include <iostream>
#include <memory>
#include <cmath>
#include "antlr4-runtime.h"
#include "TinyLexer.h"
#include "TinyParser.h"
#include "TinyBaseVisitor.h"
#include "SymbolTable.h"

class Interpreter {

public:
    Interpreter() {
        symbolTable = std::make_shared<SymbolTable>();
    }

    int interpret(void);
    void addSource(const char* filename);
    void readSource(const std::string  &filename,std::string &file_contents);

    std::string getFilename(const std::string filename) {
        size_t i = filename.rfind('/', filename.length());
        if (i != std::string::npos) {
            return filename.substr(i+1, filename.length() - i);
        }
        return filename;
    }

private:
    std::list<std::string> sources;             /* List of source filenames to interpret */
    std::shared_ptr<SymbolTable> symbolTable;   /* Symbol Table */
    //SymbolTable symbolTable; /*
/*
    friend class RpgDeclarationVisitor;
    friend class RpgCodeVisitor;
    friend class RpgVisitor;
*/
    friend class TinyCodeVisitor;
};



