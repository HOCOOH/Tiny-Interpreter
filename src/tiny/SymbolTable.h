#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <exception>
#include "Compiler.h"

class Identifier {

public:
    enum Type {
        INT = 0,
        CHAR = 1
    };
    Identifier(std::string name, Type idType) : _name(name), _idType(idType) {} 

    std::string GetName() { return _name; }

private:
    std::string _name;
    Type _idType;


};

class IdentifireInt : public Identifier {

public:
    IdentifireInt(std::string name, Type idType, int val): Identifier(name, idType), _val(val) {}

private:
    int _val;


};

class IdentifireChar : public Identifier {

public:
    IdentifireChar(std::string name, Type idType, char val): Identifier(name, idType), _val(val) {}

private:
    char _val;

};


class SymbolTable {

public:

    void AddIdentifier(std::shared_ptr<Identifier> id) {
    if(idTable.find(id->GetName()) != idTable.end())
        idTable[id->GetName()] = id;
    //else
      //  throw TinyException("Redeclrated Identifier");
    }

    void dump() {
        for (auto &sym : idTable) {

        }
    }



private:
    std::map<std::string, std::__shared_ptr<Identifier>> idTable;

};

