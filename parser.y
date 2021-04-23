%{
    void yyerror(char* s);
    int yylex();
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void ins();
    void insV();
    int flag=1;
    FILE* fp;
    int T_cnt = 0, valtop = 0, lbltop = 0, L_cnt = 0;
    extern char Match_str[20];
    extern char Match_type[20];
    extern char curval[20];
    extern char cur_identifier[20];
    extern char cur_function[20];
    extern int cur_scope;
    extern int params_cnt;
    extern int funccall_params_cnt;
    void insert_symbol_table_scope(char*, int);
    void insert_symbol_table_params_cnt(char*, int);
    void remove_scope(int);
    int verify_funccall_cnt(char*, int);
    int check_arg_type(int , char* , int);
    void insert_arg_type(char*, char*, int);
    void insert_func_table(char* );
    char get_identifier_type(char* );
    struct labl {
        char value[500];
        int id;
    } val_stack[100], labl_stack[100];
    void val_push(char* );
    void TAC();
    void reassign_TAC();
    void identifier_TAC();
    void constant_TAC();
    void if_not_goto();
    void if_end_goto();
    void if_end_label();
    void iter_label();
    void iter_loop_label(); 
    void TAC_assign();
%}

%nonassoc IF ELSE
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT
%token RETURN MAIN
%token VOID
%token WHILE FOR DO 
%token BREAK
%token ENDIF
%token AUTO SWITCH CASE ENUM REG TYPEDEF EXTERN UNION CONTINUE STATIC DEFAULT GOTO VOLATILE CONST IDENTIFIER NUM_CONSTANT CHAR_CONSTANT STRING_CONSTANT


%right leftshiftAssignment rightshiftAssignment
%right xorAssignment orAssignment
%right andAssignment moduloAssignment
%right multiplicationAssignment divisionAssignment
%right additionAssignment subtractionAssignment
%right assignment
%right SIZEOF
%right negation not

%left or
%left and
%left bitOr
%left xor
%left bitAnd
%left equality inequality
%left lessthanAssignment lessthan greaterthanAssignment greaterthan
%left leftshift rightshift 
%left add subtract
%left multiplication divide modulo
%left increment decrement 

%start program

%%
program
            : declaration_list;

declaration_list
            : declaration D 

D
            : declaration_list
            | ;

declaration
            : variable_declaration 
            | function_declaration
            | structure_definition;

variable_declaration
            : type_specifier variable_declaration_list ';' {
                
            }
            | structure_declaration;

variable_declaration_list
            : variable_declaration_identifier V ;

V
            : ',' variable_declaration_list {
                $$ = $2;
            }
            | ;

variable_declaration_identifier 
            : IDENTIFIER {ins(), insert_symbol_table_scope(cur_identifier, cur_scope); val_push(cur_identifier);} vdi {
                if($3 != 127) reassign_TAC();
                char type = get_identifier_type(cur_identifier);
                if(type == 'i' && $3 == 5) $$ = 5;
                else if(type == 'c' && $3 == 6) $$ = 6;
                else if($3 != 127) {
                    puts("ERROR:  Declaration type Mismatch.\n");
                    yyerror("");
                }
            };

vdi : identifier_array_type {$$ = 127;} | assignment expression {
    $$ = $2;    
}; 

identifier_array_type
            : '[' init_params
            | ;

init_params
            : subtract NUM_CONSTANT ']' initilization {puts("ERROR: Array size negative!!"); yyerror("");}
            | NUM_CONSTANT {if(atoi(curval) == 0) {puts("ERROR: Array Size is 0!!"); yyerror("");}} ']' initilization
            | ']' string_initilization;

initilization
            : string_initilization
            | array_initialization
            | ;

type_specifier 
            : INT {$$ = 5;}| CHAR {$$ = 6;}| FLOAT {$$ = 5;}| DOUBLE 
            | LONG long_grammar 
            | SHORT short_grammar
            | UNSIGNED unsigned_grammar 
            | SIGNED signed_grammar
            | VOID ;

unsigned_grammar 
            : INT | LONG long_grammar | SHORT short_grammar | ;

signed_grammar 
            : INT | LONG long_grammar | SHORT short_grammar | ;

long_grammar 
            : INT | ;

short_grammar 
            : INT | ;

structure_definition
            : STRUCT IDENTIFIER { ins(); } '{' V1  '}' ';';

V1 : variable_declaration V1 | ;

structure_declaration 
            : STRUCT IDENTIFIER variable_declaration_list;


function_declaration
            : function_declaration_type function_declaration_param_statement;

