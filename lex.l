%{

#include <stdlib.h>
#include "y.tab.h"
%}

/*Regular Definations*/
DELIM		[ \t\n]
DIGIT		[0-9]
INTEGER		{DIGIT}+
RATIONAL	{DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?

SEMI		[;]
COMMA		[,]
DOT			[.]
LETTER		[A-Za-z]
ID			{LETTER}({LETTER}|{DIGIT})*
%%
 

{DELIM}		{/*Need no actions*/}

{INTEGER}	{
				printf( "Flex Find integer: %s (%d)\n", yytext, atoi(yytext));
				yylval = atoi(yytext);
				return INTEGER;
			}

{RATIONAL}	{
				printf( "Flex Find rational: %s (%g)\n", yytext, atof(yytext));
				yylval = atof(yytext);
				return RATIONAL;
            }

%%



int yywrap() 
{ 
   return 1; 
} 

