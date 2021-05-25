#include <iostream>
#include "TinyBaseVisitor.h"


class TinyCodeVisitor : public TinyBaseVisitor {

public:
    antlrcpp::Any visitDecl(TinyParser::DeclContext *ctx);

    antlrcpp::Any visitExp(TinyParser::ExpContext *ctx);

    
};