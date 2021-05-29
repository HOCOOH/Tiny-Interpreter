#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <exception>
#include "Interpreter.h"

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
        INT = 1,
        CHAR = 2,
        BOOL = 3
    };
    static const int EPSILON = 1e-8;
    Value(Type type, antlrcpp::Any val) : _type(type), _val(val) {} 
    Type GetType() { return _type; }
    std::string GetTypeStr() {
        switch (_type) {
            case FLOAT: return "FLOAT";
            case INT: return "INT";
            case CHAR: return "CHAR";
            case BOOL: return "BOOL";
            default: return "UNKNOWN";
        }
    }
    antlrcpp::Any GetVal() { return _val; }
    double GetValDouble() {
        switch (_type) {
            case Value::FLOAT: return _val.as<double>();
            case Value::INT: return static_cast<double>(_val.as<int>());
            case Value::CHAR: return static_cast<double>(_val.as<char>());
            case Value::BOOL: return static_cast<double>(_val.as<bool>());
            default: throw TinyException("Unknown Type: " + _type);
        }
    }
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
        switch (_type) {
            case FLOAT: std::cout << this->GetTypeStr() << "  " << _val.as<double>() << std::endl; break;
            case INT: std::cout << this->GetTypeStr() << "  " << _val.as<int>() << std::endl; break;
            case CHAR: std::cout << this->GetTypeStr() << "  " << _val.as<char>() << std::endl; break;
            case BOOL: std::cout << this->GetTypeStr() << "  " << (_val.as<bool>() ? "true" : "false") << std::endl; break;
            default: return;
        }
    }

    static std::shared_ptr<Value> BinaryCalculate(std::shared_ptr<Value> left, std::shared_ptr<Value> right, size_t op);
    
private:
    Type _type;
    antlrcpp::Any _val;

};

class Identifier {

public:
    Identifier(std::string name, std::unique_ptr<Value> value) : name(name), value(std::move(value)) {}
    std::string GetName() { return name; }
    std::string GetTypeStr() { return value->GetTypeStr(); }
    Value::Type GetType() { return value->GetType(); }
    std::shared_ptr<Value> GetValue() {
        switch (value->GetType()) {
             case Value::FLOAT: return std::make_shared<Value>(Value::FLOAT, value->GetVal().as<double>());
             case Value::INT: return std::make_shared<Value>(Value::INT, value->GetVal().as<int>());
             case Value::CHAR: return std::make_shared<Value>(Value::CHAR, value->GetVal().as<char>());
             case Value::BOOL: return std::make_shared<Value>(Value::BOOL, value->GetVal().as<bool>());
             default: return nullptr;
        }
    }

    void SetValue(std::unique_ptr<Value> valueNew) {
        if (valueNew->GetType() == value->GetType()) {
            value.reset();
            value = std::move(valueNew);
        }
        else if (valueNew->GetType() > value->GetType()) {
            double val = valueNew->GetValDouble();
            Value::Type type = value->GetType();
            value.reset();
            switch (type) {
                case Value::FLOAT: value = std::make_unique<Value>(type, val); break;
                case Value::INT: value = std::make_unique<Value>(type, static_cast<int>(val)); break;
                case Value::CHAR: value = std::make_unique<Value>(type, static_cast<char>(val)); break;
                case Value::BOOL: value = std::make_unique<Value>(type, static_cast<bool>(val)); break;
            }
        }
        else {
            throw TinyException("Bad_cast: Assign a(an) " + valueNew->GetTypeStr() + " value to a(an) " + value->GetTypeStr() + " variable");
        }
    }
    void Dump() {
        std::cout << this->GetName() << ": ";
        value->DumpWithType();
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