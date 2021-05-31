#pragma once

#include "Interpreter.h"

class Interpreter;
/*
遍历函数定义
*/
class TinyDeclVisitor : public TinyBaseVisitor {

public:
    TinyDeclVisitor(const std::string filename, const Interpreter* interpreter) : filename(filename), interpreter(interpreter) {}

    antlrcpp::Any visitFunction(TinyParser::FunctionContext *ctx);
    antlrcpp::Any visitParams(TinyParser::ParamsContext *ctx, std::string name);

private:
    const std::string filename;         // Visitor所解释的源文件名
    const Interpreter* interpreter;     // Visitor所属的解释器
    
};