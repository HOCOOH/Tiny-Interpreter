#pragma once

#include "Interpreter.h"

class Interpreter;

class TinyDeclVisitor : public TinyBaseVisitor {

public:
    TinyDeclVisitor(const std::string filename, const Interpreter* interpreter) : filename(filename), interpreter(interpreter) {}

    antlrcpp::Any visitFunction(TinyParser::FunctionContext *ctx);
    antlrcpp::Any visitParams(TinyParser::ParamsContext *ctx, std::string name);



private:
    const std::string filename;
    const Interpreter* interpreter;
    
};