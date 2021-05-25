#include "Parser.h"

antlrcpp::Any MyTiny::visitExp(TinyParser::ExpContext *ctx) {
        // std::cout << "sdfsdfsdfsdf\n";
        std::cout << ctx->getText() << std::endl;
        return visitChildren(ctx);
    }