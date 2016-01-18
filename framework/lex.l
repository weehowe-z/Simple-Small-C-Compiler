%option yylineno
%{
#include <string>
#include "node.h"
#include "parser.hpp"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t)    (yylval.token = t)
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


[ \t\n]					        ;
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

"+"				          		return TOKEN(TPLUS);
"-"		          				return TOKEN(TMINUS);
"*"		          				return TOKEN(TMUL);
"/"				          		return TOKEN(TDIV);


%%
/*.                       printf("Unknown token!\n"); yyterminate();*/