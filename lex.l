%option yylineno
%{
#include <stdlib.h>
#include "y.tab.h"
%}

/*Regular Definations*/
DELIM		[ \t\n]
DIGIT		[0-9]
HEXLETTER	[0-9A-Fa-f]
INT     	{DIGIT}+
HEXINT		0[X|x]{HEXLETTER}+
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
UNARYOP		!|\+\+|--|~
BINARYOP	\*|\/|%
MINUS		[-]
PLUS		[\+]
SHIFTOP		<<|>>
COMPAREOP	>|>=|<|<=
EQUALOP		==|!=
BITAND		[&]
BITXOR      [\^]
BITOR       [\|]
LOGICALAND  &&
LOGICALOR	\|\|	
BINASSIGNOP	\+=|-=|\*=|\/=|&=|\^=|\|=|<<=|>>=
%%
 

{DELIM}			{/*Need no actions*/}

{UNARYOP}  		{yylval.charValue = strdup(yytext);return UNARYOP;}
{BINARYOP}  	{yylval.charValue = strdup(yytext);return BINARYOP;}
{MINUS}  		{yylval.charValue = strdup(yytext);return MINUS;}
{PLUS}  		{yylval.charValue = strdup(yytext);return PLUS;}
{SHIFTOP}  		{yylval.charValue = strdup(yytext);return SHIFTOP;}
{COMPAREOP}  	{yylval.charValue = strdup(yytext);return COMPAREOP;}
{EQUALOP}  		{yylval.charValue = strdup(yytext);return EQUALOP;}
{BITAND}		{yylval.charValue = strdup(yytext);return BITAND;}
{BITOR}			{yylval.charValue = strdup(yytext);return BITOR;}
{BITXOR}		{yylval.charValue = strdup(yytext);return BITXOR;}
{LOGICALAND}	{yylval.charValue = strdup(yytext);return LOGICALAND;}
{LOGICALOR}		{yylval.charValue = strdup(yytext);return LOGICALOR;}
{BINASSIGNOP}	{yylval.charValue = strdup(yytext);return BINASSIGNOP;}
{ASSIGNOP}		{yylval.charValue = strdup(yytext);return ASSIGNOP;}

{SEMI}			{return SEMI;}
{COMMA}			{return COMMA;}
{DOT}			{return DOT;}
if          	{return IF;}
then			{return THEN;}
else			{return ELSE;}
break			{return BREAK;}
return			{return RETURN;}
continue		{return CONT;}
for         	{return FOR;}
struct      	{return STRUCT;}
int 			{yylval.charValue = strdup(yytext);return TYPE;}
{LP}			{return LP;}
{RP}			{return RP;}
{LB}			{return LB;}
{RB}			{return RB;}
{LC}			{return LC;}
{RC}			{return RC;}

{INT}			{yylval.intValue = atoi(yytext);return INT;}
{HEXINT}		{yylval.charValue = strdup(yytext);return HEXINT;}
{ID}			{yylval.charValue = strdup(yytext);return ID;}

%%

int yywrap() 
{ 
   return 1; 
} 

