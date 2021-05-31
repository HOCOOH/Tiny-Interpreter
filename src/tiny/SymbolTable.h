#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <exception>
#include <vector>
#include "Interpreter.h"

/*
Tiny异常，用于错误处理
*/
class TinyException : public std::exception {

public:
    TinyException(const std::string &message) : message(message) { }

    const std::string &GetMessage() const {
        return message;
    }

private:
    const std::string message;
};

/*
Tiny中的数值类
*/
class Value {

public:
    // 数据类型
    enum Type {
        VOID = -1,  // function return value only
        FLOAT = 0,
        INT = 1,
        CHAR = 2,
        BOOL = 3
    };
    static const int EPSILON = 1e-8;

    Value(Type type, antlrcpp::Any val) : _type(type), _val(val) {} 
    Type GetType() { return _type; }
    std::string GetTypeStr() { return Value::TypeToStr(_type); }
    antlrcpp::Any GetVal() { return _val; }

    /* 打印信息 */
    void Dump() {
        switch (_type) {
            case FLOAT: std::cout << _val.as<double>() << std::endl; break;
            case INT: std::cout << _val.as<int>() << std::endl; break;
            case CHAR: std::cout << _val.as<char>() << std::endl; break;
            case BOOL: std::cout << (_val.as<bool>() ? "true" : "false") << std::endl; break;
            default: return;
        }
    }
    void DumpWithType() {
        std::cout << this->GetTypeStr() << "  ";
        this->Dump();
    }

    /* 返回double类型的数值 */
    double GetValDouble() {
        switch (_type) {
            case Value::FLOAT: return _val.as<double>();
            case Value::INT: return static_cast<double>(_val.as<int>());
            case Value::CHAR: return static_cast<double>(_val.as<char>());
            case Value::BOOL: return static_cast<double>(_val.as<bool>());
            default: throw TinyException("Invalid Type: " + _type);
        }
    }

    /* 数据类型: 字符串转换为枚举 */
    static Type StrToType(std::string typeStr) {
        if (typeStr == "int")
            return Type::INT;
        if (typeStr == "float")
            return Type::FLOAT;
        if (typeStr == "char")
            return Type::CHAR;
        if (typeStr == "bool")
            return Type::BOOL;
        if (typeStr == "void")  
            return Type::VOID;
        throw TinyException("Invalid Type: " + typeStr);
    }
    /* 数据类型: 枚举转换为字符串 */
    static std::string TypeToStr(Type type) {
        switch (type) {
            case FLOAT: return "FLOAT";
            case INT: return "INT";
            case CHAR: return "CHAR";
            case BOOL: return "BOOL";
            default: return "UNKNOWN";
        }
    }

    /*
    进行两个数的二元运算
    left: 操作数1
    right: 操作数2
    op: 运算符(定义在TinyLexer中的枚举类型)
    */
    static std::shared_ptr<Value> BinaryCalculate(std::shared_ptr<Value> left, std::shared_ptr<Value> right, size_t op);
    
private:
    Type _type;             // 数据类型
    antlrcpp::Any _val;     // 数值

};

/*
变量类
*/
class Identifier {

public:
    Identifier(std::string name, std::unique_ptr<Value> val) : name(name), value(std::move(val)) {}
    Identifier(std::string name, std::shared_ptr<Value> val) : name(name) {
        value = std::make_unique<Value>(val->GetType(), val->GetVal());
    }

    std::string GetName() { return name; }
    Value::Type GetType() { return value->GetType(); }
    std::string GetTypeStr() { return value->GetTypeStr(); }
    std::shared_ptr<Value> GetValue() {
        switch (value->GetType()) {
            case Value::FLOAT: return std::make_shared<Value>(Value::FLOAT, value->GetVal().as<double>());
            case Value::INT: return std::make_shared<Value>(Value::INT, value->GetVal().as<int>());
            case Value::CHAR: return std::make_shared<Value>(Value::CHAR, value->GetVal().as<char>());
            case Value::BOOL: return std::make_shared<Value>(Value::BOOL, value->GetVal().as<bool>());
            default: return nullptr;
        }
    }

    /* 更新变量的值 */
    void SetValue(std::shared_ptr<Value> valueNew) {
        // 相同类型直接赋值
        if (valueNew->GetType() == value->GetType()) {
            value.reset();
            value = std::make_unique<Value>(valueNew->GetType(), valueNew->GetVal());
        }
        // 单向赋值
        else if (valueNew->GetType() > value->GetType()) {
            double val = valueNew->GetValDouble();
            Value::Type type = value->GetType();
            value.reset();
            switch (type) {
                case Value::FLOAT: value = std::make_unique<Value>(type, val); break;
                case Value::INT: value = std::make_unique<Value>(type, static_cast<int>(val)); break;
                case Value::CHAR: value = std::make_unique<Value>(type, static_cast<char>(val)); break;
                case Value::BOOL: value = std::make_unique<Value>(type, static_cast<bool>(val)); break;
                default: throw TinyException("Invalid Identifier Type: " + Value::TypeToStr(type));
            }
        }
        else {
            throw TinyException("Bad_cast: " + valueNew->GetTypeStr() + " to " + value->GetTypeStr());
        }
    }

