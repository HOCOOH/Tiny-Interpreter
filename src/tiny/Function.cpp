#include "Function.h"
/*
function            -> type-specifier identifier ( parameters ) { function_body }
*/
antlrcpp::Any TinyDeclVisitor::visitFunction(TinyParser::FunctionContext *ctx) {
    try {
        std::string name = ctx->ID()->getText();
        TinyParser::Func_bodyContext* body = ctx->func_body();
        Value::Type type = Value::StrToType(ctx->type()->getText());

        // 创建函数并添加到符号表
        auto function = std::make_shared<TinyFunction>(name, body, type);
        interpreter->symbolTable->AddFunction(name, function);

        // 遍历形式参数信息
        return visitParams(ctx->params(), name);
    } catch(TinyException& e) {
        std::cerr << "TinyERROR: " << filename << "(" << ctx->getStart()->getLine() << "): " << e.GetMessage() << std::endl;
        exit(-1);
    }
    // return TinyBaseVisitor::visitFunction(ctx);
}

/*
parameters          -> parameters parameter | parameter
parameter           -> type-specifier identifier ,
*/
antlrcpp::Any TinyDeclVisitor::visitParams(TinyParser::ParamsContext *ctx, std::string name) {
    try {
        // 找到对应函数
        auto func = interpreter->symbolTable->GetFunc(name);
        // 遍历语法树，将形参的类型与名称添加到函数中
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
