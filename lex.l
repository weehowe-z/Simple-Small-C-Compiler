%option yylineno
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
ASSIGNOP	[=]
UNARYOP		-|!|\+\+|--|~
BINARYOP	\*|\/|%|\+|-|<<|>>|>|>=|<|<=|==|!=|&|^|\||&&|\|\||\+=|-=|\*=|\/=|&=|\^=|\|=|<<=|>>=

%%
 

{DELIM}		{/*Need no actions*/}

{UNARYOP}  	{yylval.charValue = strdup(yytext);return UNARYOP;}
{BINARYOP}  {yylval.charValue = strdup(yytext);return BINARYOP;}
{ASSIGNOP}	{return ASSIGNOP;}

{SEMI}		{return SEMI;}
{COMMA}		{return COMMA;}
{DOT}		{return DOT;}
if          {return IF;}
then		{return THEN;}
else		{return ELSE;}
break		{return BREAK;}
return		{return RETURN;}
continue	{return CONT;}
for         {return FOR;}
struct      {return STRUCT;}
int 		{yylval.charValue = strdup(yytext);return TYPE;}
{LP}		{return LP;}
{RP}		{return RP;}
{LB}		{return LB;}
{RB}		{return RB;}
{LC}		{return LC;}
{RC}		{return RC;}

{INT}		{yylval.intValue = atoi(yytext);return INT;}
{ID}		{yylval.charValue = strdup(yytext);return ID;}

%%

int yywrap() 
{ 
   return 1; 
} 