function_declaration_type
            : type_specifier IDENTIFIER '('  { params_cnt = 0; ins(); strcpy(cur_function, cur_identifier); insert_symbol_table_scope(cur_identifier, cur_scope); insert_func_table(cur_function); fprintf(fp, "function %s:\n", cur_function);};

function_declaration_param_statement
            : params ')' statement;

params 
            : parameters_list | ;

parameters_list 
            : type_specifier {insert_arg_type(Match_type, cur_function, params_cnt);} parameters_identifier_list {insert_symbol_table_params_cnt(cur_function, params_cnt);};

parameters_identifier_list 
            : param_identifier parameters_identifier_list_breakup;

parameters_identifier_list_breakup
            : ',' parameters_list 
            | ;

param_identifier 
            : IDENTIFIER { ins(); insert_symbol_table_scope(cur_identifier, cur_scope+1); params_cnt++;} param_identifier_breakup;

param_identifier_breakup
            : '[' ']'
            | ;

statement 
            : expression_statment | compound_statement 
            | conditional_statements | iterative_statements 
            | return_statement | break_statement 
            | variable_declaration;

compound_statement 
            : {cur_scope++;} '{' statment_list '}' {remove_scope(cur_scope); cur_scope--;};

statment_list 
            : statement statment_list 
            | ;

expression_statment 
            : expression ';' 
            | ';' ;

conditional_statements 
            : IF '(' simp_ex {if_not_goto();} ')' statement {if_end_goto();} conditional_statements_breakup {if_end_label();};

conditional_statements_breakup
            : ELSE statement
            | ;

iterative_statements 
            : WHILE '(' {iter_label();} simp_ex {if_not_goto();} ')' statement {iter_loop_label();}
            | FOR '(' expression ';' {iter_label();} simp_ex {if_not_goto();}';' expression ')' statement {iter_loop_label();}
            | {iter_label();} DO statement WHILE '(' simp_ex {if_not_goto(); iter_loop_label();} ')' ';';

return_statement 
            : RETURN return_statement_breakup {
                if($2 == 5 && get_identifier_type(cur_function) == 'i') {

                } else if($2 == 6 && get_identifier_type(cur_function) == 'c') {

                } else if(!($2 == 127 && get_identifier_type(cur_function) == 'v')){
                    puts("ERROR: RETURN Type mismatch!");
                    yyerror(cur_function);
                }
            };

return_statement_breakup
            : ';' {$$ = 127;}
            | expression ';' {$$ = $1;};

break_statement 
            : BREAK ';' ;

string_initilization
            : assignment STRING_CONSTANT { insV(); };

array_initialization
            : assignment '{' array_int_declarations '}';

array_int_declarations
            : NUM_CONSTANT array_int_declarations_breakup;

array_int_declarations_breakup
            : ',' array_int_declarations 
            | ;

expression 
            : mutable expression_breakup {
                if($1 != $2) {
                    printf("ERROR: Type Mismatch.\n");
                    yyerror("");
                } else if($1 == 5) {
                    $$ = 5;
                } else if($1 == 6) {
                    $$ = 6;
                }
            }
            | simp_ex {
                $$ = $1;
            };

expression_breakup
            : assignment expression {
                reassign_TAC();
                $$ = $2;
            }
            | additionAssignment {val_push("+");} expression {
                TAC_assign();
                $$ = $2;
            }
            | subtractionAssignment {val_push("-");} expression {
                TAC_assign();
                $$ = $2;
            }
            | multiplicationAssignment {val_push("*");} expression {
                TAC_assign();
                $$ = $2;
            }
            | divisionAssignment {val_push("/");} expression {
                $$ = $2;
            }
            | moduloAssignment {val_push("/");} expression {
                TAC_assign();
                $$ = $2;
            }
            | rightshiftAssignment {val_push(">>");} expression {
                TAC_assign();
                $$ = $2;
            }
            | leftshiftAssignment {val_push("<<");} expression {
                TAC_assign();
                $$ = $2;
            }
            | xorAssignment {val_push("^");} expression {
                TAC_assign();
                $$ = $2;
            }
            | increment {val_push("+"); val_push("1");}{
                TAC_assign();
                $$ = 5;
            } 
            | decrement {val_push("-"); val_push("1");}{
                TAC_assign();
                $$  = 5;
            };

simp_ex 
            : and_expression simp_ex_breakup {
                if($1 != -1 && $2 != -1) TAC();
                $$ = $1;
            };

