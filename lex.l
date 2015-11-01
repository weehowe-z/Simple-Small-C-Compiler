%{

#include <stdlib.h>
#include "y.tab.h"

%}

/*Regular Definations*/
DELIM		[ \t\n]
DIGIT		[0-9]
INT     	{DIGIT}+
ID			({LETTER}|{UNDERSCORE})({LETTER}|{DIGIT}|{UNDERSCORE})*

SEMI		[;]
COMMA		[,]
DOT			[.]
UNDERSCORE	[_]
LP			[(]
RP			[)]
LB			[[]
RB			[]]
LC			[{]
RC			[}]
LETTER		[A-Za-z]
UNARYOP		-|!|\+\+|--|~
BINARYOP	\*|\/|%|\+|-|<<|>>|>|>=|<|<=|==|!=|&|^|\||&&|\|\||\+=|-=|\*=|\/=|&=|\^=|\|=|<<=|>>=|=

%%
 

{DELIM}		{/*Need no actions*/}

{UNARYOP}  	{printf("UNARYOP%s\n", yytext);}
{BINARYOP}  {printf("BINARYOP%s\n", yytext);}
{SEMI}		{return SEMI;}
{COMMA}		{return COMMA;}
{DOT}		{return DOT;}

{INT}		{yylval = atoi(yytext);return INT;}

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

%%

int yywrap() 
{ 
   return 1; 
} 

