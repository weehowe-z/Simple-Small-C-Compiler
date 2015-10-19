%{
#include "y.tab.h"
extern int yylval;
%}

/*Regular Definations*/
DIGIT    [0-9]
INTEGER  {DIGIT}+
NUMBER   {DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?
DELIM    [ \t]
WS       {DELIM}+
ENDLINE  [\n]  	 

%%

{INTEGER}  { yylval = atoi (yytext); 
		//printf ("lex scanned the number %d\n", yylval);
	return INTEGER; }

{WS}     {/*Need no actions*/}
{ENDLINE} { return 0; }

.	{ return yytext[0]; }

%%