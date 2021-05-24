
// Generated from antlr/Tiny.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  TinyLexer : public antlr4::Lexer {
public:
  enum {
    NUM = 1, PLUS = 2, MINUS = 3, EQUAL = 4, GT = 5, LT = 6, MULT = 7, DIV = 8, 
    LPAR = 9, RPAR = 10, ASSIGN = 11, IF = 12, THEN = 13, ELSE = 14, END = 15, 
    REPEAT = 16, UNTIL = 17, WRITE = 18, CHAR = 19, INT = 20, WS = 21, ID = 22, 
    SEMI = 23, READ = 24
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

