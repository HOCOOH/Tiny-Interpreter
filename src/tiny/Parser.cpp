#include "Parser.h"
#include <sstream>

antlrcpp::Any TinyCodeVisitor::visitFunc_body(TinyParser::Func_bodyContext *ctx) {
    visitDecls(ctx->decls());
    return visitStmts(ctx->stmts());
    // interpreter->symbolTable->Dump();
    // return TinyBaseVisitor::visitFunc_body(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitDecl(TinyParser::DeclContext *ctx) {
    try {
        std::string type = ctx->type()->getText();
        std::string name = ctx->ID()->getText();
        // std::cout << type << " " << name << std::endl;
        if (ctx->type()->INT()) {
            interpreter->symbolTable->AddIdentifier(name, Value::INT);
        }
        else if (ctx->type()->FLOAT()) { 
            interpreter->symbolTable->AddIdentifier(name, Value::FLOAT);
        }
        else if (ctx->type()->CHAR()) {
            interpreter->symbolTable->AddIdentifier(name, Value::CHAR);
        }
        else if (ctx->type()->BOOL()) {
            interpreter->symbolTable->AddIdentifier(name, Value::BOOL);
        }
        else {
            throw TinyException("Invalid Identifier Type: " + type);
        }
        // initialize
        if (ctx->ASSIGN()) {
            std::shared_ptr<Identifier> id = interpreter->symbolTable->GetId(name);
            auto exp = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
            id->SetValue(std::make_unique<Value>(exp->GetType(), exp->GetVal()));
        }
        return 0;
    } catch (TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    // return TinyBaseVisitor::visitDecl(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitStmts(TinyParser::StmtsContext *ctx) {
    for (auto stmt : ctx->stmt()) {
        antlrcpp::Any retVal = visitStmt(stmt);
        if (returnFlag) {
            return retVal;
        }
    }
    return 0;
    // return TinyBaseVisitor::visitStmts(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitRead_stmt(TinyParser::Read_stmtContext *ctx) {
    std::string name = ctx->ID()->getText();
    try {
        std::shared_ptr<Identifier> id = interpreter->symbolTable->GetId(name);
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
        std::shared_ptr<Identifier> id = interpreter->symbolTable->GetId(name);
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
        return visitStmts(ctx->stmts(0));
    }
    else if (ctx->ELSE()) {
        return visitStmts(ctx->stmts(1));
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

antlrcpp::Any TinyCodeVisitor::visitCall_stmt(TinyParser::Call_stmtContext *ctx) {
    return visitFunc_call(ctx->func_call(), false);
    // return TinyBaseVisitor::visitCall_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitReturn_stmt(TinyParser::Return_stmtContext *ctx) {
    std::shared_ptr<Value> exp = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
    returnFlag = true;
    return exp;
    // return TinyBaseVisitor::visitReturn_stmt(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitFunc_call(TinyParser::Func_callContext *ctx, bool isReturn) {
    try {
        std::string name = ctx->ID()->getText();
        if (name == "main") {
            throw TinyException("Can not call main function");
        }

        auto func = interpreter->symbolTable->GetFunc(name);
        auto params = func->GetParams();
        if (isReturn && func->GetReturnType() == Value::VOID) {
            throw TinyException("Void function has no retuan value");
        }
        // check number of arguments
        if (params.size() != ctx->args()->arg().size()) {
            throw TinyException("Function " + name + " expect " + std::to_string(params.size()) + " parameters, but " + \
                std::to_string(ctx->args()->arg().size()) + " is provided");
        }

        TinyCodeVisitor funcVisitor(filename, interpreter);
        std::vector<std::shared_ptr<Value>> args;
        // add args
        visitArgs(ctx->args(), args);

        std::map<std::string, std::shared_ptr<Identifier>> funcIdTable;
        interpreter->symbolTable->PushIdTable(funcIdTable);

        for (int i = 0; i < params.size(); ++i) {
            interpreter->symbolTable->AddIdentifier(params[i]->GetName(), params[i]->GetType());
            
            auto id = interpreter->symbolTable->GetId(params[i]->GetName());
            id->SetValue(std::make_unique<Value>(args[i]->GetType(), args[i]->GetVal()));
        }

        // execute
        auto retVal = funcVisitor.visitFunc_body(func->GetEntry()).as<std::shared_ptr<Value>>();

        // end
        interpreter->symbolTable->PopIdTable();
        return retVal;

    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    return TinyBaseVisitor::visitFunc_call(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitArgs(TinyParser::ArgsContext *ctx, std::vector<std::shared_ptr<Value>>& args) {
    try {
        for (int i = 0; i < ctx->arg().size(); ++i) {
            auto arg = visitArg(ctx->arg(i)).as<std::shared_ptr<Value>>();
            args.push_back(arg);
        }
        return 0;
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    // return TinyBaseVisitor::visitArgs(ctx);
}

antlrcpp::Any TinyCodeVisitor::visitArg(TinyParser::ArgContext *ctx) {
    return visitExp(ctx->exp());
    //return TinyBaseVisitor::visitArg(ctx);
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
            std::shared_ptr<Identifier> id = interpreter->symbolTable->GetId(name);
            return id->GetValue();
        } catch(TinyException& e) {
            std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
            exit(-1);
        }
    }
    if (ctx->func_call()) {
        return visitFunc_call(ctx->func_call(), true);
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