    void Dump() {
        std::cout << this->GetName() << ": ";
        value->DumpWithType();
    }
    void DumpWithoutVal() {
        std::cout << this->GetTypeStr() << " " << this->GetName() << std::endl;
    }

private:
    std::string name;               // 变量名
    std::unique_ptr<Value> value;   // 值

};

/*
函数类
*/
class TinyFunction {

public:
    TinyFunction(std::string name, TinyParser::Func_bodyContext* entry, Value::Type returnType) : \
        name(name), entry(entry), returnType(returnType) {}

    std::string GetName() { return name; }
    Value::Type GetReturnType() { return returnType; }
    TinyParser::Func_bodyContext* GetEntry() { return entry; }
    const std::vector<std::shared_ptr<Identifier>>& GetParams() { return params; }

    /* 添加函数形式参数 */
    void AddParam(Value::Type type, std::string name) {
        // 查找有无重复的参数
        for (auto param : params) {
            if (param->GetName() == name) {
                throw TinyException("Redeclared Parameter: " + name);
                return;
            }
        }
        auto val = std::make_unique<Value>(type, 0);
        auto param = std::make_shared<Identifier>(name, std::move(val));
        params.push_back(param);
    }

    void Dump() {
        std::cout << Value::TypeToStr(returnType) << " " << name << ": parameters: " << std::endl;
        for (auto param : params) {
            param->DumpWithoutVal();
        }
    }

private:
    std::string name;                                   // 函数名
    TinyParser::Func_bodyContext* entry;                // 函数入口(语法树中的节点)
    Value::Type returnType;                             // 返回值类型
    std::vector<std::shared_ptr<Identifier>> params;    // 形参表

};

/*
符号表类
*/
class SymbolTable {

public:
    // 变量表
    typedef std::map<std::string, std::shared_ptr<Identifier>> IdTable;
    // 函数表
    typedef std::map<std::string, std::shared_ptr<TinyFunction>> FuncTable;

    /* 新建变量 */
    void AddIdentifier(std::string name, Value::Type type) {
        auto iter = idTableStack.back().find(name);
        if(iter == idTableStack.back().end()) {
            std::unique_ptr<Value> value = nullptr;
            switch (type) {
                case Value::FLOAT: value = std::make_unique<Value>(type, 0.0);
                case Value::INT: value = std::make_unique<Value>(type, 0);
                case Value::CHAR: value = std::make_unique<Value>(type, char(0));
                case Value::BOOL: value = std::make_unique<Value>(type, false);
            }
            auto id = std::make_shared<Identifier>(name, std::move(value));
            idTableStack.back()[name] = id;
        }    
        else
            throw TinyException("Redeclared Identifier: " + name);
    }

    /* 根据变量名查找变量 */
    std::shared_ptr<Identifier> GetId(std::string name) {
        auto iter = idTableStack.back().find(name);
        if (iter != idTableStack.back().end())
            return std::shared_ptr<Identifier>(iter->second);
        throw TinyException("Undeclared Identifier: " + name);
    }

    /* 新建函数 */
    void AddFunction(std::string name, std::shared_ptr<TinyFunction> function) {
        auto iter = funcTable.find(name);
        if(iter == funcTable.end()) {
            funcTable[name] = function;
        }    
        else
            throw TinyException("Redeclared Function: " + name);
    }

    /* 根据函数名查找函数 */
    std::shared_ptr<TinyFunction> GetFunc(std::string name) {
        auto iter = funcTable.find(name);
        if (iter != funcTable.end())
            return std::shared_ptr<TinyFunction>(iter->second);
        throw TinyException("Undeclared Function: " + name);
    }

    /* 变量表压栈 */
    void PushIdTable(IdTable& ids) {
        idTableStack.push_back(ids);
    }

    /* 变量表出栈 */
    void PopIdTable() {
        idTableStack.pop_back();
    }

    void Dump() {
        std::cout << "\nidTableSize = " << idTableStack.back().size() << std::endl;
        for (auto &sym : idTableStack.back()) {
            sym.second->Dump();
        }
        std::cout << "\nfuncTableSize = " << funcTable.size() << std::endl;
        for (auto &sym : funcTable) {
            sym.second->Dump();
        }
    }


private:
    /*
    变量表栈为存储变量表的栈结构，栈中的每个元素为一个函数执行时的变量表(std::map<std::string, std::shared_ptr<Identifier>>)
    当某个函数被调用时，将其变量表压栈；当某个函数返回时，将其变量表出栈。
    只能访问栈顶的变量表(属于正在执行的函数)
    变量表与函数表均为std::map，通过唯一的名称索引相应的变量/函数地址
    */
    std::vector<IdTable> idTableStack;      // 变量表栈
    FuncTable funcTable;                    // 函数表

};