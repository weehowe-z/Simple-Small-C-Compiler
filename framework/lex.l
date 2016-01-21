%{
#include "header.h"
#include "syntax_tree.h"
#include "y.tab.h"


extern char *yytext;
extern int yyval, yylineno;

int yyerror(const char* msg);
%}
%%

[ \t\v\f]+ 		{/*Need no actions*/}
[\n] 			{yylineno = yylineno+1;}
"(" 			{ yylval.string = strdup(yytext); return (LP);}
")" 			{ yylval.string = strdup(yytext); return (RP);}
"[" 			{ yylval.string = strdup(yytext); return (LB);}
"]" 			{ yylval.string = strdup(yytext); return (RB);}
"{" 			{ yylval.string = strdup(yytext); return (LC);}
"}" 			{ yylval.string = strdup(yytext); return (RC);}
";" 			{ yylval.string = strdup(yytext); return (SEMI);}
"," 			{ yylval.string = strdup(yytext); return (COMMA);}
"." 			{ yylval.string = strdup(yytext); return (DOT);}
"=" 			{ yylval.string = strdup(yytext); return (ASSIGN);}
"&" 			{ yylval.string = strdup(yytext); return (BIT_AND_OP);}
"!" 			{ yylval.string = strdup(yytext); return (LOG_NOT_OP);}
"~" 			{ yylval.string = strdup(yytext); return (BIT_NOT_OP);}
"-" 			{ yylval.string = strdup(yytext); return (MINUS_OP);}
"+" 			{ yylval.string = strdup(yytext); return (PLUS_OP);}
"*" 			{ yylval.string = strdup(yytext); return (PRODUCT_OP);}
"/" 			{ yylval.string = strdup(yytext); return (DIV_OP);}
"%" 			{ yylval.string = strdup(yytext); return (MOD_OP);}
"<" 			{ yylval.string = strdup(yytext); return (LT_OP);}
">" 			{ yylval.string = strdup(yytext); return (GT_OP);}
"^" 			{ yylval.string = strdup(yytext); return (BIT_XOR_OP);}
"|" 			{ yylval.string = strdup(yytext); return (BIT_OR_OP);}
"+=" 			{ yylval.string = strdup(yytext); return (ADD_ASSIGN);}
"-=" 			{ yylval.string = strdup(yytext); return (SUB_ASSIGN);}
"*="			{ yylval.string = strdup(yytext); return (MUL_ASSIGN);}
"/=" 			{ yylval.string = strdup(yytext); return (DIV_ASSIGN);}
"&=" 			{ yylval.string = strdup(yytext); return (AND_ASSIGN);}
"^=" 			{ yylval.string = strdup(yytext); return (XOR_ASSIGN);}
"|=" 			{ yylval.string = strdup(yytext); return (OR_ASSIGN);}
">>" 			{ yylval.string = strdup(yytext); return (RIGHT_OP);}
"<<" 			{ yylval.string = strdup(yytext); return (LEFT_OP);}
"++" 			{ yylval.string = strdup(yytext); return (INC_OP);}
"--" 			{ yylval.string = strdup(yytext); return (DEC_OP);}
"&&" 			{ yylval.string = strdup(yytext); return (AND_OP);}
"||" 			{ yylval.string = strdup(yytext); return (OR_OP);}
"<=" 			{ yylval.string = strdup(yytext); return (LE_OP);}
">=" 			{ yylval.string = strdup(yytext); return (GE_OP);}
"==" 			{ yylval.string = strdup(yytext); return (EQ_OP);}
"!=" 			{ yylval.string = strdup(yytext); return (NE_OP);}
"read" 			{ yylval.string = strdup(yytext); return (READ);}
"write" 		{ yylval.string = strdup(yytext); return (WRITE);}
">>=" 			{ yylval.string = strdup(yytext); return (RIGHT_ASSIGN);}
"<<=" 			{ yylval.string = strdup(yytext); return (LEFT_ASSIGN);}
"int" 			{ yylval.string = strdup(yytext); return (TYPE);}
"struct" 		{ yylval.string = strdup(yytext); return (STRUCT);}
"return" 		{ yylval.string = strdup(yytext); return (RETURN);}
"if" 			{ yylval.string = strdup(yytext); return (IF);}
"else" 			{ yylval.string = strdup(yytext); return (ELSE);}
"break" 		{ yylval.string = strdup(yytext); return (BREAK);}
"continue" 		{ yylval.string = strdup(yytext); return (CONT);}
"for" 			{ yylval.string = strdup(yytext); return (FOR);}

([0-9]*|0[xX][0-9a-fA-F]+)          { yylval.string = strdup(yytext); return (INT); }
[a-zA-Z_][a-zA-Z0-9_]* 				{ yylval.string = strdup(yytext); return (ID);}

%%


// . {yyerror("Error!");}













