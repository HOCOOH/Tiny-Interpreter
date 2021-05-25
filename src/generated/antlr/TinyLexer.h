
// Generated from antlr/Tiny.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  TinyLexer : public antlr4::Lexer {
public:
  enum {
    PLUS = 1, MINUS = 2, EQUAL = 3, GT = 4, LT = 5, MULT = 6, DIV = 7, LPAR = 8, 
    RPAR = 9, ASSIGN = 10, SEMI = 11, IF = 12, THEN = 13, ELSE = 14, END = 15, 
    REPEAT = 16, UNTIL = 17, READ = 18, WRITE = 19, CHAR = 20, INT = 21, 
    WS = 22, NUM = 23, ID = 24
  };

  explicit TinyLexer(antlr4::CharStream *input);
  ~TinyLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

