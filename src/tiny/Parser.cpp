#include "Parser.h"
#include <sstream>

// function_body       -> declaration-list stmt-sequence
antlrcpp::Any TinyCodeVisitor::visitFunc_body(TinyParser::Func_bodyContext *ctx) {
    visitDecls(ctx->decls());
    return visitStmts(ctx->stmts());
    // interpreter->symbolTable->Dump();
    // return TinyBaseVisitor::visitFunc_body(ctx);
}

// declaration         -> type-specifier identifier ;
//                     |  type-specifier identifier := exp ;
antlrcpp::Any TinyCodeVisitor::visitDecl(TinyParser::DeclContext *ctx) {
    try {
        std::string type = ctx->type()->getText();
        std::string name = ctx->ID()->getText();
        // std::cout << type << " " << name << std::endl;
        if (type == "void") {  // 不允许定义void型变量
            throw TinyException("Invalid Identifier Type: " + type);
        }
        interpreter->symbolTable->AddIdentifier(name, Value::StrToType(type));

        // declaration -> type-specifier identifier := exp ;
        // initialization
        if (ctx->ASSIGN()) {
            std::shared_ptr<Identifier> id = interpreter->symbolTable->GetId(name);
            auto exp = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
            id->SetValue(exp);
        }
        return 0;
    } catch (TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    // return TinyBaseVisitor::visitDecl(ctx);
}

// stmt_sequence       -> stmt_sequence statement | statement
antlrcpp::Any TinyCodeVisitor::visitStmts(TinyParser::StmtsContext *ctx) {
    for (auto stmt : ctx->stmt()) {
        antlrcpp::Any retVal = visitStmt(stmt);
        // 判断是否有return语句执行
        if (returnFlag) {
            return retVal;
        }
    }
    return 0;
    // return TinyBaseVisitor::visitStmts(ctx);
}

// read-stmt           -> read identifier ;
antlrcpp::Any TinyCodeVisitor::visitRead_stmt(TinyParser::Read_stmtContext *ctx) {
    try {
        // 获取相应的变量
        std::string name = ctx->ID()->getText();
        std::shared_ptr<Identifier> id = interpreter->symbolTable->GetId(name);

        // 在输入流中读数据
        std::cout << "Reading Identifier " << name << ": ";
        if (id->GetType() == Value::INT) {
            int val = 0;
            std::cin >> val;
            id->SetValue(std::make_shared<Value>(Value::INT, val));
        }
        else if (id->GetType() == Value::FLOAT) {
            double val = 0.0;
            std::cin >> val;
            id->SetValue(std::make_shared<Value>(Value::FLOAT, val));
        }
        else if (id->GetType() == Value::CHAR) {
            char val = 0;
            std::cin >> val;
            id->SetValue(std::make_shared<Value>(Value::CHAR, val));
        }
        else if (id->GetType() == Value::BOOL) {
            bool val = false;
            std::cin >> val;
            id->SetValue(std::make_shared<Value>(Value::BOOL, val));
        }
        else {
            throw TinyException("Invalid Identifier Type: " + id->GetTypeStr());
        }
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    return TinyBaseVisitor::visitRead_stmt(ctx);
}

// write-stmt          -> write exp ;
antlrcpp::Any TinyCodeVisitor::visitWrite_stmt(TinyParser::Write_stmtContext *ctx) {
    auto ret = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
    ret->Dump();
    return 0;
    // return TinyBaseVisitor::visitWrite_stmt(ctx);
}

// assign-stmt         -> identifier := exp ;
antlrcpp::Any TinyCodeVisitor::visitAssign_stmt(TinyParser::Assign_stmtContext *ctx) {
    try {
        // 获取相应的变量
        std::string name = ctx->ID()->getText();
        std::shared_ptr<Identifier> id = interpreter->symbolTable->GetId(name);

        // 计算表达式并赋值
        auto exp = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
        id->SetValue(exp);
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    return TinyBaseVisitor::visitAssign_stmt(ctx);
}

// if-stmt             -> if(exp) then stmt-sequence end
//                     |  if(exp) then stmt-sequence else stmt-sequence end
antlrcpp::Any TinyCodeVisitor::visitIf_stmt(TinyParser::If_stmtContext *ctx) {
    // 检查条件
    auto cond = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
    if (cond->GetType() != Value::BOOL) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): Expected Bool Expression" << std::endl;
        exit(-1);
    }

    // if(exp) then stmt-sequence end
    if (cond->GetVal().as<bool>()) {  // 满足条件执行then语句
        return visitStmts(ctx->stmts(0));
    }
    // if(exp) then stmt-sequence else stmt-sequence end
    else if (ctx->ELSE()) {  //不满足条件执行else语句(如果有的话)
        return visitStmts(ctx->stmts(1));
    }
    return 0;
    // return TinyBaseVisitor::visitIf_stmt(ctx);
}

// repeat-stmt         -> repeat stmt-sequence until exp ;
antlrcpp::Any TinyCodeVisitor::visitRepeat_stmt(TinyParser::Repeat_stmtContext *ctx) {
    while (true) {
        visitStmts(ctx->stmts());
        auto cond = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
        if (cond->GetType() != Value::BOOL) {
            std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): Expected Bool Expression" << std::endl;
            exit(-1);
        }
        // 不满足条件退出循环
        if (cond->GetVal().as<bool>() || returnFlag) {
            return 0;
        }
    }
    // return TinyBaseVisitor::visitRepeat_stmt(ctx);
}

