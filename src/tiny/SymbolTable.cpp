#include "SymbolTable.h"

std::shared_ptr<Value> Value::BinaryCalculate(std::shared_ptr<Value> left, std::shared_ptr<Value> right, size_t op) {
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
    }
    return nullptr;
}