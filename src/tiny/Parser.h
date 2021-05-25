#include "TinyBaseVisitor.h"
#include <iostream>

class MyTiny : public TinyBaseVisitor {

public:
    antlrcpp::Any visitExp(TinyParser::ExpContext *ctx);

    
};