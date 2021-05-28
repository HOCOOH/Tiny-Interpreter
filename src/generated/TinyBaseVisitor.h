
// Generated from Tiny.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "TinyVisitor.h"


/**
 * This class provides an empty implementation of TinyVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TinyBaseVisitor : public TinyVisitor {
public:

  virtual antlrcpp::Any visitProg(TinyParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecls(TinyParser::DeclsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl(TinyParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(TinyParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmts(TinyParser::StmtsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(TinyParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_stmt(TinyParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeat_stmt(TinyParser::Repeat_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign_stmt(TinyParser::Assign_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRead_stmt(TinyParser::Read_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWrite_stmt(TinyParser::Write_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExp(TinyParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_exp(TinyParser::Simple_expContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(TinyParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary(TinyParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(TinyParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }


};