simp_ex_breakup 
            : or {val_push("||");} and_expression simp_ex_breakup {}| {$$ = -1;};

and_expression 
            : unary_relation_expression and_expression_breakup {
                if($2 != -1 && $1 != -1) TAC();
                $$ = $1;
            };

and_expression_breakup
            : and {val_push("&&");} unary_relation_expression and_expression_breakup
            | {$$ = -1;};

unary_relation_expression 
            : not unary_relation_expression 
            | regular_expression {
                $$ = $1;
            };

regular_expression 
            : sum_expression regular_expression_breakup {
                {
                    if($2 != -1 && $1 != -1) TAC();
                }
                if($1 == $2) {
                    $$ = $1;
                }
            };

regular_expression_breakup
            : RELOP sum_expression {
                $$ = $2;
            }
            | {$$ = -1;};

RELOP 
            : greaterthanAssignment {val_push(">=");} | lessthanAssignment {val_push("<=");} | greaterthan {val_push(">");} | lessthan {val_push("<");}| equality {val_push("==");}| inequality {val_push("!=");};

sum_expression 
            : sum_expression ADDOP term {
                TAC();
                if($1 == $3)
                    $$ = $1;
                else {
                    printf("ERROR: Type mismatch.\n");
                    yyerror("");
                }
            }
            | term {$$ = $1;};

ADDOP 
            : add {val_push("+");} | subtract {val_push("-");};

term
            : term MULOP bit_exp {
                TAC();
                if($1 == $3)
                    $$ = $1;
                else {
                    printf("ERROR: Type mismatch");
                    yyerror("");
                };
            } 
            | bit_exp {$$ = $1;};

BITOP
            : leftshift { val_push("<<");} | rightshift { val_push(">>");} | bitAnd {val_push("&");} | bitOr {val_push("|");} | xor {val_push("^");};

MULOP 
            : multiplication {val_push("*");}| divide {val_push("/");} | modulo {val_push("%");};

factor 
            : immutable {$$ = $1;}| mutable ;

bit_exp
            : bit_exp BITOP factor {
                TAC();
                if($1 == $3)
                    $$ = $1;
                else {
                    printf("ERROR: Type mismatch");
                    yyerror("");
                };
            }
            | factor {$$ = $1;}

mutable 
            : IDENTIFIER {
                val_push(cur_identifier);
                
                char type = get_identifier_type(cur_identifier);
                if(type == 'i') $$ = 5;
                if(type == 'c') $$ = 6;
            }
            | mutable mutable_breakup {
                if($2 == 5 || $1 == 5) 
                    $$ = 5;
                else 
                    printf("ERROR: Type Mismatch");
                    yyerror("");
            };

mutable_breakup
            : '[' expression ']' 
            | '.' IDENTIFIER {if( $2 == 5) $$ = 5;};

immutable 
            : '(' expression ')' {
                if($2 == 5) $$ = 5;
            }
            | call {
                if($1 == 5) $$ = 5;
            }
            | constant {
                if($1 == 5) $$ = 5;
            };

call
            : IDENTIFIER '(' {strcpy(cur_function, cur_identifier);} arguments ')' {
                char type = get_identifier_type(cur_function);
                fprintf(fp, "goto %s\n", cur_function);
                if(type == 'i') $$ = 5;
                if(type == 'c') $$ = 6;

                if(!verify_funccall_cnt(cur_function, funccall_params_cnt)) {
                    puts("ERROR: Function Call arguments count mismatch");
                    yyerror(cur_function);
                }
                char tmp[100] = {0};
                sprintf(tmp, "%d", funccall_params_cnt);
                fprintf(fp, "pop_params %s\n", tmp);
            };

arguments 
            : arguments_list | ;

arguments_list 
            : {funccall_params_cnt = 0;} expression {fprintf(fp, "push_param %s\n", val_stack[valtop].value); check_arg_type($2, cur_function, funccall_params_cnt);funccall_params_cnt++;} A;

A
            : ',' expression {fprintf(fp, "push_param %s\n", val_stack[valtop].value); check_arg_type($2, cur_function, funccall_params_cnt);;funccall_params_cnt++;} A 
            | ;

constant 
            : NUM_CONSTANT  { insV(); constant_TAC(); $$=5;} 
            | STRING_CONSTANT   { insV(); constant_TAC();} 
            | CHAR_CONSTANT{ insV(); constant_TAC(); $$=6;};

