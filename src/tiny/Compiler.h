#pragma once

#include "antlr4-runtime.h"
#include "TinyLexer.h"
#include "TinyParser.h"
#include "TinyBaseVisitor.h"
#include "SymbolTable.h"

class Compiler {

public:
    Compiler() {
        //this->emitDebugInfo = false;
        //this->ast = std::make_shared<AST>();
        //this->symbolTable = std::make_shared<SymbolTable>();
    }

    int compile(void);
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
    std::list<std::string> sources;             /* List of source filenames to compile */
    //std::shared_ptr<SymbolTable> symbolTable;   /* Symbol Table */
    std::shared_ptr<SymbolTable> symbolTable = std::make_shared<SymbolTable>();
    //SymbolTable symbolTable; /*
    // std::shared_ptr<AST> ast;                   /* Abstract Syntax Tree */
/*
    friend class RpgDeclarationVisitor;
    friend class RpgCodeVisitor;
    friend class RpgVisitor;
*/
    friend class TinyCodeVisitor;
};

class TinyException : public std::exception {

public:
    TinyException(const std::string &message) : message(message) { }

    const std::string &getMessage() const {
        return message;
    }

private:
    const std::string message;
};

