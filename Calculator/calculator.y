%{
#include <stdio.h>
%}

%token INTEGER
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%
statement:
		number		{ printf("The answer is %d\n", $1); }
	;

number:	
		number '+' number	{ $$ = $1 + $3; }
	|	number '-' number	{ $$ = $1 - $3; }
	|	number '*' number	{ $$ = $1 * $3; }
	|	number '/' number	{ 
		if ($3 == 0){
			yyerror ("Error, divide by zero!");
			return -1;
		}
		else
			$$ = $1 / $3;
		}
	|	INTEGER				{ $$ = $1; }
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