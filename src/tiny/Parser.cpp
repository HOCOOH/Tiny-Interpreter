#include "Parser.h"
#include <sstream>

antlrcpp::Any TinyCodeVisitor::visitDecl(TinyParser::DeclContext *ctx) {
    try {
        std::string type = ctx->type()->getText();
        std::string name = ctx->ID()->getText();
        // std::cout << type << " " << name << std::endl;
        if (ctx->type()->INT()) {
            interpreter->symbolTable->AddIdentifier(name, std::make_unique<Value>(Value::INT, 0));
        }
        else if (ctx->type()->FLOAT()) { 
            interpreter->symbolTable->AddIdentifier(name, std::make_unique<Value>(Value::FLOAT, 0.0));
        }
        else if (ctx->type()->CHAR()) {
            interpreter->symbolTable->AddIdentifier(name, std::make_unique<Value>(Value::CHAR, char(0)));
        }
        else if (ctx->type()->BOOL()) {
            interpreter->symbolTable->AddIdentifier(name, std::make_unique<Value>(Value::BOOL, false));
        }
        else {
            throw TinyException("Unknown Identifier Type: " + type);
        }
        // initialize
        if (ctx->ASSIGN()) {
            std::shared_ptr<Identifier> id = interpreter->symbolTable->Get(name);
            auto exp = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
            id->SetValue(std::make_unique<Value>(exp->GetType(), exp->GetVal()));
        }
    } catch (TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    return TinyBaseVisitor::visitDecl(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitRead_stmt(TinyParser::Read_stmtContext *ctx) {
    std::string name = ctx->ID()->getText();
    try {
        std::shared_ptr<Identifier> id = interpreter->symbolTable->Get(name);
        if (id->GetType() == Value::INT) {
            int val = 0;
            std::cin >> val;
            id->SetValue(std::make_unique<Value>(Value::INT, val));
        }
        else if (id->GetType() == Value::FLOAT) {
            double val = 0.0;
            std::cin >> val;
            id->SetValue(std::make_unique<Value>(Value::FLOAT, val));
        }
        else if (id->GetType() == Value::CHAR) {
            char val = 0;
            std::cin >> val;
            id->SetValue(std::make_unique<Value>(Value::CHAR, val));
        }
        else if (id->GetType() == Value::BOOL) {
            bool val = false;
            std::cin >> val;
            id->SetValue(std::make_unique<Value>(Value::BOOL, val));
        }
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    return TinyBaseVisitor::visitRead_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitWrite_stmt(TinyParser::Write_stmtContext *ctx) {
    auto ret = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
    ret->Dump();
    return 0;
    // return TinyBaseVisitor::visitWrite_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitAssign_stmt(TinyParser::Assign_stmtContext *ctx) {
    std::string name = ctx->ID()->getText();
    try {
        std::shared_ptr<Identifier> id = interpreter->symbolTable->Get(name);
        auto exp = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
        id->SetValue(std::make_unique<Value>(exp->GetType(), exp->GetVal()));
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    return TinyBaseVisitor::visitAssign_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitIf_stmt(TinyParser::If_stmtContext *ctx) {
    auto cond = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
    if (cond->GetType() != Value::BOOL) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): Expected Bool Expression" << std::endl;
        exit(-1);
    }
    if (cond->GetVal().as<bool>()) {
        visitStmts(ctx->stmts(0));
    }
    else if (ctx->ELSE()) {
        visitStmts(ctx->stmts(1));
    }
    return 0;
    // return TinyBaseVisitor::visitIf_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitRepeat_stmt(TinyParser::Repeat_stmtContext *ctx) {
    while (true) {
        visitStmts(ctx->stmts());
        auto cond = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
        if (cond->GetType() != Value::BOOL) {
            std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): Expected Bool Expression" << std::endl;
            exit(-1);
        }
        if (cond->GetVal().as<bool>()) {
            return 0;
        }
    }
    return TinyBaseVisitor::visitRepeat_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitExp(TinyParser::ExpContext *ctx) {
    if (ctx->simple_exp(0) && ctx->simple_exp(1)) {
        auto left = visitSimple_exp(ctx->simple_exp(0)).as<std::shared_ptr<Value>>();
        auto right = visitSimple_exp(ctx->simple_exp(1)).as<std::shared_ptr<Value>>();
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    if (ctx->simple_exp(0)) {
        return visitSimple_exp(ctx->simple_exp(0));
    }
    return TinyBaseVisitor::visitExp(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitSimple_exp(TinyParser::Simple_expContext *ctx) {
    if (ctx->simple_exp()) {
        auto left = visitSimple_exp(ctx->simple_exp()).as<std::shared_ptr<Value>>();
        auto right = visitTerm(ctx->term()).as<std::shared_ptr<Value>>();
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    else {
        return visitTerm(ctx->term());
    }
    return TinyBaseVisitor::visitSimple_exp(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitTerm(TinyParser::TermContext *ctx) {
    if (ctx->term()) {
        auto left = visitTerm(ctx->term()).as<std::shared_ptr<Value>>();
        auto right = visitUnary(ctx->unary()).as<std::shared_ptr<Value>>();
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    else {
        return visitUnary(ctx->unary());
    }
    return TinyBaseVisitor::visitTerm(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitUnary(TinyParser::UnaryContext *ctx) {
    if (ctx->MINUS()) {
        auto unary = visitUnary(ctx->unary()).as<std::shared_ptr<Value>>();
        auto tmp = std::make_shared<Value>(Value::INT, -1);
        return Value::BinaryCalculate(unary, tmp, TinyLexer::MULT);
    }
    if (ctx->factor()) {
        return visitFactor(ctx->factor());
    }
    return TinyBaseVisitor::visitUnary(ctx);
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
        return std::make_shared<Value>(Value::INT, val);
    }
    if (ctx->REAL()) {
        std::stringstream ss;
        ss << ctx->REAL()->getText();
        double val;
        ss >> val;
        return std::make_shared<Value>(Value::FLOAT, val);
    }
    if (ctx->TRUE()) {
        return std::make_shared<Value>(Value::BOOL, true);
    }
    if (ctx->FALSE()) {
        return std::make_shared<Value>(Value::BOOL, false);
    }
    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        try {
            std::shared_ptr<Identifier> id = interpreter->symbolTable->Get(name);
            return id->GetValue();
        } catch(TinyException& e) {
            std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
            exit(-1);
        }
    }
    return TinyBaseVisitor::visitFactor(ctx);
}

std::shared_ptr<Value> Value::BinaryCalculate(std::shared_ptr<Value> left, std::shared_ptr<Value> right, size_t op) {
    try {
        Value::Type typeL = left->GetType();
        Value::Type typeR = right->GetType();
        Value::Type typeRet = typeL < typeR ? typeL : typeR;
        double valL = left->GetValDouble();
        double valR = right->GetValDouble();
        // bool
        if (op == TinyLexer::GT || op == TinyLexer::EQUAL || op == TinyLexer::LT) {
            switch (op) {
                case TinyLexer::GT: return std::make_shared<Value>(Value::BOOL, (valL > valR));
                case TinyLexer::EQUAL: return std::make_shared<Value>(Value::BOOL, (valL == valR));
                case TinyLexer::LT: return std::make_shared<Value>(Value::BOOL, (valL < valR));
            }
        }
        // math
        double valRet = 0;
        switch (op) {
            case TinyLexer::PLUS: valRet = valL + valR; break;
            case TinyLexer::MINUS: valRet = valL - valR; break;
            case TinyLexer::MULT: valRet = valL * valR; break;
            case TinyLexer::DIV: 
                if (fabs(valR - 0) < Value::EPSILON) {
                    throw TinyException("Devide 0");
                }
                valRet = valL / valR; 
                break;
            default: throw TinyException("Invalid Op: " + op);
        }
    
        switch (typeRet) {
            case Value::FLOAT: return std::make_shared<Value>(typeRet, valRet);
            case Value::INT: return std::make_shared<Value>(typeRet, static_cast<int>(valRet));
            case Value::CHAR: return std::make_shared<Value>(typeRet, static_cast<char>(valRet));
            case Value::BOOL: return std::make_shared<Value>(typeRet, static_cast<bool>(valRet));
            default: throw TinyException("Invalid Type: " + typeRet);
        }
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << e.GetMessage() << std::endl;
        exit(-1);
    }
}