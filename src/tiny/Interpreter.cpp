#include "antlr4-runtime.h"
#include "TinyLexer.h"
#include "TinyParser.h"
#include "Interpreter.h"
#include "Parser.h"

void Interpreter::addSource(const char* filename) {
    this->sources.push_back(filename);
}

void Interpreter::readSource(const std::string  &filename,std::string &file_contents)  {
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

int Interpreter::interpret() {
    std::string file_contents;

    for (std::string const& file: this->sources) {
        std::cout << "Interpreting file:" << file << std::endl;
        readSource(file,file_contents);

        antlr4::ANTLRInputStream input(file_contents);

        TinyLexer lexer(&input);

        antlr4::CommonTokenStream tokens(&lexer);

        /*
        tokens.fill();
		for (auto token : tokens.getTokens()) {
			std::cout << token->toString() << std::endl;
		}
        */

        TinyParser parser(&tokens);

        TinyParser::ProgContext* tree = parser.prog();
        // std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

        // pass 1: 查找所有函数定义并添加到符号表
        TinyDeclVisitor decl(file, this);
        decl.visitProg(tree);
        // symbolTable->Dump();

        // 在符号表中查找main函数
        std::shared_ptr<TinyFunction> main = nullptr;
        std::map<std::string, std::shared_ptr<Identifier>> mainIdTable;
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
    }
    return 0;
}