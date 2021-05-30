
// Generated from Tiny.g4 by ANTLR 4.9.2


#include "TinyVisitor.h"

#include "TinyParser.h"


using namespace antlrcpp;
using namespace antlr4;

TinyParser::TinyParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TinyParser::~TinyParser() {
  delete _interpreter;
}

std::string TinyParser::getGrammarFileName() const {
  return "Tiny.g4";
}

const std::vector<std::string>& TinyParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TinyParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

TinyParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::FunctionsContext* TinyParser::ProgContext::functions() {
  return getRuleContext<TinyParser::FunctionsContext>(0);
}


size_t TinyParser::ProgContext::getRuleIndex() const {
  return TinyParser::RuleProg;
}


antlrcpp::Any TinyParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::ProgContext* TinyParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, TinyParser::RuleProg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    functions();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionsContext ------------------------------------------------------------------

TinyParser::FunctionsContext::FunctionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TinyParser::FunctionContext *> TinyParser::FunctionsContext::function() {
  return getRuleContexts<TinyParser::FunctionContext>();
}

TinyParser::FunctionContext* TinyParser::FunctionsContext::function(size_t i) {
  return getRuleContext<TinyParser::FunctionContext>(i);
}


size_t TinyParser::FunctionsContext::getRuleIndex() const {
  return TinyParser::RuleFunctions;
}


