%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "symboltable.h"

	entry_t** symbol_table;

	int yyerror(char *msg);
%}

%token T_IDENTIFIER T_CONSTANT T_STRING_LITERAL T_SIZEOF
%token T_PTR_OP T_INC_OP T_DEC_OP T_LEFT_OP T_RIGHT_OP T_LE_OP T_GE_OP T_EQ_OP T_NE_OP
%token T_AND_OP T_OR_OP T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN T_ADD_ASSIGN
%token T_SUB_ASSIGN T_LEFT_ASSIGN T_RIGHT_ASSIGN T_AND_ASSIGN
%token T_XOR_ASSIGN T_OR_ASSIGN T_TYPE_NAME T_ENUM T_ELLIPSIS

%token T_TYPEDEF T_EXTERN T_STATIC T_AUTO T_REGISTER
%token T_CHAR T_SHORT T_INT T_LONG T_SIGNED T_UNSIGNED T_FLOAT T_DOUBLE T_CONST T_VOLATILE T_VOID
%token T_STRUCT T_UNION 

%token T_CASE T_DEFAULT T_IF T_ELSE T_SWITCH T_WHILE T_DO T_FOR T_GOTO T_CONTINUE T_BREAK T_RETURN

%start translation_unit

%nonassoc T_LOWER_THAN_ELSE
%%

primary_expression
	: T_IDENTIFIER
	| T_CONSTANT
	| T_STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' T_IDENTIFIER
	| postfix_expression T_PTR_OP T_IDENTIFIER
	| postfix_expression T_INC_OP
	| postfix_expression T_DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| T_INC_OP unary_expression
	| T_DEC_OP unary_expression
	| unary_operator cast_expression
	| T_SIZEOF unary_expression
	| T_SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression T_LEFT_OP additive_expression
	| shift_expression T_RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression T_LE_OP shift_expression
	| relational_expression T_GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression T_EQ_OP relational_expression
	| equality_expression T_NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression T_AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression T_OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| T_MUL_ASSIGN
	| T_DIV_ASSIGN
	| T_MOD_ASSIGN
	| T_ADD_ASSIGN
	| T_SUB_ASSIGN
	| T_LEFT_ASSIGN
	| T_RIGHT_ASSIGN
	| T_AND_ASSIGN
	| T_XOR_ASSIGN
	| T_OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: T_TYPEDEF
	| T_EXTERN
	| T_STATIC
	| T_AUTO
	| T_REGISTER
	;

type_specifier
	: T_VOID
	| T_CHAR
	| T_SHORT
	| T_INT
	| T_LONG
	| T_FLOAT
	| T_DOUBLE
	| T_SIGNED	
	| T_UNSIGNED	
	| struct_or_union_specifier
	| enum_specifier
	| T_TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union T_IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union T_IDENTIFIER
	;

struct_or_union
	: T_STRUCT
	| T_UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: T_ENUM '{' enumerator_list '}'
	| T_ENUM T_IDENTIFIER '{' enumerator_list '}'
	| T_ENUM T_IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: T_IDENTIFIER
	| T_IDENTIFIER '=' constant_expression
	;

type_qualifier
	: T_CONST
	| T_VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: T_IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' T_ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: T_IDENTIFIER
	| identifier_list ',' T_IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: T_IDENTIFIER ':' statement
	| T_CASE constant_expression ':' statement
	| T_DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: T_IF '(' expression ')' statement T_ELSE statement
	| T_IF '(' expression ')' statement %prec T_LOWER_THAN_ELSE
	| T_SWITCH '(' expression ')' statement
	;

iteration_statement
	: T_WHILE '(' expression ')' statement
	| T_DO statement T_WHILE '(' expression ')' ';'
	| T_FOR '(' expression_statement expression_statement ')' statement
	| T_FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: T_GOTO T_IDENTIFIER ';'
	| T_CONTINUE ';'
	| T_BREAK ';'
	| T_RETURN ';'
	| T_RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%

#include "lex.yy.c"
#include <ctype.h>

int main(int argc, char *argv[])
{
	symbol_table = create_table();

	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("\nParsing complete\n");
	}
	else
	{
			printf("\nParsing failed\n");
	}


	printf("\n\tSymbol table");
	display(symbol_table);


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
}
