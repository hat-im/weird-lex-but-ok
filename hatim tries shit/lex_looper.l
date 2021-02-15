
%{
    #include<stdio.h>
    #include<string.h>
    #include<math.h>
    #include "y.tab.h"

    int line=1;
%}
/* Definitions */

L           [a-zA-Z]
D           [0-9]
A           {A}|{D}
W           [ \t\n]
H           [0-9a-fA-F]
E           [Ee][+-]?{D}+

identifier  (_|{L})(_|{A})*

const_int   {D}+
const_float {D}+[\.]{D}+
const_exp   {D}+[\.]{D}+[Ee]{D}+
const_str   \"(\\.|[^"\\])*\"
const_char  \'.\'

%x COMMENT
%x MULTICOMMENT
%x MACRO
%x PREPROCESSOR

%%

/* Rules */
"int"               {printf("\t%s : t_keyword");create_entry(yytext,0,)}
"short"
"long"
"char"
"signed"
"unsigned"
"void"
"if"
"else"
"for"
"do"
"while"
"switch"
"case"
"goto"
"break"
"continue"
"main"
"return"