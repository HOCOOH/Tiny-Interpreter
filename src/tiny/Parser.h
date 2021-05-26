#include <iostream>
#include "TinyBaseVisitor.h"
#include "Compiler.h"


class TinyCodeVisitor : public TinyBaseVisitor {

public:
    TinyCodeVisitor(const Compiler* compiler) : compiler(compiler) {}

    antlrcpp::Any visitDecl(TinyParser::DeclContext *ctx);
    antlrcpp::Any visitRead_stmt(TinyParser::Read_stmtContext *ctx);
    antlrcpp::Any visitWrite_stmt(TinyParser::Write_stmtContext *ctx);
    antlrcpp::Any visitAssign_stmt(TinyParser::Assign_stmtContext *ctx);
    antlrcpp::Any visitIf_stmt(TinyParser::If_stmtContext *ctx);
    antlrcpp::Any visitRepeat_stmt(TinyParser::Repeat_stmtContext *ctx);
    antlrcpp::Any visitExp(TinyParser::ExpContext *ctx);
    antlrcpp::Any visitSimple_exp(TinyParser::Simple_expContext *ctx);
    antlrcpp::Any visitTerm(TinyParser::TermContext *ctx);
    antlrcpp::Any visitUnary(TinyParser::UnaryContext *ctx);
    antlrcpp::Any visitFactor(TinyParser::FactorContext *ctx);

private:
    const Compiler* compiler;
    
};