
// Generated from antlr/Tiny.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  TinyParser : public antlr4::Parser {
public:
  enum {
    PLUS = 1, MINUS = 2, EQUAL = 3, GT = 4, LT = 5, MULT = 6, DIV = 7, LPAR = 8, 
    RPAR = 9, ASSIGN = 10, SEMI = 11, IF = 12, THEN = 13, ELSE = 14, END = 15, 
    REPEAT = 16, UNTIL = 17, READ = 18, WRITE = 19, CHAR = 20, INT = 21, 
    WS = 22, NUM = 23, ID = 24
  };

  enum {
    RuleProg = 0, RuleDecls = 1, RuleDecl = 2, RuleType = 3, RuleStmts = 4, 
    RuleStmt = 5, RuleIf_stmt = 6, RuleRepeat_stmt = 7, RuleAssign_stmt = 8, 
    RuleRead_stmt = 9, RuleWrite_stmt = 10, RuleExp = 11, RuleCmpop = 12, 
    RuleSimple_exp = 13, RuleAddop = 14, RuleTerm = 15, RuleMulop = 16, 
    RuleFactor = 17, RuleUnary = 18
  };

  explicit TinyParser(antlr4::TokenStream *input);
  ~TinyParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class DeclsContext;
  class DeclContext;
  class TypeContext;
  class StmtsContext;
  class StmtContext;
  class If_stmtContext;
  class Repeat_stmtContext;
  class Assign_stmtContext;
  class Read_stmtContext;
  class Write_stmtContext;
  class ExpContext;
  class CmpopContext;
  class Simple_expContext;
  class AddopContext;
  class TermContext;
  class MulopContext;
  class FactorContext;
  class UnaryContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclsContext *decls();
    antlr4::tree::TerminalNode *SEMI();
    StmtsContext *stmts();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  DeclsContext : public antlr4::ParserRuleContext {
  public:
    DeclsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    DeclsContext *decls();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclsContext* decls();
  DeclsContext* decls(int precedence);
  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMI();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclContext* decl();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *CHAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  StmtsContext : public antlr4::ParserRuleContext {
  public:
    StmtsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StmtContext *stmt();
    StmtsContext *stmts();
    antlr4::tree::TerminalNode *SEMI();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtsContext* stmts();
  StmtsContext* stmts(int precedence);
  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_stmtContext *if_stmt();
    Repeat_stmtContext *repeat_stmt();
    Assign_stmtContext *assign_stmt();
    Read_stmtContext *read_stmt();
    Write_stmtContext *write_stmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAR();
    ExpContext *exp();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *THEN();
    std::vector<StmtsContext *> stmts();
    StmtsContext* stmts(size_t i);
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *ELSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_stmtContext* if_stmt();

  class  Repeat_stmtContext : public antlr4::ParserRuleContext {
  public:
    Repeat_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REPEAT();
    StmtsContext *stmts();
    antlr4::tree::TerminalNode *UNTIL();
    ExpContext *exp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Repeat_stmtContext* repeat_stmt();

  class  Assign_stmtContext : public antlr4::ParserRuleContext {
  public:
    Assign_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpContext *exp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_stmtContext* assign_stmt();

  class  Read_stmtContext : public antlr4::ParserRuleContext {
  public:
    Read_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Read_stmtContext* read_stmt();

  class  Write_stmtContext : public antlr4::ParserRuleContext {
  public:
    Write_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITE();
    ExpContext *exp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Write_stmtContext* write_stmt();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expContext *> simple_exp();
    Simple_expContext* simple_exp(size_t i);
    CmpopContext *cmpop();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpContext* exp();

  class  CmpopContext : public antlr4::ParserRuleContext {
  public:
    CmpopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *LT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CmpopContext* cmpop();

  class  Simple_expContext : public antlr4::ParserRuleContext {
  public:
    Simple_expContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    Simple_expContext *simple_exp();
    AddopContext *addop();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_expContext* simple_exp();
  Simple_expContext* simple_exp(int precedence);
  class  AddopContext : public antlr4::ParserRuleContext {
  public:
    AddopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddopContext* addop();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    TermContext *term();
    MulopContext *mulop();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  MulopContext : public antlr4::ParserRuleContext {
  public:
    MulopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulopContext* mulop();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    ExpContext *exp();
    antlr4::tree::TerminalNode *RPAR();
    UnaryContext *unary();
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  UnaryContext : public antlr4::ParserRuleContext {
  public:
    UnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *NUM();
    antlr4::tree::TerminalNode *MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryContext* unary();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool declsSempred(DeclsContext *_localctx, size_t predicateIndex);
  bool stmtsSempred(StmtsContext *_localctx, size_t predicateIndex);
  bool simple_expSempred(Simple_expContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

