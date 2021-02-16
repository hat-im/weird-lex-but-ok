%{
#include <stdio.h>
#include "y.tab.h"
#include "symboltable.h"

void count();
%}

D               [0-9]
L               [a-zA-Z]
A               {D}|{L}|_
H               [a-fA-F0-9]

%%
"int"               {count(); return(T_INT);}
"char"              {count(); return(T_CHAR);}
"double"            {count(); return(T_DOUBLE);}
"float"             {count(); return(T_FLOAT);}
"long"              {count(); return(T_LONG);}
"short"             {count(); return(T_SHORT);}
"unsigned"          {count(); return(T_UNSIGNED);}
"const"             {count(); return(T_CONST);}

"for"               {count(); return(T_FOR);}
"while"             {count(); return(T_WHILE);}
"do"                {count(); return(T_DO);}
"if"                {count(); return(T_IF);}
"else"              {count(); return(T_ELSE);}
"switch"            {count(); return(T_SWITCH);}
"case"              {count(); return(T_CASE);}
"default"           {count(); return(T_DEFAULT);}
"break"             {count(); return(T_BREAK);}
"continue"          {count(); return(T_CONTINUE);}

"/*"                {comment();}
"goto"              {count(); return(T_GOTO);}
"return"            {count(); return(T_RETURN);}
"static"            {count(); return(T_STATIC);}
"struct"            {count(); return(T_STRUCT);}
"typedef"           {count(); return(T_TYPEDEF);}
"void"              {count(); return(T_VOID);}

({L}|_){A}*       {insert(symbol_table, yytext, check_type(), count(), count()+strlen(yytext)); return(check_type());}

0[xX]{H}+           {count(); return(T_CONSTANT);}
{D}+                {count(); return(T_CONSTANT);}
L?'(\\.|[^\\'])+'   {count(); return(T_CONSTANT);}

{D}+[Ee][+-]?{D}+             {count(); return(T_CONSTANT);}
{D}*"."{D}+([Ee][+-]?{D}+)?   {count(); return(T_CONSTANT);}
{D}+"."{D}*([Ee][+-]?{D}+)?   {count(); return(T_CONSTANT);}

\"(\\.|[^\\"])*\" {count(); return(T_STRING_LITERAL);}

">>="               {count(); return(T_RIGHT_ASSIGN);}
"<<="               {count(); return(T_LEFT_ASSIGN);}
"+="                {count(); return(T_ADD_ASSIGN);}
"-="                {count(); return(T_SUB_ASSIGN);}
"*="                {count(); return(T_MUL_ASSIGN);}
"/="                {count(); return(T_DIV_ASSIGN);}
"%="                {count(); return(T_MOD_ASSIGN);}
"&="                {count(); return(T_AND_ASSIGN);}
"^="                {count(); return(T_XOR_ASSIGN);}
"|="                {count(); return(T_OR_ASSIGN);}
">>"                {count(); return(T_RIGHT_OP);}
"<<"                {count(); return(T_LEFT_OP);}
"++"                {count(); return(T_INC_OP);}
"--"                {count(); return(T_DEC_OP);}
"->"                {count(); return(T_PTR_OP);}
"&&"                {count(); return(T_AND_OP);}
"||"                {count(); return(T_OR_OP);}
"<="                {count(); return(T_LE_OP);}
">="                {count(); return(T_GE_OP);}
"=="                {count(); return(T_EQ_OP);}
"!="                {count(); return(T_NE_OP);}
";"                 {count(); return(';');}
("{"|"<%")          {count(); return('{');}
("}"|"%>")          {count(); return('}');}
","                 {count(); return(',');}
":"                 {count(); return(':');}
"="                 {count(); return('=');}
"("                 {count(); return('(');}
")"                 {count(); return(')');}
("["|"<:")          {count(); return('[');}
("]"|":>")          {count(); return(']');}
"."                 {count(); return('.');}
"&"                 {count(); return('&');}
"!"                 {count(); return('!');}
"~"                 {count(); return('~');}
"-"                 {count(); return('-');}
"+"                 {count(); return('+');}
"*"                 {count(); return('*');}
"/"                 {count(); return('/');}
"%"                 {count(); return('%');}
"<"                 {count(); return('<');}
">"                 {count(); return('>');}
"^"                 {count(); return('^');}
"|"                 {count(); return('|');}
"?"                 {count(); return('?');}

[ \t\v\n\f]        {count();}
.            {/* ignore bad characters */}

%%

yywrap()
{
    return(1);
}


comment()
{
    char c, c1;

loop:
    while ((c = input()) != '*' && c != 0)
        putchar(c);

    if ((c1 = input()) != '/' && c != 0)
    {
        unput(c1);
        goto loop;
   }

    if (c != 0)
        putchar(c1);
}


int column = 0;

int count()
{
    int i;

    for (i = 0; yytext[i] != '\0'; i++)
        if (yytext[i] == '\n')
            column = 0;
        else if (yytext[i] == '\t')
            column += 8 - (column % 8);
        else
            column++;
    return column;
}


int check_type()
{
    return(T_IDENTIFIER);
}

int main (int argc, char *argv[]){
    
    entry_t** symbol_table = create_table();
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);

    printf("Parsing finished!");
	
	display(symbol_table);
	
	return flag;
}