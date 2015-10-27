%code requires
{
    #define YYSTYPE double
    /*Override Bison’s default YYSTYPE */
}

%{
#include <stdio.h>
extern FILE *yyin;
/*Solve warning: implicit declaration*/
int yyerror (char *msg);
int yylex();
%}

%token
ID INTEGER RATIONAL SEMI COMMA DOT
BINARYOP UNARYOP ASSIGNOP
TYPE LP RP LB RB LC RC STRUCT
RETURN IF THEN ELSE BREAK CONT FOR 

%%
PROGRAM:
		EXTDEFS
	;

EXTDEFS:
		EXTDEF EXTDEFS
	|	/*EMPTY*/
	;

EXTDEF:
		SPEC EXTVARS SEMI			{printf("BISON find new var defination\n");}
	;

EXTVARS:
		VAR
	;

SPEC:
		TYPE
	;

VAR:
		ID
	;

%%


int main (int argc, char const *argv[]) {

	if (argc == 1){
		printf("%s\n", "YACC: please write your code in the shell. input CTRL-D to exit.");
		printf("%s\n", "YACC: or you can specify the source code path. \nexample --> $./a.out  sourceFile outputFile\n");
		return yyparse();
	}
	else {
		FILE *file = fopen(argv[1], "r");
		if (!file) {
			return fprintf (stderr, "YACC: file %s does not exist!\n", argv[1]);
		}
		yyin = file;

		while (!feof(yyin)){
			yyparse();
		}
		fclose(file);
	}
}

/* Added because panther doesn't have liby.a installed. */
int yyerror (char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
}