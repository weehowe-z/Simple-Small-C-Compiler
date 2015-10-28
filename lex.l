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
UNDERSCORE	[_]
ASSIGNOP	[=]
LP			[(]
RP			[)]
LB			[[]
RB			[]]
LC			[{]
RC			[}]
LETTER		[A-Za-z]
ID			({LETTER}|{UNDERSCORE})({LETTER}|{DIGIT}|{UNDERSCORE})*
%%
 

{DELIM}		{/*Need no actions*/}

{SEMI}		{return SEMI;}
{COMMA}		{return COMMA;}
{DOT}		{return DOT;}
{ASSIGNOP}  {return ASSIGNOP;}

{INTEGER}	{yylval = atoi(yytext);return INTEGER;}

if          {return IF;}
then		{return THEN;}
else		{return ELSE;}
break		{return BREAK;}
continue	{return CONT;}
for         {return FOR;}
struct      {return STRUCT;}
int 		{return TYPE;}
{LP}		{return LP;}
{RP}		{return RP;}
{LB}		{return LB;}
{RB}		{return RB;}
{LC}		{return LC;}
{RC}		{return RC;}

{ID}		{yylval = ID;return ID;}
{RATIONAL}	{yylval = atof(yytext);return RATIONAL;}

%%

int yywrap() 
{ 
   return 1; 
} 

