#include <iostream>
#include "TinyBaseVisitor.h"
#include "Interpreter.h"


class TinyCodeVisitor : public TinyBaseVisitor {

public:
    TinyCodeVisitor(const std::string filename, const Interpreter* interpreter) : \
        filename(filename), interpreter(interpreter), returnFlag(false) {}

    antlrcpp::Any visitFunc_body(TinyParser::Func_bodyContext *ctx);
    antlrcpp::Any visitDecl(TinyParser::DeclContext *ctx);
    antlrcpp::Any visitStmts(TinyParser::StmtsContext *ctx);
    antlrcpp::Any visitRead_stmt(TinyParser::Read_stmtContext *ctx);
    antlrcpp::Any visitWrite_stmt(TinyParser::Write_stmtContext *ctx);
    antlrcpp::Any visitAssign_stmt(TinyParser::Assign_stmtContext *ctx);
    antlrcpp::Any visitIf_stmt(TinyParser::If_stmtContext *ctx);
    antlrcpp::Any visitRepeat_stmt(TinyParser::Repeat_stmtContext *ctx);
    antlrcpp::Any visitCall_stmt(TinyParser::Call_stmtContext *ctx);
    antlrcpp::Any visitReturn_stmt(TinyParser::Return_stmtContext *ctx);
    antlrcpp::Any visitFunc_call(TinyParser::Func_callContext *ctx, bool isReturn);
    antlrcpp::Any visitArgs(TinyParser::ArgsContext *ctx, std::vector<std::shared_ptr<Value>>& args);
    antlrcpp::Any visitArg(TinyParser::ArgContext *ctx);
    antlrcpp::Any visitExp(TinyParser::ExpContext *ctx);
    antlrcpp::Any visitSimple_exp(TinyParser::Simple_expContext *ctx);
    antlrcpp::Any visitTerm(TinyParser::TermContext *ctx);
    antlrcpp::Any visitUnary(TinyParser::UnaryContext *ctx);
    antlrcpp::Any visitFactor(TinyParser::FactorContext *ctx);

private:
    const std::string filename;
    const Interpreter* interpreter;
    bool returnFlag;
    
};