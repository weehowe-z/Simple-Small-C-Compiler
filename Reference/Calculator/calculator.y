%code requires
{
    #define YYSTYPE double
    /*Override Bison’s default YYSTYPE */
}

%{
/*#define YYSTYPE double  /*Deafult Type is INT*/
#include <stdio.h>
#include <math.h>
#define Pi 3.1415926
%}

%token INTEGER RATIONAL
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left '^'

%%
stmt:
		expr { printf("= %.2f\n", $1); }
	;

expr:	
		INTEGER
	|	RATIONAL
	|	expr '+' expr	{ $$ = $1 + $3; }
	|	expr '-' expr	{ $$ = $1 - $3; }
	|	expr '*' expr	{ $$ = $1 * $3; }
	|	expr '/' expr	{ 
		if ($3 == 0){
			yyerror ("Error, divide by zero!");
			return -1;
		}
		else
			$$ = $1 / $3;
		}
	|	expr '^' expr	{ $$ = pow($1,$3);}
	|	'('	expr ')'		{ $$ = $2; }
	|   '-' INTEGER  %prec UMINUS { $$ = -$2; }
	;
%%
int main (void) {
	return yyparse();
	}

/* Added because panther doesn't have liby.a installed. */
int yyerror (char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
	}