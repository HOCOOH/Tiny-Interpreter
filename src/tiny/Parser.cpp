#include "Parser.h"
#include <sstream>

antlrcpp::Any TinyCodeVisitor::visitDecl(TinyParser::DeclContext *ctx) {
    if (ctx->type()) {
        std::string type = ctx->type()->getText();
        std::string name = ctx->ID()->getText();
        // std::cout << type << " " << name << std::endl;
        if (type == "int") {
            compiler->symbolTable->AddIdentifier(name, Identifier::INT, int(0));
        }
        else if (type == "char") {
            compiler->symbolTable->AddIdentifier(name, Identifier::CHAR, char(0));
        }
        else {
            std::cerr << "Unknown identifier type" << std::endl;
            exit(-1);
        }
    }
    return TinyBaseVisitor::visitDecl(ctx);
    
}

antlrcpp::Any TinyCodeVisitor::visitRead_stmt(TinyParser::Read_stmtContext *ctx) {
    std::string name = ctx->ID()->getText();
    auto id = compiler->symbolTable->Get(name);
    return 0;
    
}

antlrcpp::Any TinyCodeVisitor::visitWrite_stmt(TinyParser::Write_stmtContext *ctx) {
    return TinyBaseVisitor::visitWrite_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitAssign_stmt(TinyParser::Assign_stmtContext *ctx) {
    return TinyBaseVisitor::visitAssign_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitIf_stmt(TinyParser::If_stmtContext *ctx) {
    return TinyBaseVisitor::visitIf_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitRepeat_stmt(TinyParser::Repeat_stmtContext *ctx){
    return TinyBaseVisitor::visitRepeat_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitExp(TinyParser::ExpContext *ctx) {
        // std::cout << "sdfsdfsdfsdf\n";
        // std::cout << ctx->getText() << std::endl;
        return visitChildren(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitSimple_exp(TinyParser::Simple_expContext *ctx) {

}

antlrcpp::Any TinyCodeVisitor::visitTerm(TinyParser::TermContext *ctx) {

}

antlrcpp::Any TinyCodeVisitor::visitUnary(TinyParser::UnaryContext *ctx) {
    if (ctx->MINUS()) {

    }
    
}

antlrcpp::Any TinyCodeVisitor::visitFactor(TinyParser::FactorContext *ctx) {
    if (ctx->LPAR()) {
        return visitExp(ctx->exp());
    }
    if (ctx->NUM()) {
        std::stringstream ss;
        ss << ctx->NUM()->getText();
        int val;
        ss >> val;
        std::shared_ptr<Value> ret = std::make_shared<ValueInt>(val);
        return ret;
    }
    if (ctx->REAL()) {

    }
    if (ctx->ID()) {

    }

}