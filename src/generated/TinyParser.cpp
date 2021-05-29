
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

TinyParser::DeclsContext* TinyParser::ProgContext::decls() {
  return getRuleContext<TinyParser::DeclsContext>(0);
}

TinyParser::StmtsContext* TinyParser::ProgContext::stmts() {
  return getRuleContext<TinyParser::StmtsContext>(0);
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
    setState(32);
    decls(0);
    setState(33);
    stmts(0);
   
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

TinyParser::DeclContext* TinyParser::DeclsContext::decl() {
  return getRuleContext<TinyParser::DeclContext>(0);
}

TinyParser::DeclsContext* TinyParser::DeclsContext::decls() {
  return getRuleContext<TinyParser::DeclsContext>(0);
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
   return decls(0);
}

TinyParser::DeclsContext* TinyParser::decls(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TinyParser::DeclsContext *_localctx = _tracker.createInstance<DeclsContext>(_ctx, parentState);
  TinyParser::DeclsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, TinyParser::RuleDecls, precedence);

    

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
    setState(36);
    decl();
    _ctx->stop = _input->LT(-1);
    setState(42);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDecls);
        setState(38);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(39);
        decl(); 
      }
      setState(44);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
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
  enterRule(_localctx, 4, TinyParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(45);
      type();
      setState(46);
      match(TinyParser::ID);
      setState(47);
      match(TinyParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(49);
      type();
      setState(50);
      match(TinyParser::ID);
      setState(51);
      match(TinyParser::ASSIGN);
      setState(52);
      exp();
      setState(53);
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
  enterRule(_localctx, 6, TinyParser::RuleType);
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
    setState(57);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TinyParser::CHAR)
      | (1ULL << TinyParser::INT)
      | (1ULL << TinyParser::FLOAT)
      | (1ULL << TinyParser::BOOL))) != 0))) {
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

TinyParser::StmtContext* TinyParser::StmtsContext::stmt() {
  return getRuleContext<TinyParser::StmtContext>(0);
}

TinyParser::StmtsContext* TinyParser::StmtsContext::stmts() {
  return getRuleContext<TinyParser::StmtsContext>(0);
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
   return stmts(0);
}

TinyParser::StmtsContext* TinyParser::stmts(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TinyParser::StmtsContext *_localctx = _tracker.createInstance<StmtsContext>(_ctx, parentState);
  TinyParser::StmtsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, TinyParser::RuleStmts, precedence);

    

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
    setState(60);
    stmt();
    _ctx->stop = _input->LT(-1);
    setState(66);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StmtsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStmts);
        setState(62);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(63);
        stmt(); 
      }
      setState(68);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
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
  enterRule(_localctx, 10, TinyParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TinyParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        if_stmt();
        break;
      }

      case TinyParser::REPEAT: {
        enterOuterAlt(_localctx, 2);
        setState(70);
        repeat_stmt();
        break;
      }

      case TinyParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(71);
        assign_stmt();
        break;
      }

      case TinyParser::READ: {
        enterOuterAlt(_localctx, 4);
        setState(72);
        read_stmt();
        break;
      }

      case TinyParser::WRITE: {
        enterOuterAlt(_localctx, 5);
        setState(73);
        write_stmt();
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
  enterRule(_localctx, 12, TinyParser::RuleIf_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(76);
      match(TinyParser::IF);
      setState(77);
      match(TinyParser::LPAR);
      setState(78);
      exp();
      setState(79);
      match(TinyParser::RPAR);
      setState(80);
      match(TinyParser::THEN);
      setState(81);
      stmts(0);
      setState(82);
      match(TinyParser::END);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(84);
      match(TinyParser::IF);
      setState(85);
      match(TinyParser::LPAR);
      setState(86);
      exp();
      setState(87);
      match(TinyParser::RPAR);
      setState(88);
      match(TinyParser::THEN);
      setState(89);
      stmts(0);
      setState(90);
      match(TinyParser::ELSE);
      setState(91);
      stmts(0);
      setState(92);
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
  enterRule(_localctx, 14, TinyParser::RuleRepeat_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(TinyParser::REPEAT);
    setState(97);
    stmts(0);
    setState(98);
    match(TinyParser::UNTIL);
    setState(99);
    exp();
    setState(100);
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
  enterRule(_localctx, 16, TinyParser::RuleAssign_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    match(TinyParser::ID);
    setState(103);
    match(TinyParser::ASSIGN);
    setState(104);
    exp();
    setState(105);
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
  enterRule(_localctx, 18, TinyParser::RuleRead_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(TinyParser::READ);
    setState(108);
    match(TinyParser::ID);
    setState(109);
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
  enterRule(_localctx, 20, TinyParser::RuleWrite_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(TinyParser::WRITE);
    setState(112);
    exp();
    setState(113);
    match(TinyParser::SEMI);
   
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
  enterRule(_localctx, 22, TinyParser::RuleExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      simple_exp(0);
      setState(116);
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
      setState(117);
      simple_exp(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(119);
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
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, TinyParser::RuleSimple_exp, precedence);

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
    setState(123);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(130);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSimple_exp);
        setState(125);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(126);
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
        setState(127);
        term(0); 
      }
      setState(132);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
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
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, TinyParser::RuleTerm, precedence);

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
    setState(134);
    unary();
    _ctx->stop = _input->LT(-1);
    setState(141);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(136);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(137);
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
        setState(138);
        unary(); 
      }
      setState(143);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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
  enterRule(_localctx, 28, TinyParser::RuleUnary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TinyParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(144);
        match(TinyParser::MINUS);
        setState(145);
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
        setState(146);
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
  enterRule(_localctx, 30, TinyParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TinyParser::LPAR: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        match(TinyParser::LPAR);
        setState(150);
        exp();
        setState(151);
        match(TinyParser::RPAR);
        break;
      }

      case TinyParser::NUM: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        match(TinyParser::NUM);
        break;
      }

      case TinyParser::REAL: {
        enterOuterAlt(_localctx, 3);
        setState(154);
        match(TinyParser::REAL);
        break;
      }

      case TinyParser::TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(155);
        match(TinyParser::TRUE);
        break;
      }

      case TinyParser::FALSE: {
        enterOuterAlt(_localctx, 5);
        setState(156);
        match(TinyParser::FALSE);
        break;
      }

      case TinyParser::ID: {
        enterOuterAlt(_localctx, 6);
        setState(157);
        match(TinyParser::ID);
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

bool TinyParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return declsSempred(dynamic_cast<DeclsContext *>(context), predicateIndex);
    case 4: return stmtsSempred(dynamic_cast<StmtsContext *>(context), predicateIndex);
    case 12: return simple_expSempred(dynamic_cast<Simple_expContext *>(context), predicateIndex);
    case 13: return termSempred(dynamic_cast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TinyParser::declsSempred(DeclsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool TinyParser::stmtsSempred(StmtsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool TinyParser::simple_expSempred(Simple_expContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool TinyParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 2);

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
  "prog", "decls", "decl", "type", "stmts", "stmt", "if_stmt", "repeat_stmt", 
  "assign_stmt", "read_stmt", "write_stmt", "exp", "simple_exp", "term", 
  "unary", "factor"
};

std::vector<std::string> TinyParser::_literalNames = {
  "", "'+'", "'-'", "'='", "'>'", "'<'", "'*'", "'/'", "'('", "')'", "':='", 
  "';'", "'if'", "'then'", "'else'", "'end'", "'repeat'", "'until'", "'read'", 
  "'write'", "'char'", "'int'", "'float'", "'bool'", "'true'", "'false'"
};

std::vector<std::string> TinyParser::_symbolicNames = {
  "", "PLUS", "MINUS", "EQUAL", "GT", "LT", "MULT", "DIV", "LPAR", "RPAR", 
  "ASSIGN", "SEMI", "IF", "THEN", "ELSE", "END", "REPEAT", "UNTIL", "READ", 
  "WRITE", "CHAR", "INT", "FLOAT", "BOOL", "TRUE", "FALSE", "REAL", "NUM", 
  "ID", "WS"
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
       0x3, 0x1f, 0xa3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2b, 0xa, 0x3, 0xc, 0x3, 0xe, 
       0x3, 0x2e, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0x3a, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x43, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
       0x46, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x5, 0x7, 0x4d, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x5, 0x8, 0x61, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x5, 0xd, 0x7b, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x83, 0xa, 0xe, 0xc, 
       0xe, 0xe, 0xe, 0x86, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x8e, 0xa, 0xf, 0xc, 0xf, 0xe, 
       0xf, 0x91, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
       0x96, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xa1, 
       0xa, 0x11, 0x3, 0x11, 0x2, 0x6, 0x4, 0xa, 0x1a, 0x1c, 0x12, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x2, 0x6, 0x3, 0x2, 0x16, 0x19, 0x3, 0x2, 0x5, 
       0x7, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x8, 0x9, 0x2, 0xa3, 0x2, 0x22, 
       0x3, 0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x6, 0x39, 0x3, 
       0x2, 0x2, 0x2, 0x8, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3d, 0x3, 0x2, 
       0x2, 0x2, 0xc, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x60, 0x3, 0x2, 0x2, 
       0x2, 0x10, 0x62, 0x3, 0x2, 0x2, 0x2, 0x12, 0x68, 0x3, 0x2, 0x2, 0x2, 
       0x14, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x16, 0x71, 0x3, 0x2, 0x2, 0x2, 0x18, 
       0x7a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x87, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0x95, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa0, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x23, 0x5, 0x4, 0x3, 0x2, 0x23, 0x24, 0x5, 0xa, 
       0x6, 0x2, 0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x8, 0x3, 0x1, 
       0x2, 0x26, 0x27, 0x5, 0x6, 0x4, 0x2, 0x27, 0x2c, 0x3, 0x2, 0x2, 0x2, 
       0x28, 0x29, 0xc, 0x4, 0x2, 0x2, 0x29, 0x2b, 0x5, 0x6, 0x4, 0x2, 0x2a, 
       0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 
       0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x5, 0x8, 
       0x5, 0x2, 0x30, 0x31, 0x7, 0x1e, 0x2, 0x2, 0x31, 0x32, 0x7, 0xd, 
       0x2, 0x2, 0x32, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x5, 0x8, 0x5, 
       0x2, 0x34, 0x35, 0x7, 0x1e, 0x2, 0x2, 0x35, 0x36, 0x7, 0xc, 0x2, 
       0x2, 0x36, 0x37, 0x5, 0x18, 0xd, 0x2, 0x37, 0x38, 0x7, 0xd, 0x2, 
       0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x2f, 0x3, 0x2, 0x2, 0x2, 
       0x39, 0x33, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3b, 
       0x3c, 0x9, 0x2, 0x2, 0x2, 0x3c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 
       0x8, 0x6, 0x1, 0x2, 0x3e, 0x3f, 0x5, 0xc, 0x7, 0x2, 0x3f, 0x44, 0x3, 
       0x2, 0x2, 0x2, 0x40, 0x41, 0xc, 0x4, 0x2, 0x2, 0x41, 0x43, 0x5, 0xc, 
       0x7, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 
       0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 
       0x45, 0xb, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x47, 
       0x4d, 0x5, 0xe, 0x8, 0x2, 0x48, 0x4d, 0x5, 0x10, 0x9, 0x2, 0x49, 
       0x4d, 0x5, 0x12, 0xa, 0x2, 0x4a, 0x4d, 0x5, 0x14, 0xb, 0x2, 0x4b, 
       0x4d, 0x5, 0x16, 0xc, 0x2, 0x4c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4c, 
       0x48, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 
       0x3, 0x2, 0x2, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0xe, 0x2, 0x2, 0x4f, 0x50, 0x7, 0xa, 
       0x2, 0x2, 0x50, 0x51, 0x5, 0x18, 0xd, 0x2, 0x51, 0x52, 0x7, 0xb, 
       0x2, 0x2, 0x52, 0x53, 0x7, 0xf, 0x2, 0x2, 0x53, 0x54, 0x5, 0xa, 0x6, 
       0x2, 0x54, 0x55, 0x7, 0x11, 0x2, 0x2, 0x55, 0x61, 0x3, 0x2, 0x2, 
       0x2, 0x56, 0x57, 0x7, 0xe, 0x2, 0x2, 0x57, 0x58, 0x7, 0xa, 0x2, 0x2, 
       0x58, 0x59, 0x5, 0x18, 0xd, 0x2, 0x59, 0x5a, 0x7, 0xb, 0x2, 0x2, 
       0x5a, 0x5b, 0x7, 0xf, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0xa, 0x6, 0x2, 0x5c, 
       0x5d, 0x7, 0x10, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0xa, 0x6, 0x2, 0x5e, 
       0x5f, 0x7, 0x11, 0x2, 0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x60, 
       0x4e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x56, 0x3, 0x2, 0x2, 0x2, 0x61, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x12, 0x2, 0x2, 0x63, 0x64, 
       0x5, 0xa, 0x6, 0x2, 0x64, 0x65, 0x7, 0x13, 0x2, 0x2, 0x65, 0x66, 
       0x5, 0x18, 0xd, 0x2, 0x66, 0x67, 0x7, 0xd, 0x2, 0x2, 0x67, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x1e, 0x2, 0x2, 0x69, 0x6a, 
       0x7, 0xc, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0x18, 0xd, 0x2, 0x6b, 0x6c, 
       0x7, 0xd, 0x2, 0x2, 0x6c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x7, 
       0x14, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x1e, 0x2, 0x2, 0x6f, 0x70, 0x7, 
       0xd, 0x2, 0x2, 0x70, 0x15, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x15, 
       0x2, 0x2, 0x72, 0x73, 0x5, 0x18, 0xd, 0x2, 0x73, 0x74, 0x7, 0xd, 
       0x2, 0x2, 0x74, 0x17, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x5, 0x1a, 
       0xe, 0x2, 0x76, 0x77, 0x9, 0x3, 0x2, 0x2, 0x77, 0x78, 0x5, 0x1a, 
       0xe, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7b, 0x5, 0x1a, 
       0xe, 0x2, 0x7a, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x79, 0x3, 0x2, 0x2, 
       0x2, 0x7b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x8, 0xe, 0x1, 0x2, 
       0x7d, 0x7e, 0x5, 0x1c, 0xf, 0x2, 0x7e, 0x84, 0x3, 0x2, 0x2, 0x2, 
       0x7f, 0x80, 0xc, 0x4, 0x2, 0x2, 0x80, 0x81, 0x9, 0x4, 0x2, 0x2, 0x81, 
       0x83, 0x5, 0x1c, 0xf, 0x2, 0x82, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x83, 
       0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 
       0x3, 0x2, 0x2, 0x2, 0x85, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 
       0x2, 0x2, 0x2, 0x87, 0x88, 0x8, 0xf, 0x1, 0x2, 0x88, 0x89, 0x5, 0x1e, 
       0x10, 0x2, 0x89, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0xc, 0x4, 
       0x2, 0x2, 0x8b, 0x8c, 0x9, 0x5, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0x1e, 
       0x10, 0x2, 0x8d, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 0x3, 0x2, 
       0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 
       0x2, 0x90, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 
       0x92, 0x93, 0x7, 0x4, 0x2, 0x2, 0x93, 0x96, 0x5, 0x1e, 0x10, 0x2, 
       0x94, 0x96, 0x5, 0x20, 0x11, 0x2, 0x95, 0x92, 0x3, 0x2, 0x2, 0x2, 
       0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x97, 
       0x98, 0x7, 0xa, 0x2, 0x2, 0x98, 0x99, 0x5, 0x18, 0xd, 0x2, 0x99, 
       0x9a, 0x7, 0xb, 0x2, 0x2, 0x9a, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9b, 0xa1, 
       0x7, 0x1d, 0x2, 0x2, 0x9c, 0xa1, 0x7, 0x1c, 0x2, 0x2, 0x9d, 0xa1, 
       0x7, 0x1a, 0x2, 0x2, 0x9e, 0xa1, 0x7, 0x1b, 0x2, 0x2, 0x9f, 0xa1, 
       0x7, 0x1e, 0x2, 0x2, 0xa0, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9b, 
       0x3, 0x2, 0x2, 0x2, 0xa0, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9d, 0x3, 
       0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9f, 0x3, 0x2, 
       0x2, 0x2, 0xa1, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc, 0x2c, 0x39, 0x44, 
       0x4c, 0x60, 0x7a, 0x84, 0x8f, 0x95, 0xa0, 
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
