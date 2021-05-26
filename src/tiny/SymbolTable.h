#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <exception>
#include "Compiler.h"


class Value {

public:
    enum Type {
        INT = 0,
        CHAR = 1,
        FLOAT = 2
    };
    Value(Type type) : _type(type) {} 

    std::string GetType() {
         switch (_type) {
             case INT: return "INT";
             case CHAR: return "CHAR";
             case FLOAT: return "FLOAT";
             default: return "";
         }
    }
    virtual antlrcpp::Any GetVal() = 0;
    virtual void Dump() = 0; 
    
private:
    Type _type;

};

class ValueInt : public Value {

public:
    ValueInt(int val) : Value(Value::INT), _val(val) {}
    virtual antlrcpp::Any GetVal() { return _val; }
    virtual void Dump() {
        int val = this->GetVal();
        std::cout << this->GetType() << " " << val << std::endl;
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
        std::cout << this->GetType() << " " << val << std::endl;
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
        std::cout << this->GetType() << " " << val << std::endl;
    }

private:
    double _val;
};

class Identifier {

public:
    Identifier(std::string name, std::unique_ptr<Value> value) : name(name), value(std::move(value)) {}
    std::string GetName() { return name; }
    std::string GetType() { return value->GetType(); }
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
    void AddIdentifier(std::string name, Identifier::Type idType, T val) {
        std::shared_ptr<Identifier> id = nullptr;
        if (idType == Identifier::INT) {
            id = std::make_shared<IdentifierInt>(name, idType, val);
        }
        else if (idType == Identifier::CHAR) {
            id = std::make_shared<IdentifierChar>(name, idType, val);
        }
        auto iter = idTable.find(name);
        if(iter == idTable.end())
            idTable[name] = id;
        //else
            //throw TinyException("Redeclrated Identifier");
    }

    std::shared_ptr<Identifier> Get(std::string name) {
        auto iter = idTable.find(name);
        if (iter != idTable.end())
            return std::shared_ptr<Identifier>(iter->second);
        return nullptr;
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

