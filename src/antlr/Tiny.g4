grammar Tiny;

prog    : functions;

functions   : function+;

function: type ID LPAR params RPAR LBRA func_body RBRA;

params  : param*;

param   : type ID COMMA;

func_body   : decls stmts;

decls   : decl*;

decl    : type ID SEMI
        | type ID ASSIGN exp SEMI
        ;

type    : INT | CHAR | FLOAT | BOOL | VOID;

stmts   : stmt*;

stmt    : if_stmt
        | repeat_stmt
        | assign_stmt
        | read_stmt
        | write_stmt
        | call_stmt
        | return_stmt
        ;

if_stmt : IF LPAR exp RPAR THEN stmts END
        | IF LPAR exp RPAR THEN stmts ELSE stmts END
        ;

repeat_stmt : REPEAT stmts UNTIL exp SEMI;

assign_stmt : ID ASSIGN exp SEMI;

read_stmt   : READ ID SEMI;

write_stmt  : WRITE exp SEMI;

call_stmt   : func_call SEMI;

return_stmt : RETURN exp SEMI;

func_call   : ID LPAR args RPAR;

args        : arg*;

arg         : exp COMMA;

exp         : simple_exp op=(GT | EQUAL | LT) simple_exp 
            | simple_exp
            ;

simple_exp  : simple_exp op=(PLUS | MINUS) term
            | term
            ;

term        : term op=(MULT | DIV) unary
            | unary
            ;

unary       : MINUS unary
            | factor
            ;

factor      : LPAR exp RPAR
            | NUM
            | REAL
            | TRUE
            | FALSE
            | ID
            | func_call
            ;


PLUS    : '+';
MINUS   : '-';
EQUAL   : '=';
GT      : '>';
LT      : '<';
MULT    : '*';
DIV     : '/';
LPAR    : '(';
RPAR    : ')';
ASSIGN  : ':=';
SEMI    : ';';
LBRA    : '{';
RBRA    : '}';
COMMA   : ',';

IF      : 'if';
THEN    : 'then';
ELSE    : 'else';
END     : 'end';
REPEAT  : 'repeat';
UNTIL   : 'until';
READ    : 'read';
WRITE   : 'write';
CHAR    : 'char';
INT     : 'int';
FLOAT   : 'float';
BOOL    : 'bool';
TRUE    : 'true';
FALSE   : 'false';
VOID    : 'void';
RETURN  : 'return';

REAL    : ([1-9][0-9]* | '0')'.'[0-9]+;
NUM     : [1-9][0-9]* | '0';
ID      : [a-zA-Z]([a-zA-Z0-9])*;
WS      : [ \t\r\n]+ -> skip;
