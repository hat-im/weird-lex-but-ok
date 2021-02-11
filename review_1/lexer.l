
%{
    #include<stdio.h>
    #include<stdlib.h>

    #include "tables.h"

    entry **SymbolTable = NULL;
    entry **ConstantTable = NULL;

    int ErrFlag = 0;
%}

global int yylval;
global int yylloc;

 /* Declarations */

letter [a-zA-Z]
digit [0-9]
whitespace [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_)*
hex [0-9a-fA-F]


 /* States */

%x PREPROCESSOR
%x MACROPREPROCESSOR
%x COMMENT
%x SLCOMMENT

%%


 /* Keywords */

"int"                               {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"short"                             {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"long"                              {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"char"                              {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"signed"                            {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"unsigned"                          {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"void"                              {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"if"                                {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"else"                              {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"for"                               {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"do"                                {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"while"                             {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"goto"                              {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"break"                             {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"continue"                          {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"main"                              {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}
"return"                            {printf("\t%-50s : T_Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"T_KEYWORD");}


 /* Constants */

[+/-]?[0][x|X]{hex}+                {printf("\t%-50s : T_Hexadecimal Constant\n", yytext); InsertEntry(ConstantTable,yytext,"T_HEX_CONSTANT");}
[+/-]?{digit}+                      {printf("\t%-50s : T_Integer Constant\n", yytext); InsertEntry(ConstantTable,yytext,"T_INT_CONSTANT");}
[+/-]?({digit}*)["."]({digit}+)     {printf("\t%-50s : T_Decimal Constant\n", yytext); InsertEntry(ConstantTable,yytext,"T_DEC_CONSTANT");}
[+/-]?({digit}+)["."]({digit}*)     {printf("\t%-50s : T_Decimal Constant\n", yytext); InsertEntry(ConstantTable,yytext,"T_DEC_CONSTANT");}
[+/-]?({digit}+)["."]({digit}*)[E/e][+/-]({digit}+) {printf("\t%-50s : T_Exponential Constant\n", yytext); InsertEntry(ConstantTable,yytext,"T_EXP_CONSTANT");}
{identifier} {
  if(strlen(yytext) <= 32)
    {
      printf("\t%-50s : T_Identifier\n", yytext);
      InsertEntry(SymbolTable,yytext,"T_IDENTIFIER");
    }
  else
  {
      printf("Error %d: T_Identifier too long,must be between 1 to 32 characters\n", yylineno);
      ErrFlag = 1;
  }
}


{digit}+({letter}|_)+               {printf("Error %d: Illegal identifier format\n", yylineno); ErrFlag = 1;}
{whitespace}                        ;


 /* Preprocessor Directives */

^"#include"                         {BEGIN PREPROCESSOR;}
<PREPROCESSOR>{whitespace}          ;
<PREPROCESSOR>"<"[^<>\n]*">"        {printf("\t%-50s : T_Preprocessor_directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>\"[^<>\n]*\"          {printf("\t%-50s : T_Preprocessor_directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>"\n"                  {printf("Error %d: Header format not allowed\n", yylineno); yylineno++; BEGIN INITIAL;ErrFlag=1;}
<PREPROCESSOR>.                     {printf("Error %d: Header format not allowed\n", yylineno); ErrFlag=1;}


 /* Macropreprocessor Directives */

^"#define"                                        {BEGIN MACROPREPROCESSOR;}
<MACROPREPROCESSOR>{whitespace}                   ;
<MACROPREPROCESSOR>({letter})({letter}|{digit})*  {printf("\t%-50s : T_Macropreprocessor_directive\n", yytext); BEGIN INITIAL;}
<MACROPREPROCESSOR>\n                             {yylineno++; BEGIN INITIAL;}
<MACROPREPROCESSOR>.                              {printf("Error %d: Invalid definition\n", yylineno); BEGIN INITIAL;ErrFlag=1;}


 /* Comments */

"/*"                                {BEGIN COMMENT;}
<COMMENT>.|{whitespace}             ;
<COMMENT>\n                         {yylineno++;}
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {printf("Error %d: Nested comments are invalid\n", yylineno); ErrFlag=1;yyterminate();}
<COMMENT><<EOF>>                    {printf("Error %d: Unterminated comments are invalid\n", yylineno);ErrFlag=1; yyterminate();}
"//"                                {BEGIN SLCOMMENT;}
<SLCOMMENT>.                        ;
<SLCOMMENT>\n                       {yylineno++; BEGIN INITIAL;}


 /* Operators */

"+"                                 {printf("\t%-50s : T_Addition_Arithmetic_Operator\n", yytext);}
"-"                                 {printf("\t%-50s : T_Subtraction_Arithmetic_Operator\n", yytext);}
"*"                                 {printf("\t%-50s : T_Multiplication_Arithmetic_Operator\n", yytext);}
"/"                                 {printf("\t%-50s : T_Division_Arithmetic_Operator\n", yytext);}
"="                                 {printf("\t%-50s : T_Assignment_Operator\n", yytext);}
"--"                                {printf("\t%-50s : T_Decrement_Operator\n", yytext);}
"++"                                {printf("\t%-50s : T_Increment_Operator\n", yytext);}
"%"                                 {printf("\t%-50s : T_Modulus_Operator\n", yytext);} 
">"                                 {printf("\t%-50s : T_GREATER\n", yytext);}
"<"                                 {printf("\t%-50s : T_LESSER\n", yytext);}
">="                                {printf("\t%-50s : T_GREATER_OR_EQUAL\n", yytext);}
"<="                                {printf("\t%-50s : T_LESSER_OR_EQUAL\n", yytext);}

"=="                                {printf("\t%-50s : T_IS_EQUAL_TO\n", yytext);}
"!="                                {printf("\t%-50s : T_NOT_EQUAL_TO\n", yytext);}    
"||"                                {printf("\t%-50s : T_OR\n", yytext);}
"&&"                                {printf("\t%-50s : T_AND\n", yytext);}
"!"                                 {printf("\t%-50s : T_NOT\n", yytext);}


 /* Strings and Characters */

\"[^\"\n]*$                         {printf("Error %d: Illegally terminated string\n", yylineno);ErrFlag=1; yyterminate();}
\"[^\"\n]*\" {
  if(yytext[yyleng-2]=='\\') {
    yyless(yyleng-1);
    yymore();
  }
  else
  {
    InsertEntry(ConstantTable,yytext,"STRING");
    printf("\t%-50s : String\n", yytext);
  }
}

\'[^\'\n]\'                         {printf("\t%-50s : T_Character\n", yytext);}


 /* Punctuators */


"["                                 {printf("\t%-50s : T_Open_Square_Bracket\n", yytext);}
"]"                                 {printf("\t%-50s : T_Closed_Square_Bracket\n", yytext);}
"{"                                 {printf("\t%-50s : T_Open_Curly_Bracket\n", yytext);}
"}"                                 {printf("\t%-50s : T_Closed_Curly_Bracket\n", yytext);}
"("                                 {printf("\t%-50s : T_Open_Round_Bracket\n", yytext);}
")"                                 {printf("\t%-50s : T_Closed_Round_Bracket\n", yytext);}
","                                 {printf("\t%-50s : T_Comma\n", yytext);}
";"                                 {printf("\t%-50s : T_Delimiter\n", yytext);}
"&"                                 {printf("\t%-50s : T_Ampersand\n",yytext);}
"()"                                {printf("\t%-50s : T_Empty_Function_Parameters\n",yytext);}
"{}"                                {printf("\t%-50s : T_Empty_Block\n",yytext);}
"[]"                                {printf("\t%-50s : T_Empty_Array\n",yytext);}
"\n"                                {yylineno++;}
.                                   {printf("Error %d: Illegal character\n", yylineno);ErrFlag=1;}


%%


int main(int argc, char *argv[])
{
  SymbolTable = CreateTable();
  ConstantTable = CreateTable();
  FILE *fh;
  if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
  yylex();

  if (ErrFlag == 0)
  {
    printf("\nPrinting Symbol Table\n" );
    Display(SymbolTable);
    printf("\n\n");
    printf("Printing Constant Table\n" );
    Display(ConstantTable);
  }

  printf("Lexical analysis finished\n");
  return 0;
}

int yywrap(){return 1;}
