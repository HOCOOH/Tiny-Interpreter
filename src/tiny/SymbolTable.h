#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <exception>
#include "Compiler.h"

class TinyException : public std::exception {

public:
    TinyException(const std::string &message) : message(message) { }

    const std::string &GetMessage() const {
        return message;
    }

private:
    const std::string message;
};

class Value {

public:
    enum Type {
        FLOAT = 0,
        CHAR = 1,
        INT = 2,
        BOOL = 3
    };
    Value(Type type) : _type(type) {} 
    Type GetType() { return _type; }
    std::string GetTypeStr() {
        switch (_type) {
            case INT: return "INT";
            case CHAR: return "CHAR";
            case FLOAT: return "FLOAT";
            case BOOL: return "BOOL";
            default: return "UNKNOWN";
        }
    }
    virtual antlrcpp::Any GetVal() = 0;
    virtual void Dump() = 0;
    static std::shared_ptr<Value> BinaryCalculate(std::shared_ptr<Value> left, std::shared_ptr<Value> right, size_t op);
    
private:
    Type _type;

};

class ValueInt : public Value {

public:
    ValueInt(int val) : Value(Value::INT), _val(val) {}
    virtual antlrcpp::Any GetVal() { return _val; }
    virtual void Dump() {
        int val = this->GetVal();
        std::cout << this->GetTypeStr() << " " << val << std::endl;
    }

private:
    int _val;
};

class ValueChar : public Value {

public:
    ValueChar(char val) : Value(Value::CHAR), _val(val) {}
    virtual antlrcpp::Any GetVal() { return _val; }
    virtual void Dump() {
        char val = this->GetVal();
        std::cout << this->GetTypeStr() << " " << val << std::endl;
    }

private:
    char _val;
};

class ValueFloat : public Value {

public:
    ValueFloat(double val) : Value(Value::FLOAT), _val(val) {}
    virtual antlrcpp::Any GetVal() { return _val; }
    virtual void Dump() {
        double val = this->GetVal();
        std::cout << this->GetTypeStr() << " " << val << std::endl;
    }

private:
    double _val;
};

class ValueBool : public Value {

public:
    ValueBool(bool val) : Value(Value::BOOL), _val(val) {}
    virtual antlrcpp::Any GetVal() { return _val; }
    virtual void Dump() {
        bool val = this->GetVal();
        std::cout << this->GetTypeStr() << " " << val << std::endl;
    }

private:
    bool _val;
};

class Identifier {

public:
    Identifier(std::string name, std::unique_ptr<Value> value) : name(name), value(std::move(value)) {}
    std::string GetName() { return name; }
    std::string GetTypeStr() { return value->GetTypeStr(); }
    Value::Type GetType() { return value->GetType(); }
    antlrcpp::Any GetValue() { return value->GetVal(); }
    void SetValue(std::unique_ptr<Value> valueNew) {
        value.reset();
        value = std::move(valueNew);
    }
    void Dump() {
        std::cout << this->GetName() << ": ";
        value->Dump();
    }

private:
    std::string name;
    std::unique_ptr<Value> value;

};

class SymbolTable {

public:
    void AddIdentifier(std::string name, std::unique_ptr<Value> value) {
        auto iter = idTable.find(name);
        if(iter == idTable.end()) {
            auto id = std::make_shared<Identifier>(name, std::move(value));
            idTable[name] = id;
        }    
        else
            throw TinyException("Redeclared Identifier: " + name);
    }

    std::shared_ptr<Identifier> Get(std::string name) {
        auto iter = idTable.find(name);
        if (iter != idTable.end())
            return std::shared_ptr<Identifier>(iter->second);
        throw TinyException("Undeclared Identifier: " + name);
    }

    void Dump() {
        std::cout << "SymbolTableSize = " << idTable.size() << std::endl;
        for (auto &sym : idTable) {
            sym.second->Dump();
        }
    }

private:
    std::map<std::string, std::shared_ptr<Identifier>> idTable;

};