// call-stmt           -> function_call ;
antlrcpp::Any TinyCodeVisitor::visitCall_stmt(TinyParser::Call_stmtContext *ctx) {
    return visitFunc_call(ctx->func_call(), false);
    // return TinyBaseVisitor::visitCall_stmt(ctx);
}

// return-stmt         -> return exp ;
antlrcpp::Any TinyCodeVisitor::visitReturn_stmt(TinyParser::Return_stmtContext *ctx) {
    std::shared_ptr<Value> exp = visitExp(ctx->exp()).as<std::shared_ptr<Value>>();
    returnFlag = true;  // 设置返回标志
    return exp;
    // return TinyBaseVisitor::visitReturn_stmt(ctx);
}

// function_call       -> identifier ( arguments )
// isReturn: 是否需要返回值，用于类型检查
antlrcpp::Any TinyCodeVisitor::visitFunc_call(TinyParser::Func_callContext *ctx, bool isReturn) {
    try {
        std::string name = ctx->ID()->getText();
        if (name == "main") {
            throw TinyException("Can not call main function");
        }

        // 获取相应的函数
        auto func = interpreter->symbolTable->GetFunc(name);
        auto params = func->GetParams();

        // void返回值检查
        if (isReturn && func->GetReturnType() == Value::VOID) {
            throw TinyException("Void function has no retuan value");
        }
        // 参数个数检查
        if (params.size() != ctx->args()->arg().size()) {
            throw TinyException("Function " + name + " expect " + std::to_string(params.size()) + " parameters, but " + \
                std::to_string(ctx->args()->arg().size()) + " is provided");
        }

        // 获取函数调用的实际参数
        std::vector<std::shared_ptr<Value>> args;
        visitArgs(ctx->args(), args);

        // 新建变量表并压栈
        SymbolTable::IdTable funcIdTable;
        interpreter->symbolTable->PushIdTable(funcIdTable);

        // 将函数实参写入新的变量表
        for (int i = 0; i < params.size(); ++i) {
            interpreter->symbolTable->AddIdentifier(params[i]->GetName(), params[i]->GetType());
            
            // 赋值与类型检查
            auto id = interpreter->symbolTable->GetId(params[i]->GetName());
            id->SetValue(args[i]);
        }

        // 创建一个TinyCodeVisitor执行函数
        TinyCodeVisitor funcVisitor(filename, interpreter);
        auto retVal = funcVisitor.visitFunc_body(func->GetEntry()).as<std::shared_ptr<Value>>();

        // 执行完成后将变量表出栈
        interpreter->symbolTable->PopIdTable();

        // 返回值类型检查
        auto ret = std::make_shared<Identifier>("ret", std::make_unique<Value>(func->GetReturnType(), 0));
        ret->SetValue(retVal);

        return ret->GetValue();

    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    // return TinyBaseVisitor::visitFunc_call(ctx);
}

// arguments           -> arguments argument | argument
antlrcpp::Any TinyCodeVisitor::visitArgs(TinyParser::ArgsContext *ctx, std::vector<std::shared_ptr<Value>>& args) {
    for (int i = 0; i < ctx->arg().size(); ++i) {
        auto arg = visitArg(ctx->arg(i)).as<std::shared_ptr<Value>>();
        args.push_back(arg);
    }
    return 0;
    // return TinyBaseVisitor::visitArgs(ctx);
}

// argument            -> exp ,
antlrcpp::Any TinyCodeVisitor::visitArg(TinyParser::ArgContext *ctx) {
    return visitExp(ctx->exp());
    //return TinyBaseVisitor::visitArg(ctx);
}

// exp                 -> simple-exp comparison-op simple-exp | simple-exp
antlrcpp::Any TinyCodeVisitor::visitExp(TinyParser::ExpContext *ctx) {
    // simple-exp comparison-op simple-exp
    if (ctx->simple_exp(0) && ctx->simple_exp(1)) {
        auto left = visitSimple_exp(ctx->simple_exp(0)).as<std::shared_ptr<Value>>();
        auto right = visitSimple_exp(ctx->simple_exp(1)).as<std::shared_ptr<Value>>();
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    // simple-exp
    if (ctx->simple_exp(0)) {
        return visitSimple_exp(ctx->simple_exp(0));
    }
    return TinyBaseVisitor::visitExp(ctx);
}
// simple-exp          -> simple-exp addop term | term
antlrcpp::Any TinyCodeVisitor::visitSimple_exp(TinyParser::Simple_expContext *ctx) {
    // simple-exp addop term
    if (ctx->simple_exp()) {
        auto left = visitSimple_exp(ctx->simple_exp()).as<std::shared_ptr<Value>>();
        auto right = visitTerm(ctx->term()).as<std::shared_ptr<Value>>();
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    // term
    else {
        return visitTerm(ctx->term());
    }
    return TinyBaseVisitor::visitSimple_exp(ctx);
}

// term                -> term mulop factor | factor
antlrcpp::Any TinyCodeVisitor::visitTerm(TinyParser::TermContext *ctx) {
    // term mulop unary
    if (ctx->term()) {
        auto left = visitTerm(ctx->term()).as<std::shared_ptr<Value>>();
        auto right = visitUnary(ctx->unary()).as<std::shared_ptr<Value>>();
        return Value::BinaryCalculate(left, right, ctx->op->getType());
    }
    // unary
    else {
        return visitUnary(ctx->unary());
    }
    return TinyBaseVisitor::visitTerm(ctx);
}

// unary               -> - unary | factor
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

// factor -> ( exp ) | number | real | identifier | true | false | function_call
antlrcpp::Any TinyCodeVisitor::visitFactor(TinyParser::FactorContext *ctx) {
    // ( exp )
    if (ctx->LPAR()) {
        return visitExp(ctx->exp());
    }
    // number
    if (ctx->NUM()) {
        std::stringstream ss;
        ss << ctx->NUM()->getText();
        int val;
        ss >> val;
        return std::make_shared<Value>(Value::INT, val);
    }
    // real
    if (ctx->REAL()) {
        std::stringstream ss;
        ss << ctx->REAL()->getText();
        double val;
        ss >> val;
        return std::make_shared<Value>(Value::FLOAT, val);
    }
    // true
    if (ctx->TRUE()) {
        return std::make_shared<Value>(Value::BOOL, true);
    }
    // false
    if (ctx->FALSE()) {
        return std::make_shared<Value>(Value::BOOL, false);
    }
    // identifier
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
    // function_call
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