%%

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int cbracketsopen;
extern int cbracketsclose;
extern int bbracketsopen;
extern int bbracketsclose;
extern int fbracketsopen;
extern int fbracketsclose;
void insert_symbol_table_type(char *,char *);
void insert_symbol_table_value(char *, char *);
void insert_constantsTable(char *, char *);
void print_constant_table();
void print_symbol_table();
void print_func_table();
void val_push(char* str) {
    strcpy(val_stack[++valtop].value, str);
}

void if_end_label() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", labl_stack[lbltop].id);
    printf( "%s: \n" , code);
    fprintf(fp, "%s: \n", code);
    lbltop--;
}

void if_not_goto() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", L_cnt);
    printf( "if not %s goto %s\n" , val_stack[valtop].value, code);
    fprintf(fp, "if not %s goto %s\n", val_stack[valtop].value, code);
    labl_stack[++lbltop].id = L_cnt++;
}

void if_end_goto() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", L_cnt);
    printf( "goto %s\n" , code);
    fprintf(fp,  "goto %s\n" , code);
    code[0] = 'L';
    sprintf(code + 1, "%d", labl_stack[lbltop].id);
    printf( "%s: \n" , code);
    fprintf(fp, "%s: \n", code);
    labl_stack[lbltop].id = L_cnt++;
}

void iter_label() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", L_cnt);
    fprintf(fp, "%s:\n", code);
    labl_stack[++lbltop].id = L_cnt++;
}

void iter_loop_label()  {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", labl_stack[lbltop-1].id);
    fprintf(fp, "goto %s\n", code);
    sprintf(code + 1, "%d", labl_stack[lbltop].id);
    fprintf(fp, "%s: \n", code);
    lbltop -= 2;
}

void identifier_TAC()  {
    char code[100] = {0};
    strcpy(code, "T");
    sprintf(code + 1, "%d", T_cnt);
    printf( "= %s NULL %s\n" , cur_identifier, code);
    fprintf(fp, "= %s NULL %s\n" , cur_identifier, code);
    T_cnt++;
    val_push(code);
}
void constant_TAC() {
    char code[100] = {0};
    strcpy(code, "T");
    sprintf(code + 1, "%d", T_cnt);
    printf( "= %s NULL %s\n" , curval , code);
    fprintf(fp, "= %s NULL %s\n"  , curval , code);
    T_cnt++;
    val_push(code);
}

void reassign_TAC() {
    if(valtop-1 < 0) return;
    printf( "= %s NULL %s\n" , val_stack[valtop].value, val_stack[valtop-1].value);
    fprintf(fp, "= %s NULL %s\n", val_stack[valtop].value, val_stack[valtop-1].value);
    valtop -= 2;
}

void TAC() {
    char code[100] = {0};
    strcpy(code, "T");
    if(valtop-2 < 0) return;
    sprintf(code + 1, "%d", T_cnt);
    printf( "%s %s %s %s\n" , val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    fprintf(fp, "%s %s %s %s\n", val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    valtop -= 2;
    strcpy(val_stack[valtop].value, code);
    T_cnt++;
}
void TAC_assign() {
    char code[100] = {0};
    strcpy(code, "T");

    sprintf(code + 1, "%d", T_cnt);
    printf( "%s %s %s %s\n" , val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    fprintf(fp, "%s %s %s %s\n", val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    valtop -= 2;
}

int main(int argc , char **argv)
{
    fp = fopen("TAC.txt", "w");
    yyin = fopen(argv[1], "r");
    yyparse();
    if((bbracketsopen-bbracketsclose)){
        printf("ERROR: brackets error [\n");
        flag = 1;
    }
    if((fbracketsopen-fbracketsclose)){
        printf("ERROR: brackets error {\n");
        flag = 1;
    }
    if((cbracketsopen-cbracketsclose)){
        printf("ERROR: brackets error (\n");
        flag = 1;
    }


    if(flag == 0)
    {
        printf("Status: Parsing Complete - Valid\n");
        printf("SYMBOL TABLE\n");
        printf("%30s %s\n", " ", "------------");
        print_symbol_table();
        printf("\n\nCONSTANT TABLE\n");
        printf("%30s %s\n", " ", "--------------");
        print_constant_table();
        printf("%30s %s\n", " ", "--------------");
        print_func_table();
    }
    fclose(fp);
}


void yyerror(char *s)
{
    puts("=========================================================================");
    printf("Parsing Failed at line no: %d\n", yylineno);
    printf("Error: %s\n", yytext);
}

void ins()
{
    insert_symbol_table_type(Match_str,Match_type);
}

void insV()
{
    insert_symbol_table_value(Match_str,curval);
} 