grammar Tiny;

prog    : decls SEMI stmts;

decls   : decls decl
        | decl
        ;

decl    : type ID SEMI;

type    : INT | CHAR;

stmts   : stmts SEMI stmt
        | stmt
        ;

stmt    : if_stmt
        | repeat_stmt
        | assign_stmt
        | read_stmt
        | write_stmt
        ;

if_stmt : IF LPAR exp RPAR THEN stmts END
        | IF LPAR exp RPAR THEN stmts ELSE stmts END
        ;

repeat_stmt : REPEAT stmts UNTIL exp;

assign_stmt : ID ASSIGN exp;

read_stmt   : READ ID;

write_stmt  : WRITE exp;

exp         : simple_exp cmpop simple_exp 
            | simple_exp
            ;

cmpop      : GT | EQUAL | LT;

simple_exp  : simple_exp addop term
            | term
            ;

addop       : PLUS | MINUS;

term        : term mulop factor
            | factor
            ;

mulop       : MULT | DIV;

factor      : LPAR exp RPAR
            | unary
            | ID
            ;

unary       : PLUS NUM
            | MINUS NUM
            | NUM
            ;


PLUS  : '+';
MINUS : '-';
EQUAL : '=';
GT   : '>';
LT   : '<';
MULT  : '*';
DIV   : '/';
LPAR  : '(';
RPAR  : ')';
ASSIGN: ':=';
SEMI  : ';';

IF    : 'if';
THEN  : 'then';
ELSE  : 'else';
END   : 'end';
REPEAT: 'repeat';
UNTIL : 'until';
READ  : 'read';
WRITE : 'write';
CHAR  : 'char';
INT   : 'int';

WS     : [ \t\r\n]+ -> skip;
NUM    : [1-9][0-9]*;
ID     : [a-zA-Z]([a-zA-Z] | [0-9])*;