antlrcpp::Any TinyParser::FunctionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitFunctions(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::FunctionsContext* TinyParser::functions() {
  FunctionsContext *_localctx = _tracker.createInstance<FunctionsContext>(_ctx, getState());
  enterRule(_localctx, 2, TinyParser::RuleFunctions);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(54);
      function();
      setState(57); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TinyParser::CHAR)
      | (1ULL << TinyParser::INT)
      | (1ULL << TinyParser::FLOAT)
      | (1ULL << TinyParser::BOOL)
      | (1ULL << TinyParser::VOID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

TinyParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::TypeContext* TinyParser::FunctionContext::type() {
  return getRuleContext<TinyParser::TypeContext>(0);
}

tree::TerminalNode* TinyParser::FunctionContext::ID() {
  return getToken(TinyParser::ID, 0);
}

tree::TerminalNode* TinyParser::FunctionContext::LPAR() {
  return getToken(TinyParser::LPAR, 0);
}

TinyParser::ParamsContext* TinyParser::FunctionContext::params() {
  return getRuleContext<TinyParser::ParamsContext>(0);
}

tree::TerminalNode* TinyParser::FunctionContext::RPAR() {
  return getToken(TinyParser::RPAR, 0);
}

tree::TerminalNode* TinyParser::FunctionContext::LBRA() {
  return getToken(TinyParser::LBRA, 0);
}

TinyParser::Func_bodyContext* TinyParser::FunctionContext::func_body() {
  return getRuleContext<TinyParser::Func_bodyContext>(0);
}

tree::TerminalNode* TinyParser::FunctionContext::RBRA() {
  return getToken(TinyParser::RBRA, 0);
}


size_t TinyParser::FunctionContext::getRuleIndex() const {
  return TinyParser::RuleFunction;
}


antlrcpp::Any TinyParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::FunctionContext* TinyParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, TinyParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    type();
    setState(60);
    match(TinyParser::ID);
    setState(61);
    match(TinyParser::LPAR);
    setState(62);
    params();
    setState(63);
    match(TinyParser::RPAR);
    setState(64);
    match(TinyParser::LBRA);
    setState(65);
    func_body();
    setState(66);
    match(TinyParser::RBRA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

TinyParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TinyParser::ParamContext *> TinyParser::ParamsContext::param() {
  return getRuleContexts<TinyParser::ParamContext>();
}

TinyParser::ParamContext* TinyParser::ParamsContext::param(size_t i) {
  return getRuleContext<TinyParser::ParamContext>(i);
}


size_t TinyParser::ParamsContext::getRuleIndex() const {
  return TinyParser::RuleParams;
}


antlrcpp::Any TinyParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::ParamsContext* TinyParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 6, TinyParser::RuleParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TinyParser::CHAR)
      | (1ULL << TinyParser::INT)
      | (1ULL << TinyParser::FLOAT)
      | (1ULL << TinyParser::BOOL)
      | (1ULL << TinyParser::VOID))) != 0)) {
      setState(68);
      param();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

TinyParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::TypeContext* TinyParser::ParamContext::type() {
  return getRuleContext<TinyParser::TypeContext>(0);
}

tree::TerminalNode* TinyParser::ParamContext::ID() {
  return getToken(TinyParser::ID, 0);
}

tree::TerminalNode* TinyParser::ParamContext::COMMA() {
  return getToken(TinyParser::COMMA, 0);
}


size_t TinyParser::ParamContext::getRuleIndex() const {
  return TinyParser::RuleParam;
}


antlrcpp::Any TinyParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::ParamContext* TinyParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 8, TinyParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    type();
    setState(75);
    match(TinyParser::ID);
    setState(76);
    match(TinyParser::COMMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_bodyContext ------------------------------------------------------------------

TinyParser::Func_bodyContext::Func_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::DeclsContext* TinyParser::Func_bodyContext::decls() {
  return getRuleContext<TinyParser::DeclsContext>(0);
}

TinyParser::StmtsContext* TinyParser::Func_bodyContext::stmts() {
  return getRuleContext<TinyParser::StmtsContext>(0);
}


size_t TinyParser::Func_bodyContext::getRuleIndex() const {
  return TinyParser::RuleFunc_body;
}


antlrcpp::Any TinyParser::Func_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitFunc_body(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Func_bodyContext* TinyParser::func_body() {
  Func_bodyContext *_localctx = _tracker.createInstance<Func_bodyContext>(_ctx, getState());
  enterRule(_localctx, 10, TinyParser::RuleFunc_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    decls();
    setState(79);
    stmts();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclsContext ------------------------------------------------------------------

TinyParser::DeclsContext::DeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TinyParser::DeclContext *> TinyParser::DeclsContext::decl() {
  return getRuleContexts<TinyParser::DeclContext>();
}

TinyParser::DeclContext* TinyParser::DeclsContext::decl(size_t i) {
  return getRuleContext<TinyParser::DeclContext>(i);
}


size_t TinyParser::DeclsContext::getRuleIndex() const {
  return TinyParser::RuleDecls;
}


antlrcpp::Any TinyParser::DeclsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitDecls(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::DeclsContext* TinyParser::decls() {
  DeclsContext *_localctx = _tracker.createInstance<DeclsContext>(_ctx, getState());
  enterRule(_localctx, 12, TinyParser::RuleDecls);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TinyParser::CHAR)
      | (1ULL << TinyParser::INT)
      | (1ULL << TinyParser::FLOAT)
      | (1ULL << TinyParser::BOOL)
      | (1ULL << TinyParser::VOID))) != 0)) {
      setState(81);
      decl();
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

TinyParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::TypeContext* TinyParser::DeclContext::type() {
  return getRuleContext<TinyParser::TypeContext>(0);
}

tree::TerminalNode* TinyParser::DeclContext::ID() {
  return getToken(TinyParser::ID, 0);
}

tree::TerminalNode* TinyParser::DeclContext::SEMI() {
  return getToken(TinyParser::SEMI, 0);
}

tree::TerminalNode* TinyParser::DeclContext::ASSIGN() {
  return getToken(TinyParser::ASSIGN, 0);
}

TinyParser::ExpContext* TinyParser::DeclContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}


size_t TinyParser::DeclContext::getRuleIndex() const {
  return TinyParser::RuleDecl;
}


antlrcpp::Any TinyParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::DeclContext* TinyParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 14, TinyParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(87);
      type();
      setState(88);
      match(TinyParser::ID);
      setState(89);
      match(TinyParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(91);
      type();
      setState(92);
      match(TinyParser::ID);
      setState(93);
      match(TinyParser::ASSIGN);
      setState(94);
      exp();
      setState(95);
      match(TinyParser::SEMI);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

TinyParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::TypeContext::INT() {
  return getToken(TinyParser::INT, 0);
}

tree::TerminalNode* TinyParser::TypeContext::CHAR() {
  return getToken(TinyParser::CHAR, 0);
}

tree::TerminalNode* TinyParser::TypeContext::FLOAT() {
  return getToken(TinyParser::FLOAT, 0);
}

tree::TerminalNode* TinyParser::TypeContext::BOOL() {
  return getToken(TinyParser::BOOL, 0);
}

tree::TerminalNode* TinyParser::TypeContext::VOID() {
  return getToken(TinyParser::VOID, 0);
}


size_t TinyParser::TypeContext::getRuleIndex() const {
  return TinyParser::RuleType;
}


antlrcpp::Any TinyParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::TypeContext* TinyParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 16, TinyParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TinyParser::CHAR)
      | (1ULL << TinyParser::INT)
      | (1ULL << TinyParser::FLOAT)
      | (1ULL << TinyParser::BOOL)
      | (1ULL << TinyParser::VOID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtsContext ------------------------------------------------------------------

TinyParser::StmtsContext::StmtsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TinyParser::StmtContext *> TinyParser::StmtsContext::stmt() {
  return getRuleContexts<TinyParser::StmtContext>();
}

TinyParser::StmtContext* TinyParser::StmtsContext::stmt(size_t i) {
  return getRuleContext<TinyParser::StmtContext>(i);
}


size_t TinyParser::StmtsContext::getRuleIndex() const {
  return TinyParser::RuleStmts;
}


antlrcpp::Any TinyParser::StmtsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitStmts(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::StmtsContext* TinyParser::stmts() {
  StmtsContext *_localctx = _tracker.createInstance<StmtsContext>(_ctx, getState());
  enterRule(_localctx, 18, TinyParser::RuleStmts);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TinyParser::IF)
      | (1ULL << TinyParser::REPEAT)
      | (1ULL << TinyParser::READ)
      | (1ULL << TinyParser::WRITE)
      | (1ULL << TinyParser::RETURN)
      | (1ULL << TinyParser::ID))) != 0)) {
      setState(101);
      stmt();
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

TinyParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::If_stmtContext* TinyParser::StmtContext::if_stmt() {
  return getRuleContext<TinyParser::If_stmtContext>(0);
}

TinyParser::Repeat_stmtContext* TinyParser::StmtContext::repeat_stmt() {
  return getRuleContext<TinyParser::Repeat_stmtContext>(0);
}

TinyParser::Assign_stmtContext* TinyParser::StmtContext::assign_stmt() {
  return getRuleContext<TinyParser::Assign_stmtContext>(0);
}

TinyParser::Read_stmtContext* TinyParser::StmtContext::read_stmt() {
  return getRuleContext<TinyParser::Read_stmtContext>(0);
}

TinyParser::Write_stmtContext* TinyParser::StmtContext::write_stmt() {
  return getRuleContext<TinyParser::Write_stmtContext>(0);
}

TinyParser::Call_stmtContext* TinyParser::StmtContext::call_stmt() {
  return getRuleContext<TinyParser::Call_stmtContext>(0);
}

TinyParser::Return_stmtContext* TinyParser::StmtContext::return_stmt() {
  return getRuleContext<TinyParser::Return_stmtContext>(0);
}


size_t TinyParser::StmtContext::getRuleIndex() const {
  return TinyParser::RuleStmt;
}


antlrcpp::Any TinyParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::StmtContext* TinyParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 20, TinyParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      if_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(108);
      repeat_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(109);
      assign_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(110);
      read_stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(111);
      write_stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(112);
      call_stmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(113);
      return_stmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

TinyParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::If_stmtContext::IF() {
  return getToken(TinyParser::IF, 0);
}

tree::TerminalNode* TinyParser::If_stmtContext::LPAR() {
  return getToken(TinyParser::LPAR, 0);
}

TinyParser::ExpContext* TinyParser::If_stmtContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}

