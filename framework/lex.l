%option yylineno
%{
#include <iostream>
#include <string>
#include "node.h"
#include "parser.hpp"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
%}

%option noyywrap

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

{UNARYOP}  		{yylval.token = strdup(yytext);return UNARYOP;}
{BINARYOP}  	{yylval.token = strdup(yytext);return BINARYOP;}
{MINUS}  		{yylval.token = strdup(yytext);return MINUS;}
{PLUS}  		{yylval.token = strdup(yytext);return PLUS;}
{SHIFTOP}  		{yylval.token = strdup(yytext);return SHIFTOP;}
{COMPAREOP}  	{yylval.token = strdup(yytext);return COMPAREOP;}
{EQUALOP}  		{yylval.token = strdup(yytext);return EQUALOP;}
{BITAND}		{yylval.token = strdup(yytext);return BITAND;}
{BITOR}			{yylval.token = strdup(yytext);return BITOR;}
{BITXOR}		{yylval.token = strdup(yytext);return BITXOR;}
{LOGICALAND}	{yylval.token = strdup(yytext);return LOGICALAND;}
{LOGICALOR}		{yylval.token = strdup(yytext);return LOGICALOR;}
{BINASSIGNOP}	{yylval.token = strdup(yytext);return BINASSIGNOP;}
{ASSIGNOP}		{yylval.token = strdup(yytext);return ASSIGNOP;}

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
{LP}			{return LP;}
{RP}			{return RP;}
{LB}			{return LB;}
{RB}			{return RB;}
{LC}			{return LC;}
{RC}			{return RC;}
int 			{yylval.string = new std::string(yytext, yyleng);return TYPE;}

{INT}			{yylval.string = new std::string(yytext, yyleng); return INT;}
{ID}  			{yylval.string = new std::string(yytext, yyleng); return ID;}

%%

// [0-9]+\.[0-9]* 			    SAVE_TOKEN; return TDOUBLE;
/*.                       printf("Unknown token!\n"); yyterminate();*/
/*
"extern"                        return TOKEN(TEXTERN);
"return"				        return TOKEN(TRETURN);
[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]* 			    SAVE_TOKEN; return TDOUBLE;
[0-9]+					        SAVE_TOKEN; return TINTEGER;

"="						          return TOKEN(TEQUAL);
"=="				          	return TOKEN(TCEQ);
"!="			          		return TOKEN(TCNE);
"<"				          		return TOKEN(TCLT);
"<="	          				return TOKEN(TCLE);
">"				          		return TOKEN(TCGT);
">="					          return TOKEN(TCGE);

"("	          					return TOKEN(TLPAREN);
")"					          	return TOKEN(TRPAREN);
"{"         						return TOKEN(TLBRACE);
"}"					          	return TOKEN(TRBRACE);

"."         						return TOKEN(TDOT);
","				          		return TOKEN(TCOMMA);
*/

/*
"-"		          				return TOKEN(TMINUS);
"*"		          				return TOKEN(TMINUS);
"/"				          		return TOKEN(TDIV);
*/