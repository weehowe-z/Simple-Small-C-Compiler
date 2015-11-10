%{
#include "y.tab.h"
/*extern int yylval;*/
%}

/*Regular Definations*/
DIGIT    [0-9]
INTEGER  {DIGIT}+
RATIONAL   {DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?
DELIM    [ \t]
ENDLINE  [\n]
%%

{INTEGER}	{ 
	yylval = atoi (yytext);
	return INTEGER; 
}

{RATIONAL}	{
	yylval = atof (yytext);
	return RATIONAL;
}

{DELIM}		{/*Need no actions*/}

{ENDLINE}	{ return 0; }

.	{ return yytext[0]; }/*Other lexme*/


%%