tree::TerminalNode* TinyParser::If_stmtContext::RPAR() {
  return getToken(TinyParser::RPAR, 0);
}

tree::TerminalNode* TinyParser::If_stmtContext::THEN() {
  return getToken(TinyParser::THEN, 0);
}

std::vector<TinyParser::StmtsContext *> TinyParser::If_stmtContext::stmts() {
  return getRuleContexts<TinyParser::StmtsContext>();
}

TinyParser::StmtsContext* TinyParser::If_stmtContext::stmts(size_t i) {
  return getRuleContext<TinyParser::StmtsContext>(i);
}

tree::TerminalNode* TinyParser::If_stmtContext::END() {
  return getToken(TinyParser::END, 0);
}

tree::TerminalNode* TinyParser::If_stmtContext::ELSE() {
  return getToken(TinyParser::ELSE, 0);
}


size_t TinyParser::If_stmtContext::getRuleIndex() const {
  return TinyParser::RuleIf_stmt;
}


antlrcpp::Any TinyParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitIf_stmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::If_stmtContext* TinyParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 22, TinyParser::RuleIf_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(134);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(116);
      match(TinyParser::IF);
      setState(117);
      match(TinyParser::LPAR);
      setState(118);
      exp();
      setState(119);
      match(TinyParser::RPAR);
      setState(120);
      match(TinyParser::THEN);
      setState(121);
      stmts();
      setState(122);
      match(TinyParser::END);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(124);
      match(TinyParser::IF);
      setState(125);
      match(TinyParser::LPAR);
      setState(126);
      exp();
      setState(127);
      match(TinyParser::RPAR);
      setState(128);
      match(TinyParser::THEN);
      setState(129);
      stmts();
      setState(130);
      match(TinyParser::ELSE);
      setState(131);
      stmts();
      setState(132);
      match(TinyParser::END);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Repeat_stmtContext ------------------------------------------------------------------

TinyParser::Repeat_stmtContext::Repeat_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::Repeat_stmtContext::REPEAT() {
  return getToken(TinyParser::REPEAT, 0);
}

TinyParser::StmtsContext* TinyParser::Repeat_stmtContext::stmts() {
  return getRuleContext<TinyParser::StmtsContext>(0);
}

tree::TerminalNode* TinyParser::Repeat_stmtContext::UNTIL() {
  return getToken(TinyParser::UNTIL, 0);
}

TinyParser::ExpContext* TinyParser::Repeat_stmtContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}

tree::TerminalNode* TinyParser::Repeat_stmtContext::SEMI() {
  return getToken(TinyParser::SEMI, 0);
}


size_t TinyParser::Repeat_stmtContext::getRuleIndex() const {
  return TinyParser::RuleRepeat_stmt;
}


