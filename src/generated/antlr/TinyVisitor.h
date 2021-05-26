
// Generated from antlr/Tiny.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "TinyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TinyParser.
 */
class  TinyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TinyParser.
   */
    virtual antlrcpp::Any visitProg(TinyParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitDecls(TinyParser::DeclsContext *context) = 0;

    virtual antlrcpp::Any visitDecl(TinyParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitType(TinyParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitStmts(TinyParser::StmtsContext *context) = 0;

    virtual antlrcpp::Any visitStmt(TinyParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitIf_stmt(TinyParser::If_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRepeat_stmt(TinyParser::Repeat_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAssign_stmt(TinyParser::Assign_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRead_stmt(TinyParser::Read_stmtContext *context) = 0;

    virtual antlrcpp::Any visitWrite_stmt(TinyParser::Write_stmtContext *context) = 0;

    virtual antlrcpp::Any visitExp(TinyParser::ExpContext *context) = 0;

    virtual antlrcpp::Any visitSimple_exp(TinyParser::Simple_expContext *context) = 0;

    virtual antlrcpp::Any visitTerm(TinyParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitUnary(TinyParser::UnaryContext *context) = 0;

    virtual antlrcpp::Any visitFactor(TinyParser::FactorContext *context) = 0;


};

