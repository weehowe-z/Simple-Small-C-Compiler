%{
/* 
 * Usage: (1) $ flex Lexical.lex
 *        (2) $ g++ lex.yy.c -l fl
 *        (3) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 */
#include <math.h>
#include <stdlib.h>
//#include "y.tab.h"
%}
	int num_lines = 0, num_chars = 0;

/*Regular Definations*/
DELIM    [ \t\n]
WS       {DELIM}+
DIGIT    [0-9]
LETTER   [A-Za-z]
ID       {LETTER}({LETTER}|{DIGIT})*
NUMBER   {DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?

%%
\n	{++num_lines; ++num_chars;}
.	{++num_chars;}



{WS}     {/*Need no actions*/}

{DIGIT}+	{
				printf( "An integer: %s (%d)\n", yytext,
				atoi( yytext ) );
			}

{NUMBER}	{
				printf( "A NUMBER: %s (%g)\n", yytext,
                atof( yytext ) );
            }

if|then|begin|end|procedure|function        {
                     printf( "A keyword: %s\n", yytext );
                     }
   


%%

int main(int argc,char *argv[])
{
  yylex();
  //printf("\n# total lines = %d\ttotal chars = %d\n", num_lines, num_chars);
  fflush(yyout);
  return 0;
}
