#include <iostream>
#include <memory>
#include "antlr4-runtime.h"
#include "TinyLexer.h"
#include "TinyParser.h"
#include "Compiler.h"
#include "Parser.h"

void Compiler::addSource(const char* filename) {
    this->sources.push_back(filename);
}

void Compiler::readSource(const std::string  &filename,std::string &file_contents)  {
    std::string str;
    std::ifstream stream;

    stream.open(filename);
    std::string m = filename;

    /*  read the input line by line to avoid any linux/windows/mac newline problem */
    while (getline(stream, str))
    {
        // Pad the string
        if(str.size() < 80)
            str.append( 80 - str.size(), ' ');
        file_contents += str;
        file_contents.push_back('\n');
    }

    stream.close();
}
int Compiler::compile() {
    std::string file_contents;

    for (std::string const& file: this->sources) {
        std::cerr << "Compiling file:" << file << "\n";
        readSource(file,file_contents);

        antlr4::ANTLRInputStream input(file_contents);

        TinyLexer lexer(&input);

        antlr4::CommonTokenStream tokens(&lexer);

        tokens.fill();
		for (auto token : tokens.getTokens()) {
			std::cout << token->toString() << std::endl;
		}

        TinyParser parser(&tokens);
        // parser.removeErrorListeners();

        // antlr4::tree::ParseTree *tree = parser.prog();
        TinyParser::ProgContext* tree = parser.prog();
        std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

        MyTiny test;
        test.visitProg(tree);

        /*
        // First Pass parse declarations
        RpgDeclarationVisitor declarationVisitor(file, this);
        declarationVisitor.visit(tree);
        //symbolTable->dump();
        symbolTable->resolve();

        // Second  Pass parse statements
        RpgCodeVisitor codeVisitor(file, this);
        codeVisitor.visit(tree);
        //codeVisitor.dump();

        // Code Generation
        GeneratorLLVM *generator =  new GeneratorLLVM(file,emitDebugInfo);
        generator->process(symbolTable,ast);
        generator->dump();
        */

    }
    return 0;

}