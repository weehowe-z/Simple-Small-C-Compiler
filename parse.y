%code requires
{
    #define YYSTYPE double
    /*Override Bison’s default YYSTYPE */
}

%{
#include <stdio.h>
extern FILE *yyin;
%}

%token
INTEGER RATIONAL SEMI COMMA DOT

%%
stmt:
		expr { printf("%g\n", $1);}
	;

expr:	
		INTEGER			{ printf("BISON Find integer: %g\n", $1);}
	|	RATIONAL		{ printf("BISON Find rational: %g\n", $1);}
	|	INTEGER	expr	{ printf("BISONex Find integer: %g\n", $1);}
	|	RATIONAL expr	{ printf("BISONex Find rational: %g\n", $1);}
	;

%%


int main (int argc, char const *argv[]) {

	if (argc == 1){
		printf("%s\n", "YACC: please write your code in the shell. input CTRL-D to exit.");
		printf("%s\n", "YACC: or you can specify the source code path. example --> $./a.out  test.in\n");
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