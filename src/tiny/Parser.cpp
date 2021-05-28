#include "Parser.h"
#include <sstream>

antlrcpp::Any TinyCodeVisitor::visitDecl(TinyParser::DeclContext *ctx) {
    if (ctx->type()) {
        std::string type = ctx->type()->getText();
        std::string name = ctx->ID()->getText();
        // std::cout << type << " " << name << std::endl;
        if (type == "int") {
            std::unique_ptr<Value> val = std::make_unique<ValueInt>(0);
            compiler->symbolTable->AddIdentifier(name, std::move(val));
        }
        else if (type == "float") { 
            //std::unique_ptr<Value> val = std::make_unique<ValueFloat>(0.0);
            //compiler->symbolTable->AddIdentifier(name, std::move(val));
            compiler->symbolTable->AddIdentifier(name, std::make_unique<ValueFloat>(0.0));
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
    try {
        std::shared_ptr<Identifier> id = compiler->symbolTable->Get(name);
        if (id->GetType() == Value::INT) {
            int val = 0;
            std::cin >> val;
            id->SetValue(std::make_unique<ValueInt>(val));
        }
        if (id->GetType() == Value::FLOAT) {
            double val = 0.0;
            std::cin >> val;
            id->SetValue(std::make_unique<ValueFloat>(val));
        }
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << '\n';
        exit(-1);
    }
    return TinyBaseVisitor::visitRead_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitWrite_stmt(TinyParser::Write_stmtContext *ctx) {
    std::shared_ptr<Value> ret = visitExp(ctx->exp());
    ret->Dump();
    if (ret->GetType() == Value::INT) {
        int retVal = ret->GetVal();
        std::cout << retVal << std::endl;
        return 0;
    }
    else if (ret->GetType() == Value::FLOAT) {
        double retVal = ret->GetVal();
        std::cout << retVal << std::endl;
        return 0;
    }
    else if (ret->GetType() == Value::BOOL) {
        bool retVal = ret->GetVal();
        std::cout << retVal << std::endl;
        return 0;
    }
    return TinyBaseVisitor::visitWrite_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitAssign_stmt(TinyParser::Assign_stmtContext *ctx) {
    std::string name = ctx->ID()->getText();
    try {
        std::shared_ptr<Identifier> id = compiler->symbolTable->Get(name);
        std::shared_ptr<Value> right = visitExp(ctx->exp());

    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << '\n';
        exit(-1);
    }
    return TinyBaseVisitor::visitAssign_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitIf_stmt(TinyParser::If_stmtContext *ctx) {

    return TinyBaseVisitor::visitIf_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitRepeat_stmt(TinyParser::Repeat_stmtContext *ctx) {
    return TinyBaseVisitor::visitRepeat_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitExp(TinyParser::ExpContext *ctx) {
    if (ctx->simple_exp(0) && ctx->simple_exp(1)) {
        std::shared_ptr<Value> left = visitSimple_exp(ctx->simple_exp(0));
        std::shared_ptr<Value> right = visitSimple_exp(ctx->simple_exp(1));
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    if (ctx->simple_exp(0)) {
        return visitSimple_exp(ctx->simple_exp(0));
    }
    return TinyBaseVisitor::visitExp(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitSimple_exp(TinyParser::Simple_expContext *ctx) {
    if (ctx->simple_exp()) {
        std::shared_ptr<Value> left = visitSimple_exp(ctx->simple_exp());
        std::shared_ptr<Value> right = visitTerm(ctx->term());
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    else {
        return visitTerm(ctx->term());
    }
    return TinyBaseVisitor::visitSimple_exp(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitTerm(TinyParser::TermContext *ctx) {
    if (ctx->term()) {
        std::shared_ptr<Value> left = visitTerm(ctx->term());
        std::shared_ptr<Value> right = visitUnary(ctx->unary());
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    else {
        return visitUnary(ctx->unary());
    }
    return TinyBaseVisitor::visitTerm(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitUnary(TinyParser::UnaryContext *ctx) {
    if (ctx->MINUS()) {
        std::shared_ptr<Value> factor = visitUnary(ctx->unary());
        if (factor->GetType() == Value::INT) {
            int retVal = factor->GetVal();
            return std::shared_ptr<Value>(std::make_shared<ValueInt>(retVal * -1));
        }
        else if (factor->GetType() == Value::FLOAT) {
            double retVal = factor->GetVal();
            return std::shared_ptr<Value>(std::make_shared<ValueFloat>(retVal * -1));
        }
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
        std::shared_ptr<Value> ret = std::make_shared<ValueInt>(val);
        return ret;
    }
    if (ctx->REAL()) {
        std::stringstream ss;
        ss << ctx->REAL()->getText();
        double val;
        ss >> val;
        std::shared_ptr<Value> ret = std::make_shared<ValueFloat>(val);
        return ret;
    }
    if (ctx->ID()) {
        std::string name = ctx->ID()->getText();
        try {
            std::shared_ptr<Identifier> id = compiler->symbolTable->Get(name);
            if (id->GetType() == Value::INT) {
                std::shared_ptr<Value> ret = std::make_shared<ValueInt>(int(id->GetValue()));
                return ret;
            }
            if (id->GetType() == Value::FLOAT) {
                std::shared_ptr<Value> ret = std::make_shared<ValueFloat>(double(id->GetValue()));
                return ret;
            }
        } catch(TinyException& e) {
            std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << '\n';
            exit(-1);
        }
    }
    return TinyBaseVisitor::visitFactor(ctx);
}

std::shared_ptr<Value> Value::BinaryCalculate(std::shared_ptr<Value> left, std::shared_ptr<Value> right, size_t op) {
    Value::Type typeL = left->GetType();
    Value::Type typeR = right->GetType();
    switch (op) {
        case TinyLexer::PLUS:
            if (left->GetType() == Value::FLOAT || right->GetType() == Value::FLOAT) {
                double retVal = double(left->GetVal()) + double(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueFloat>(retVal));
            }
            else {
                int retVal = int(left->GetVal()) + int(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueInt>(retVal));
            }
            break;
        case TinyLexer::MINUS:
            if (left->GetType() == Value::FLOAT || right->GetType() == Value::FLOAT) {
                double retVal = double(left->GetVal()) - double(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueFloat>(retVal));
            }
            else {
                int retVal = int(left->GetVal()) - int(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueInt>(retVal));
            }
            break;
        case TinyLexer::MULT:
            if (left->GetType() == Value::FLOAT || right->GetType() == Value::FLOAT) {
                double retVal = double(left->GetVal()) * double(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueFloat>(retVal));
            }
            else {
                int retVal = int(left->GetVal()) * int(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueInt>(retVal));
            }
            break;
        case TinyLexer::DIV:
            if (left->GetType() == Value::FLOAT || right->GetType() == Value::FLOAT) {
                double retVal = double(left->GetVal()) / double(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueFloat>(retVal));
            }
            else {
                int retVal = int(left->GetVal()) / int(right->GetVal());
                return std::shared_ptr<Value>(std::make_shared<ValueInt>(retVal));
            }
            break;
        case TinyLexer::GT: {
            bool retVal = double(left->GetVal()) > double(right->GetVal());
            return std::shared_ptr<Value>(std::make_shared<ValueBool>(retVal));
        }
        case TinyLexer::LT: {
            left->Dump();
            right->Dump();
            double valL = left->GetVal();
            bool retVal = (double(left->GetVal()) < int(right->GetVal()));
            return std::shared_ptr<Value>(std::make_shared<ValueBool>(retVal));
        }
        case TinyLexer::EQUAL: {
            bool retVal = double(left->GetVal()) == double(right->GetVal());
            return std::shared_ptr<Value>(std::make_shared<ValueBool>(retVal));
        }
    }
    return nullptr;
}