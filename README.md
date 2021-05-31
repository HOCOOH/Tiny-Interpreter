# Tiny-Interpreter

## 项目结构

```
.
├── antlr-cpp-runtime               // antlr-C++运行环境
├── CMakeLists.txt                  // CMake 文件
├── README.md                       
├── src                             // 源代码
│   ├── antlr                           // antlr脚本
│   ├── generated                       // antlr生成的Lexer/Parser
│   ├── main.cpp                        // 主函数
│   └── tiny                            // C++源代码
├── tinysrc                         // Tiny代码测试文件
└── tools
    ├── antlr-4.9.2-complete.jar                // antlr4工具
    └── antlr4-cpp-runtime-4.9.2-source.zip     // antlr4-C++运行环境源代码
```

## 编译运行

```sh
mkdir build

cd build

cmake ../

make

./Tiny <source filename>
```

