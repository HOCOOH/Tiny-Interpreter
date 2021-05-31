#include "antlr4-runtime.h"
#include "TinyLexer.h"
#include "TinyParser.h"
#include "Interpreter.h"
#include "Parser.h"

void Interpreter::addSource(const char* filename) {
    this->sources.push_back(filename);
}

int Interpreter::interpret() {
    std::ifstream stream;
    for (std::string const& file: this->sources) {
        std::cout << "Interpreting file:" << file << std::endl;

        stream.open(file);

        // take the input and convert to the ANTLR format
        antlr4::ANTLRInputStream input(stream);

        // create a lexer that works on that input
        TinyLexer lexer(&input);

        // produce a stream of tokens using the lexer
        antlr4::CommonTokenStream tokens(&lexer);

        /*
        tokens.fill();
		for (auto token : tokens.getTokens()) {
			std::cout << token->toString() << std::endl;
		}
        */

        // create a parser that works on the stream of tokens
        TinyParser parser(&tokens);

        TinyParser::ProgContext* tree = parser.prog();
        // std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

        // pass 1: 查找所有函数定义并添加到符号表
        TinyDeclVisitor decl(file, this);
        decl.visitProg(tree);
        // symbolTable->Dump();

        // 在符号表中查找main函数
        std::shared_ptr<TinyFunction> main = nullptr;
        SymbolTable::IdTable mainIdTable;
        try {
            main = symbolTable->GetFunc("main");
            symbolTable->PushIdTable(mainIdTable);  // 将main函数的符号表压栈
            // symbolTable->idTable.push_back(idTableMain);
        } catch(TinyException& e) {
            std::cerr << "TinyERROR: " << file << ": Not find function 'main'" << std::endl;
            exit(-1);
        }

        // pass 2: 执行main函数
        TinyCodeVisitor mainVisitor(file, this);
        mainVisitor.visitFunc_body(main->GetEntry());
        // symbolTable->Dump();

        symbolTable->PopIdTable();  // 弹出main函数的符号表

        stream.close();
    }
    return 0;
}