grammar Tiny;

prog    : decls stmts;

decls   : decls decl
        | decl
        ;

decl    : type ID SEMI;

type    : INT | CHAR;

stmts   : stmts stmt
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

repeat_stmt : REPEAT stmts UNTIL exp SEMI;

assign_stmt : ID ASSIGN exp SEMI;

read_stmt   : READ ID SEMI;

write_stmt  : WRITE exp SEMI;

exp         : simple_exp op=(GT | EQUAL | LT) simple_exp 
            | simple_exp
            ;

// cmpop      : GT | EQUAL | LT;

simple_exp  : simple_exp op=(PLUS | MINUS) term
            | term
            ;

// addop       : PLUS | MINUS;

term        : term op=(MULT | DIV) unary
            | unary
            ;

// mulop       : MULT | DIV;

unary       : MINUS unary
            | factor
            ;

factor      : LPAR exp RPAR
            | NUM
            | ID
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

NUM    : [0-9]+;
ID     : [a-zA-Z]([a-zA-Z0-9])*;
WS     : [ \t\r\n]+ -> skip;
