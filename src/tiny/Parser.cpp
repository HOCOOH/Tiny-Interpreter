#include "Parser.h"

antlrcpp::Any TinyCodeVisitor::visitDecl(TinyParser::DeclContext *ctx) {
    
}


antlrcpp::Any TinyCodeVisitor::visitExp(TinyParser::ExpContext *ctx) {
        // std::cout << "sdfsdfsdfsdf\n";
        std::cout << ctx->getText() << std::endl;
        return visitChildren(ctx);
    }