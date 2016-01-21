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


{DELIM}							{/*Need no actions*/}

{PLUS}  						{yylval.token = strdup(yytext);return PLUS;}

{SEMI}							{return SEMI;}
{COMMA}							{return COMMA;}
{DOT}							{return DOT;}
if          					{return IF;}
then							{return THEN;}
else							{return ELSE;}
break							{return BREAK;}
return							{return RETURN;}
continue						{return CONT;}
for         					{return FOR;}
struct      					{return STRUCT;}
{LP}							{return LP;}
{RP}							{return RP;}
{LB}							{return LB;}
{RB}							{return RB;}
{LC}							{return LC;}
{RC}							{return RC;}

{INT}					        {yylval.string = new std::string(yytext, yyleng); return TINTEGER;}
{ID}  						 	{yylval.string = new std::string(yytext, yyleng); return TIDENTIFIER;}

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