antlrcpp::Any TinyParser::Repeat_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitRepeat_stmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Repeat_stmtContext* TinyParser::repeat_stmt() {
  Repeat_stmtContext *_localctx = _tracker.createInstance<Repeat_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, TinyParser::RuleRepeat_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(TinyParser::REPEAT);
    setState(137);
    stmts();
    setState(138);
    match(TinyParser::UNTIL);
    setState(139);
    exp();
    setState(140);
    match(TinyParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_stmtContext ------------------------------------------------------------------

TinyParser::Assign_stmtContext::Assign_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::Assign_stmtContext::ID() {
  return getToken(TinyParser::ID, 0);
}

tree::TerminalNode* TinyParser::Assign_stmtContext::ASSIGN() {
  return getToken(TinyParser::ASSIGN, 0);
}

TinyParser::ExpContext* TinyParser::Assign_stmtContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}

tree::TerminalNode* TinyParser::Assign_stmtContext::SEMI() {
  return getToken(TinyParser::SEMI, 0);
}


size_t TinyParser::Assign_stmtContext::getRuleIndex() const {
  return TinyParser::RuleAssign_stmt;
}


antlrcpp::Any TinyParser::Assign_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitAssign_stmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Assign_stmtContext* TinyParser::assign_stmt() {
  Assign_stmtContext *_localctx = _tracker.createInstance<Assign_stmtContext>(_ctx, getState());
  enterRule(_localctx, 26, TinyParser::RuleAssign_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(TinyParser::ID);
    setState(143);
    match(TinyParser::ASSIGN);
    setState(144);
    exp();
    setState(145);
    match(TinyParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Read_stmtContext ------------------------------------------------------------------

TinyParser::Read_stmtContext::Read_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::Read_stmtContext::READ() {
  return getToken(TinyParser::READ, 0);
}

tree::TerminalNode* TinyParser::Read_stmtContext::ID() {
  return getToken(TinyParser::ID, 0);
}

tree::TerminalNode* TinyParser::Read_stmtContext::SEMI() {
  return getToken(TinyParser::SEMI, 0);
}


size_t TinyParser::Read_stmtContext::getRuleIndex() const {
  return TinyParser::RuleRead_stmt;
}


antlrcpp::Any TinyParser::Read_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitRead_stmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Read_stmtContext* TinyParser::read_stmt() {
  Read_stmtContext *_localctx = _tracker.createInstance<Read_stmtContext>(_ctx, getState());
  enterRule(_localctx, 28, TinyParser::RuleRead_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(TinyParser::READ);
    setState(148);
    match(TinyParser::ID);
    setState(149);
    match(TinyParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Write_stmtContext ------------------------------------------------------------------

TinyParser::Write_stmtContext::Write_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::Write_stmtContext::WRITE() {
  return getToken(TinyParser::WRITE, 0);
}

TinyParser::ExpContext* TinyParser::Write_stmtContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}

tree::TerminalNode* TinyParser::Write_stmtContext::SEMI() {
  return getToken(TinyParser::SEMI, 0);
}


size_t TinyParser::Write_stmtContext::getRuleIndex() const {
  return TinyParser::RuleWrite_stmt;
}


antlrcpp::Any TinyParser::Write_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitWrite_stmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Write_stmtContext* TinyParser::write_stmt() {
  Write_stmtContext *_localctx = _tracker.createInstance<Write_stmtContext>(_ctx, getState());
  enterRule(_localctx, 30, TinyParser::RuleWrite_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(TinyParser::WRITE);
    setState(152);
    exp();
    setState(153);
    match(TinyParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_stmtContext ------------------------------------------------------------------

TinyParser::Call_stmtContext::Call_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::Func_callContext* TinyParser::Call_stmtContext::func_call() {
  return getRuleContext<TinyParser::Func_callContext>(0);
}

tree::TerminalNode* TinyParser::Call_stmtContext::SEMI() {
  return getToken(TinyParser::SEMI, 0);
}


size_t TinyParser::Call_stmtContext::getRuleIndex() const {
  return TinyParser::RuleCall_stmt;
}


antlrcpp::Any TinyParser::Call_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitCall_stmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Call_stmtContext* TinyParser::call_stmt() {
  Call_stmtContext *_localctx = _tracker.createInstance<Call_stmtContext>(_ctx, getState());
  enterRule(_localctx, 32, TinyParser::RuleCall_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    func_call();
    setState(156);
    match(TinyParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

TinyParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::Return_stmtContext::RETURN() {
  return getToken(TinyParser::RETURN, 0);
}

TinyParser::ExpContext* TinyParser::Return_stmtContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}

tree::TerminalNode* TinyParser::Return_stmtContext::SEMI() {
  return getToken(TinyParser::SEMI, 0);
}


size_t TinyParser::Return_stmtContext::getRuleIndex() const {
  return TinyParser::RuleReturn_stmt;
}


antlrcpp::Any TinyParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Return_stmtContext* TinyParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 34, TinyParser::RuleReturn_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(TinyParser::RETURN);
    setState(159);
    exp();
    setState(160);
    match(TinyParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

TinyParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::Func_callContext::ID() {
  return getToken(TinyParser::ID, 0);
}

tree::TerminalNode* TinyParser::Func_callContext::LPAR() {
  return getToken(TinyParser::LPAR, 0);
}

TinyParser::ArgsContext* TinyParser::Func_callContext::args() {
  return getRuleContext<TinyParser::ArgsContext>(0);
}

tree::TerminalNode* TinyParser::Func_callContext::RPAR() {
  return getToken(TinyParser::RPAR, 0);
}


size_t TinyParser::Func_callContext::getRuleIndex() const {
  return TinyParser::RuleFunc_call;
}


antlrcpp::Any TinyParser::Func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitFunc_call(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::Func_callContext* TinyParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 36, TinyParser::RuleFunc_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(TinyParser::ID);
    setState(163);
    match(TinyParser::LPAR);
    setState(164);
    args();
    setState(165);
    match(TinyParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

TinyParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TinyParser::ArgContext *> TinyParser::ArgsContext::arg() {
  return getRuleContexts<TinyParser::ArgContext>();
}

TinyParser::ArgContext* TinyParser::ArgsContext::arg(size_t i) {
  return getRuleContext<TinyParser::ArgContext>(i);
}


size_t TinyParser::ArgsContext::getRuleIndex() const {
  return TinyParser::RuleArgs;
}


antlrcpp::Any TinyParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::ArgsContext* TinyParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 38, TinyParser::RuleArgs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TinyParser::MINUS)
      | (1ULL << TinyParser::LPAR)
      | (1ULL << TinyParser::TRUE)
      | (1ULL << TinyParser::FALSE)
      | (1ULL << TinyParser::REAL)
      | (1ULL << TinyParser::NUM)
      | (1ULL << TinyParser::ID))) != 0)) {
      setState(167);
      arg();
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

TinyParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::ExpContext* TinyParser::ArgContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}

tree::TerminalNode* TinyParser::ArgContext::COMMA() {
  return getToken(TinyParser::COMMA, 0);
}


size_t TinyParser::ArgContext::getRuleIndex() const {
  return TinyParser::RuleArg;
}


antlrcpp::Any TinyParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::ArgContext* TinyParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 40, TinyParser::RuleArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    exp();
    setState(174);
    match(TinyParser::COMMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

TinyParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TinyParser::Simple_expContext *> TinyParser::ExpContext::simple_exp() {
  return getRuleContexts<TinyParser::Simple_expContext>();
}

TinyParser::Simple_expContext* TinyParser::ExpContext::simple_exp(size_t i) {
  return getRuleContext<TinyParser::Simple_expContext>(i);
}

tree::TerminalNode* TinyParser::ExpContext::GT() {
  return getToken(TinyParser::GT, 0);
}

tree::TerminalNode* TinyParser::ExpContext::EQUAL() {
  return getToken(TinyParser::EQUAL, 0);
}

tree::TerminalNode* TinyParser::ExpContext::LT() {
  return getToken(TinyParser::LT, 0);
}


size_t TinyParser::ExpContext::getRuleIndex() const {
  return TinyParser::RuleExp;
}


antlrcpp::Any TinyParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::ExpContext* TinyParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 42, TinyParser::RuleExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(176);
      simple_exp(0);
      setState(177);
      dynamic_cast<ExpContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TinyParser::EQUAL)
        | (1ULL << TinyParser::GT)
        | (1ULL << TinyParser::LT))) != 0))) {
        dynamic_cast<ExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(178);
      simple_exp(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(180);
      simple_exp(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expContext ------------------------------------------------------------------

TinyParser::Simple_expContext::Simple_expContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::TermContext* TinyParser::Simple_expContext::term() {
  return getRuleContext<TinyParser::TermContext>(0);
}

TinyParser::Simple_expContext* TinyParser::Simple_expContext::simple_exp() {
  return getRuleContext<TinyParser::Simple_expContext>(0);
}

tree::TerminalNode* TinyParser::Simple_expContext::PLUS() {
  return getToken(TinyParser::PLUS, 0);
}

tree::TerminalNode* TinyParser::Simple_expContext::MINUS() {
  return getToken(TinyParser::MINUS, 0);
}


size_t TinyParser::Simple_expContext::getRuleIndex() const {
  return TinyParser::RuleSimple_exp;
}


antlrcpp::Any TinyParser::Simple_expContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitSimple_exp(this);
  else
    return visitor->visitChildren(this);
}


TinyParser::Simple_expContext* TinyParser::simple_exp() {
   return simple_exp(0);
}

TinyParser::Simple_expContext* TinyParser::simple_exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TinyParser::Simple_expContext *_localctx = _tracker.createInstance<Simple_expContext>(_ctx, parentState);
  TinyParser::Simple_expContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, TinyParser::RuleSimple_exp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(184);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(191);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSimple_exp);
        setState(186);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(187);
        dynamic_cast<Simple_expContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == TinyParser::PLUS

        || _la == TinyParser::MINUS)) {
          dynamic_cast<Simple_expContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(188);
        term(0); 
      }
      setState(193);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

TinyParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TinyParser::UnaryContext* TinyParser::TermContext::unary() {
  return getRuleContext<TinyParser::UnaryContext>(0);
}

TinyParser::TermContext* TinyParser::TermContext::term() {
  return getRuleContext<TinyParser::TermContext>(0);
}

tree::TerminalNode* TinyParser::TermContext::MULT() {
  return getToken(TinyParser::MULT, 0);
}

tree::TerminalNode* TinyParser::TermContext::DIV() {
  return getToken(TinyParser::DIV, 0);
}


size_t TinyParser::TermContext::getRuleIndex() const {
  return TinyParser::RuleTerm;
}


antlrcpp::Any TinyParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


TinyParser::TermContext* TinyParser::term() {
   return term(0);
}

TinyParser::TermContext* TinyParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TinyParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  TinyParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, TinyParser::RuleTerm, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(195);
    unary();
    _ctx->stop = _input->LT(-1);
    setState(202);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(197);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(198);
        dynamic_cast<TermContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == TinyParser::MULT

        || _la == TinyParser::DIV)) {
          dynamic_cast<TermContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(199);
        unary(); 
      }
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryContext ------------------------------------------------------------------

TinyParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::UnaryContext::MINUS() {
  return getToken(TinyParser::MINUS, 0);
}

TinyParser::UnaryContext* TinyParser::UnaryContext::unary() {
  return getRuleContext<TinyParser::UnaryContext>(0);
}

TinyParser::FactorContext* TinyParser::UnaryContext::factor() {
  return getRuleContext<TinyParser::FactorContext>(0);
}


size_t TinyParser::UnaryContext::getRuleIndex() const {
  return TinyParser::RuleUnary;
}


antlrcpp::Any TinyParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::UnaryContext* TinyParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 48, TinyParser::RuleUnary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TinyParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(205);
        match(TinyParser::MINUS);
        setState(206);
        unary();
        break;
      }

      case TinyParser::LPAR:
      case TinyParser::TRUE:
      case TinyParser::FALSE:
      case TinyParser::REAL:
      case TinyParser::NUM:
      case TinyParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(207);
        factor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

TinyParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TinyParser::FactorContext::LPAR() {
  return getToken(TinyParser::LPAR, 0);
}

TinyParser::ExpContext* TinyParser::FactorContext::exp() {
  return getRuleContext<TinyParser::ExpContext>(0);
}

tree::TerminalNode* TinyParser::FactorContext::RPAR() {
  return getToken(TinyParser::RPAR, 0);
}

tree::TerminalNode* TinyParser::FactorContext::NUM() {
  return getToken(TinyParser::NUM, 0);
}

tree::TerminalNode* TinyParser::FactorContext::REAL() {
  return getToken(TinyParser::REAL, 0);
}

tree::TerminalNode* TinyParser::FactorContext::TRUE() {
  return getToken(TinyParser::TRUE, 0);
}

tree::TerminalNode* TinyParser::FactorContext::FALSE() {
  return getToken(TinyParser::FALSE, 0);
}

tree::TerminalNode* TinyParser::FactorContext::ID() {
  return getToken(TinyParser::ID, 0);
}

TinyParser::Func_callContext* TinyParser::FactorContext::func_call() {
  return getRuleContext<TinyParser::Func_callContext>(0);
}


size_t TinyParser::FactorContext::getRuleIndex() const {
  return TinyParser::RuleFactor;
}


antlrcpp::Any TinyParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TinyVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

