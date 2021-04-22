%{
    #include<stdio.h>
    #include<string.h>    


struct symbol_table {
        char name[100];
		char type[100];        
        int valid;
    }st[500];

    struct constant_table {
        char type[100];
        char name[100];
        int valid;
    }ct[500];

    int hash_function(char *str)
	{
		int value = 0;
		for(int i = 0 ; i < strlen(str) ; i++)
		{
			value = 10*value + (str[i] - 'A');
			value = value % 501;
			while(value < 0)
				value = value + 501;
		}
		return value;
	}
	int lookup_symbolTable(char *str)
	{
		int value = hash_function(str);
		if(st[value].valid == 0)
		{
			return 0;
		}
		else if(strcmp(st[value].name,str)==0)
		{
			return 1;
		}
		else
		{
			for(int i = value + 1 ; i!=value ; i = (i+1)%501)
	    	{
	    		if(strcmp(st[i].name,str)==0)
	    		{
	    			return 1;
	    		}
	    	}
	    	return 0;
	    }
	}
	int lookup_constantTable(char *str)
	{
		int value = hash_function(str);
		if(ct[value].valid == 0)
			return 0;
		else if(strcmp(ct[value].name,str)==0)
			return 1;
		else
		{
			for(int i = value + 1 ; i!=value ; i = (i+1)%501)
			{
				if(strcmp(ct[i].name,str)==0)
				{
					return 1;
				}
			}
			return 0;
		}
	}
	void insert_symbolTable(char *str1, char *str2)
	{
		if(lookup_symbolTable(str1))
		{
		    return;
	    }
		else
		{
			int value = hash_function(str1);
			if(st[value].valid == 0)
			{
				strcpy(st[value].name,str1);
				strcpy(st[value].type,str2);
				st[value].valid = strlen(str1);
				return;
			}

			int pos = 0;

			for (int i = value + 1 ; i!=value ; i = (i+1)%501)
			{
				if(st[i].valid == 0)
				{
					pos = i;
					break;
				}
			}

			strcpy(st[pos].name,str1);
			strcpy(st[pos].type,str2);
			st[pos].valid = strlen(str1);
		}
	}
	void insert_constantsTable(char *str1, char *str2)
	{
		if(lookup_constantTable(str1))
			return;
		else
		{
			int value = hash_function(str1);
			if(ct[value].valid == 0)
			{
				strcpy(ct[value].name,str1);
				strcpy(ct[value].type,str2);
				ct[value].valid = strlen(str1);
				return;
			}

			int pos = 0;

			for (int i = value + 1 ; i!=value ; i = (i+1)%501)
			{
				if(ct[i].valid == 0)
				{
					pos = i;
					break;
				}
			}

			strcpy(ct[pos].name,str1);
			strcpy(ct[pos].type,str2);
			ct[pos].valid = strlen(str1);
		}
	}
    int cbracketsopen = 0;
    int cbracketsclose = 0;
    int bbracketsopen = 0;
    int bbracketsclose = 0;
    int fbracketsopen = 0;
    int fbracketsclose = 0;

 
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*
numerical_constants [+-]?(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*)|([0-9]+))
char_constants  [\t\n ]*((\'[a-zA-Z0-9]\')|\'\\a\'|\'\\b\'|\'\\e\'|'\\f\'|\'\\n\'|\'\\n\'|\'\\r\'|\'\\t\'|\'\\v\'|\'\\\'|\'\'\'|\'\"\'|\'\?\') 
string_constants [\t\n ]*\"(.)*\"
multiline_comment \/\*([^(\*/)]*|(\n)*)\*\/
singleline_comment \/\/(.)*
binary_operators \+|\-|\*|\/|\%
unary_operators \+\+|\-\-
relational_operators \=\=|\!\=|\>|\<|\>\=|\<\=
logical_operators \&\&|\|\||\!
bitwise_operators \&|\||\^|\<\<|\>\>
assignment_operators \+\=|\-\=|\*\=|\/\=|\%\=|\=
special_operators sizeof
special_symbols \[|\]|\{|\}|\(|\)|\,|\;
header_files #(.)*
keywords auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|volatile|const|float|short|unsigned
constants {numerical_constants}|{char_constants}|{string_constants}
operators {unary_operators}|{special_operators}|{logical_operators}|{relational_operators}|{bitwise_operators}|{binary_operators}|{assignment_operators}

%%

\n {yylineno++;}
[\n\t' ']* {
    for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') yylineno++;
    }
}

{singleline_comment} ;
{multiline_comment} {
     for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') yylineno++;
    }
}


{header_files} {printf("%s is a header declaration\n", yytext);}

{keywords} {
    printf("%s is a keyword\n", yytext);
    }
({numerical_constants}){identifier} {
  printf("In LineNo: %d, ERROR: Invalid Identifier : %s\n", yylineno, yytext); // exit(1);
}
(\")(\s|{identifier}|{numerical_constants}|{operators})* {
    printf("In LineNo: %d, ERROR: String usage error in %s\n", yylineno, yytext); // exit(1);
}

[\n\t ]*\'(\s|{identifier}|{numerical_constants}|{operators})* {
    printf("In LineNo: %d, ERROR: Character usage error: %s\n", yylineno, yytext); // exit(1);
}

(\s|{identifier}|{numerical_constants}|{operators})*\' {
    printf("In LineNo: %d, ERROR: Character usage error: %s\n", yylineno, yytext); // exit(1);
}

{identifier} {
    printf("%s is a identifier\n", yytext);
	insert_symbolTable(yytext, "Identifier");
}

{constants} {
    printf("%s is a constant\n", yytext);
	insert_constantsTable(yytext, "Constant");
	for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') yylineno++;
    }
    }
{special_symbols} {
    printf("%s is a special symbol\n", yytext);
    if(yytext[0] == '{'){
        fbracketsopen++;    
    }
    else if(yytext[0] == '}'){
        fbracketsclose++;
    }
    else if(yytext[0] == '('){
        cbracketsopen++;
    }
    else if(yytext[0] == ')'){
        cbracketsclose++;
    }
    else if(yytext[0] == '['){
        bbracketsopen++;
    }
    else if(yytext[0] == ']'){
        bbracketsclose++;
    }
    }

{unary_operators}|{special_operators}|{logical_operators}|{relational_operators}|{bitwise_operators}|{binary_operators}|{assignment_operators} {
    printf("%s is an operator\n", yytext);
    }

%%

int main(int argc, char** argv){
	if(argc < 2){
		puts("ERROR: input file unavailable");
		exit(1);
	}
    yyin = fopen(argv[1], "r");

    int i,j;

    for (j=0;j<500;j++)
    {
        st[j].valid = 0;
        ct[j].valid = 0;
    }

    yylex();
    if((bbracketsopen-bbracketsclose)){
        printf("ERROR: brackets error [");
        exit(1);
    }
    if((fbracketsopen-fbracketsclose)){
        printf("ERROR: brackets error {");
        exit(1);
    }
    if((cbracketsopen-cbracketsclose)){
        printf("ERROR: brackets error (");
        exit(1);
    }
    printf("\nSymbol Table\n");
    for (i=0;i<500;i++)
    {
        if(st[i].valid)
        {
            printf("Name : %s \t", st[i].name);
            printf("Type : %s \n", st[i].type);
        }
    }

    printf("\nConstant Table\n");
    for (int i=0;i<500;i++)
    {
        if(ct[i].valid)
        {
            printf("Name : %s \t", ct[i].name);
            printf("Type : %s \n", ct[i].type);
        }
    }
    fclose(yyin);
    return (0);
}

int yywrap(){
    return(1);
}