#include "Function.h"

antlrcpp::Any TinyDeclVisitor::visitFunction(TinyParser::FunctionContext *ctx) {
    try {
        std::string name = ctx->ID()->getText();
        TinyParser::Func_bodyContext* body = ctx->func_body();
        Value::Type type = Value::StrToType(ctx->type()->getText());
        auto function = std::make_shared<TinyFunction>(name, body, type);
        interpreter->symbolTable->AddFunction(name, function);
        return visitParams(ctx->params(), name);
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    // return TinyBaseVisitor::visitFunction(ctx);
}

antlrcpp::Any TinyDeclVisitor::visitParams(TinyParser::ParamsContext *ctx, std::string name) {
    try {
        auto func = interpreter->symbolTable->GetFunc(name);
        for (auto param : ctx->param()) {
            Value::Type type = Value::StrToType(param->type()->getText());
            std::string name = param->ID()->getText();
            func->AddParam(type, name);
        }
        return 0;
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    // return TinyBaseVisitor::visitParams(ctx);
}
