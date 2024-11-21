%{
#include "parser.hpp" // Include the parser header
#include <cstdio>
#include <iostream>   // Include iostream for std::cerr and std::endl
extern FILE* yyin;    // Declare yyin to handle file input
%}

%option noyywrap c++ yylineno nounistd

DIGIT   [0-9]
ALPHA   [A-Za-z]
WSPACE  [\\ \\t\\n]

%%

"void" { return VOID_T; }
"int" { return INT_T; }
"float" { return FLOAT_T; }
"begin" { return BEGIN_T; }
"end" { return END_T; }
"if" { return IF_T; }
"then" { return THEN_T; }
"else" { return ELSE_T; }
"while" { return WHILE_T; }

{ALPHA}({ALPHA}|{DIGIT})*  { return ID_T; }
{DIGIT}+  { return NUM_INT_T; }
{DIGIT}+"."{DIGIT}+ { return NUM_REAL_T; }
"+"|"-"  { return ADDOP_T; }
"*"|"/"  { return MULOP_T; }
">"|"<"|"=="|">="|"<="  { return RELOP_T; }
"<-" { return ASSIGNOP_T; }
"&&" { return AND_T; }
"||" { return OR_T; }
"~" { return NOT_T; }
"[" { return LBRACK_T; }
"]" { return RBRACK_T; }
"," { return COMMA_T; }
"(" { return LPAREN_T; }
")" { return RPAREN_T; }

{WSPACE}+ { /* skip whitespace */ }
#.*\\n { /* skip comments */ }
<<EOF>> { return 0; }

. { std::cerr << "Unmatched character: " << yytext[0] << " on line " << yylineno << std::endl; }
%%