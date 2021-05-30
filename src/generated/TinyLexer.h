
// Generated from Tiny.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  TinyLexer : public antlr4::Lexer {
public:
  enum {
    PLUS = 1, MINUS = 2, EQUAL = 3, GT = 4, LT = 5, MULT = 6, DIV = 7, LPAR = 8, 
    RPAR = 9, ASSIGN = 10, SEMI = 11, LBRA = 12, RBRA = 13, COMMA = 14, 
    IF = 15, THEN = 16, ELSE = 17, END = 18, REPEAT = 19, UNTIL = 20, READ = 21, 
    WRITE = 22, CHAR = 23, INT = 24, FLOAT = 25, BOOL = 26, TRUE = 27, FALSE = 28, 
    VOID = 29, RETURN = 30, REAL = 31, NUM = 32, ID = 33, WS = 34
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