TinyParser::FactorContext* TinyParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 50, TinyParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(210);
      match(TinyParser::LPAR);
      setState(211);
      exp();
      setState(212);
      match(TinyParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(214);
      match(TinyParser::NUM);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(215);
      match(TinyParser::REAL);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(216);
      match(TinyParser::TRUE);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(217);
      match(TinyParser::FALSE);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(218);
      match(TinyParser::ID);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(219);
      func_call();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool TinyParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 22: return simple_expSempred(dynamic_cast<Simple_expContext *>(context), predicateIndex);
    case 23: return termSempred(dynamic_cast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TinyParser::simple_expSempred(Simple_expContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool TinyParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> TinyParser::_decisionToDFA;
atn::PredictionContextCache TinyParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TinyParser::_atn;
std::vector<uint16_t> TinyParser::_serializedATN;

std::vector<std::string> TinyParser::_ruleNames = {
  "prog", "functions", "function", "params", "param", "func_body", "decls", 
  "decl", "type", "stmts", "stmt", "if_stmt", "repeat_stmt", "assign_stmt", 
  "read_stmt", "write_stmt", "call_stmt", "return_stmt", "func_call", "args", 
  "arg", "exp", "simple_exp", "term", "unary", "factor"
};

std::vector<std::string> TinyParser::_literalNames = {
  "", "'+'", "'-'", "'='", "'>'", "'<'", "'*'", "'/'", "'('", "')'", "':='", 
  "';'", "'{'", "'}'", "','", "'if'", "'then'", "'else'", "'end'", "'repeat'", 
  "'until'", "'read'", "'write'", "'char'", "'int'", "'float'", "'bool'", 
  "'true'", "'false'", "'void'", "'return'"
};

std::vector<std::string> TinyParser::_symbolicNames = {
  "", "PLUS", "MINUS", "EQUAL", "GT", "LT", "MULT", "DIV", "LPAR", "RPAR", 
  "ASSIGN", "SEMI", "LBRA", "RBRA", "COMMA", "IF", "THEN", "ELSE", "END", 
  "REPEAT", "UNTIL", "READ", "WRITE", "CHAR", "INT", "FLOAT", "BOOL", "TRUE", 
  "FALSE", "VOID", "RETURN", "REAL", "NUM", "ID", "WS"
};

dfa::Vocabulary TinyParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TinyParser::_tokenNames;

TinyParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x24, 0xe1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 
       0x3, 0x3a, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x3b, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x5, 0x7, 0x5, 0x48, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4b, 
       0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x8, 0x7, 0x8, 0x55, 0xa, 0x8, 0xc, 0x8, 0xe, 
       0x8, 0x58, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
       0x64, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x7, 0xb, 0x69, 0xa, 
       0xb, 0xc, 0xb, 0xe, 0xb, 0x6c, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x75, 0xa, 
       0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
       0x89, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x15, 0x7, 0x15, 0xab, 0xa, 0x15, 0xc, 0x15, 
       0xe, 0x15, 0xae, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0xb8, 
       0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x7, 0x18, 0xc0, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0xc3, 
       0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x7, 0x19, 0xcb, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0xce, 
       0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0xd3, 0xa, 
       0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xdf, 
       0xa, 0x1b, 0x3, 0x1b, 0x2, 0x4, 0x2e, 0x30, 0x1c, 0x2, 0x4, 0x6, 
       0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
       0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
       0x2, 0x6, 0x4, 0x2, 0x19, 0x1c, 0x1f, 0x1f, 0x3, 0x2, 0x5, 0x7, 0x3, 
       0x2, 0x3, 0x4, 0x3, 0x2, 0x8, 0x9, 0x2, 0xdd, 0x2, 0x36, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0x39, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3d, 0x3, 0x2, 0x2, 
       0x2, 0x8, 0x49, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4c, 0x3, 0x2, 0x2, 0x2, 
       0xc, 0x50, 0x3, 0x2, 0x2, 0x2, 0xe, 0x56, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0x63, 0x3, 0x2, 0x2, 0x2, 0x12, 0x65, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6a, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0x74, 0x3, 0x2, 0x2, 0x2, 0x18, 0x88, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x90, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0x95, 0x3, 0x2, 0x2, 0x2, 0x20, 0x99, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa0, 0x3, 0x2, 0x2, 0x2, 
       0x26, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xac, 0x3, 0x2, 0x2, 0x2, 0x2a, 
       0xaf, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x32, 0xd2, 0x3, 
       0x2, 0x2, 0x2, 0x34, 0xde, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x5, 0x4, 
       0x3, 0x2, 0x37, 0x3, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x5, 0x6, 0x4, 
       0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 
       0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 
       0x5, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0x12, 0xa, 0x2, 0x3e, 0x3f, 
       0x7, 0x23, 0x2, 0x2, 0x3f, 0x40, 0x7, 0xa, 0x2, 0x2, 0x40, 0x41, 
       0x5, 0x8, 0x5, 0x2, 0x41, 0x42, 0x7, 0xb, 0x2, 0x2, 0x42, 0x43, 0x7, 
       0xe, 0x2, 0x2, 0x43, 0x44, 0x5, 0xc, 0x7, 0x2, 0x44, 0x45, 0x7, 0xf, 
       0x2, 0x2, 0x45, 0x7, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x5, 0xa, 0x6, 
       0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 
       0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 
       0x9, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
       0x5, 0x12, 0xa, 0x2, 0x4d, 0x4e, 0x7, 0x23, 0x2, 0x2, 0x4e, 0x4f, 
       0x7, 0x10, 0x2, 0x2, 0x4f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x5, 
       0xe, 0x8, 0x2, 0x51, 0x52, 0x5, 0x14, 0xb, 0x2, 0x52, 0xd, 0x3, 0x2, 
       0x2, 0x2, 0x53, 0x55, 0x5, 0x10, 0x9, 0x2, 0x54, 0x53, 0x3, 0x2, 
       0x2, 0x2, 0x55, 0x58, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 
       0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x12, 0xa, 0x2, 
       0x5a, 0x5b, 0x7, 0x23, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0xd, 0x2, 0x2, 
       0x5c, 0x64, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0x12, 0xa, 0x2, 
       0x5e, 0x5f, 0x7, 0x23, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xc, 0x2, 0x2, 
       0x60, 0x61, 0x5, 0x2c, 0x17, 0x2, 0x61, 0x62, 0x7, 0xd, 0x2, 0x2, 
       0x62, 0x64, 0x3, 0x2, 0x2, 0x2, 0x63, 0x59, 0x3, 0x2, 0x2, 0x2, 0x63, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x64, 0x11, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 
       0x9, 0x2, 0x2, 0x2, 0x66, 0x13, 0x3, 0x2, 0x2, 0x2, 0x67, 0x69, 0x5, 
       0x16, 0xc, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x3, 
       0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 
       0x2, 0x2, 0x6b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 
       0x2, 0x6d, 0x75, 0x5, 0x18, 0xd, 0x2, 0x6e, 0x75, 0x5, 0x1a, 0xe, 
       0x2, 0x6f, 0x75, 0x5, 0x1c, 0xf, 0x2, 0x70, 0x75, 0x5, 0x1e, 0x10, 
       0x2, 0x71, 0x75, 0x5, 0x20, 0x11, 0x2, 0x72, 0x75, 0x5, 0x22, 0x12, 
       0x2, 0x73, 0x75, 0x5, 0x24, 0x13, 0x2, 0x74, 0x6d, 0x3, 0x2, 0x2, 
       0x2, 0x74, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x74, 0x6f, 0x3, 0x2, 0x2, 0x2, 
       0x74, 0x70, 0x3, 0x2, 0x2, 0x2, 0x74, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 
       0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x11, 0x2, 0x2, 0x77, 0x78, 
       0x7, 0xa, 0x2, 0x2, 0x78, 0x79, 0x5, 0x2c, 0x17, 0x2, 0x79, 0x7a, 
       0x7, 0xb, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x12, 0x2, 0x2, 0x7b, 0x7c, 
       0x5, 0x14, 0xb, 0x2, 0x7c, 0x7d, 0x7, 0x14, 0x2, 0x2, 0x7d, 0x89, 
       0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x11, 0x2, 0x2, 0x7f, 0x80, 
       0x7, 0xa, 0x2, 0x2, 0x80, 0x81, 0x5, 0x2c, 0x17, 0x2, 0x81, 0x82, 
       0x7, 0xb, 0x2, 0x2, 0x82, 0x83, 0x7, 0x12, 0x2, 0x2, 0x83, 0x84, 
       0x5, 0x14, 0xb, 0x2, 0x84, 0x85, 0x7, 0x13, 0x2, 0x2, 0x85, 0x86, 
       0x5, 0x14, 0xb, 0x2, 0x86, 0x87, 0x7, 0x14, 0x2, 0x2, 0x87, 0x89, 
       0x3, 0x2, 0x2, 0x2, 0x88, 0x76, 0x3, 0x2, 0x2, 0x2, 0x88, 0x7e, 0x3, 
       0x2, 0x2, 0x2, 0x89, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x15, 
       0x2, 0x2, 0x8b, 0x8c, 0x5, 0x14, 0xb, 0x2, 0x8c, 0x8d, 0x7, 0x16, 
       0x2, 0x2, 0x8d, 0x8e, 0x5, 0x2c, 0x17, 0x2, 0x8e, 0x8f, 0x7, 0xd, 
       0x2, 0x2, 0x8f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x7, 0x23, 
       0x2, 0x2, 0x91, 0x92, 0x7, 0xc, 0x2, 0x2, 0x92, 0x93, 0x5, 0x2c, 
       0x17, 0x2, 0x93, 0x94, 0x7, 0xd, 0x2, 0x2, 0x94, 0x1d, 0x3, 0x2, 
       0x2, 0x2, 0x95, 0x96, 0x7, 0x17, 0x2, 0x2, 0x96, 0x97, 0x7, 0x23, 
       0x2, 0x2, 0x97, 0x98, 0x7, 0xd, 0x2, 0x2, 0x98, 0x1f, 0x3, 0x2, 0x2, 
       0x2, 0x99, 0x9a, 0x7, 0x18, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x2c, 0x17, 
       0x2, 0x9b, 0x9c, 0x7, 0xd, 0x2, 0x2, 0x9c, 0x21, 0x3, 0x2, 0x2, 0x2, 
       0x9d, 0x9e, 0x5, 0x26, 0x14, 0x2, 0x9e, 0x9f, 0x7, 0xd, 0x2, 0x2, 
       0x9f, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x20, 0x2, 0x2, 
       0xa1, 0xa2, 0x5, 0x2c, 0x17, 0x2, 0xa2, 0xa3, 0x7, 0xd, 0x2, 0x2, 
       0xa3, 0x25, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x23, 0x2, 0x2, 
       0xa5, 0xa6, 0x7, 0xa, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x28, 0x15, 0x2, 
       0xa7, 0xa8, 0x7, 0xb, 0x2, 0x2, 0xa8, 0x27, 0x3, 0x2, 0x2, 0x2, 0xa9, 
       0xab, 0x5, 0x2a, 0x16, 0x2, 0xaa, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 
       0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 
       0x3, 0x2, 0x2, 0x2, 0xad, 0x29, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 
       0x2, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x2c, 0x17, 0x2, 0xb0, 0xb1, 0x7, 
       0x10, 0x2, 0x2, 0xb1, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x5, 
       0x2e, 0x18, 0x2, 0xb3, 0xb4, 0x9, 0x3, 0x2, 0x2, 0xb4, 0xb5, 0x5, 
       0x2e, 0x18, 0x2, 0xb5, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb8, 0x5, 
       0x2e, 0x18, 0x2, 0xb7, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb6, 0x3, 
       0x2, 0x2, 0x2, 0xb8, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x8, 0x18, 
       0x1, 0x2, 0xba, 0xbb, 0x5, 0x30, 0x19, 0x2, 0xbb, 0xc1, 0x3, 0x2, 
       0x2, 0x2, 0xbc, 0xbd, 0xc, 0x4, 0x2, 0x2, 0xbd, 0xbe, 0x9, 0x4, 0x2, 
       0x2, 0xbe, 0xc0, 0x5, 0x30, 0x19, 0x2, 0xbf, 0xbc, 0x3, 0x2, 0x2, 
       0x2, 0xc0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 
       0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xc3, 
       0xc1, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x8, 0x19, 0x1, 0x2, 0xc5, 
       0xc6, 0x5, 0x32, 0x1a, 0x2, 0xc6, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xc7, 
       0xc8, 0xc, 0x4, 0x2, 0x2, 0xc8, 0xc9, 0x9, 0x5, 0x2, 0x2, 0xc9, 0xcb, 
       0x5, 0x32, 0x1a, 0x2, 0xca, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 
       0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 
       0x2, 0x2, 0x2, 0xcd, 0x31, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 
       0x2, 0x2, 0xcf, 0xd0, 0x7, 0x4, 0x2, 0x2, 0xd0, 0xd3, 0x5, 0x32, 
       0x1a, 0x2, 0xd1, 0xd3, 0x5, 0x34, 0x1b, 0x2, 0xd2, 0xcf, 0x3, 0x2, 
       0x2, 0x2, 0xd2, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0x33, 0x3, 0x2, 0x2, 
       0x2, 0xd4, 0xd5, 0x7, 0xa, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x2c, 0x17, 
       0x2, 0xd6, 0xd7, 0x7, 0xb, 0x2, 0x2, 0xd7, 0xdf, 0x3, 0x2, 0x2, 0x2, 
       0xd8, 0xdf, 0x7, 0x22, 0x2, 0x2, 0xd9, 0xdf, 0x7, 0x21, 0x2, 0x2, 
       0xda, 0xdf, 0x7, 0x1d, 0x2, 0x2, 0xdb, 0xdf, 0x7, 0x1e, 0x2, 0x2, 
       0xdc, 0xdf, 0x7, 0x23, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x26, 0x14, 0x2, 
       0xde, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xde, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xde, 
       0xd9, 0x3, 0x2, 0x2, 0x2, 0xde, 0xda, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdb, 
       0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdd, 0x3, 
       0x2, 0x2, 0x2, 0xdf, 0x35, 0x3, 0x2, 0x2, 0x2, 0xf, 0x3b, 0x49, 0x56, 
       0x63, 0x6a, 0x74, 0x88, 0xac, 0xb7, 0xc1, 0xcc, 0xd2, 0xde, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TinyParser::Initializer TinyParser::_init;
