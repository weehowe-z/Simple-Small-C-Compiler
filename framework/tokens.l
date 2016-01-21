%{
#include "header.h"
#include "syntax_tree.h"
#include "y.tab.h"

#define printReturn(x)  return x;
#define load yylval.string = strdup(yytext);

extern char *yytext;
extern int yyval, yylineno;

int yyerror(const char* msg);
%}
%%
[ \t\v\f]+ ;
[\n] {yylineno = yylineno+1;}
"(" {load printReturn(LP)}
")" {load printReturn(RP)}
"[" {load printReturn(LB)}
"]" {load printReturn(RB)}
"{" {load printReturn(LC)}
"}" {load printReturn(RC)}
";" {load printReturn(SEMI)}
"," {load printReturn(COMMA)}
"." {load printReturn(DOT)}
"=" {load printReturn(ASSIGN)}
"&" {load printReturn(BIT_AND_OP)}
"!" {load printReturn(LOG_NOT_OP)}
"~" {load printReturn(BIT_NOT_OP)}
"-" {load printReturn(MINUS_OP)}
"+" {load printReturn(PLUS_OP)}
"*" {load printReturn(PRODUCT_OP)}
"/" {load printReturn(DIV_OP)}
"%" {load printReturn(MOD_OP)}
"<" {load printReturn(LT_OP)}
">" {load printReturn(GT_OP)}
"^" {load printReturn(BIT_XOR_OP)}
"|" {load printReturn(BIT_OR_OP)}
"+=" {load printReturn(ADD_ASSIGN)}
"-=" {load printReturn(SUB_ASSIGN)}
"*=" {load printReturn(MUL_ASSIGN)}
"/=" {load printReturn(DIV_ASSIGN)}
"&=" {load printReturn(AND_ASSIGN)}
"^=" {load printReturn(XOR_ASSIGN)}
"|=" {load printReturn(OR_ASSIGN)}
">>" {load printReturn(RIGHT_OP)}
"<<" {load printReturn(LEFT_OP)}
"++" {load printReturn(INC_OP)}
"--" {load printReturn(DEC_OP)}
"&&" {load printReturn(AND_OP)}
"||" {load printReturn(OR_OP)}
"<=" {load printReturn(LE_OP)}
">=" {load printReturn(GE_OP)}
"==" {load printReturn(EQ_OP)}
"!=" {load printReturn(NE_OP)}
"read" {load  printReturn(READ)}
"write" {load printReturn(WRITE)}
">>=" {load printReturn(RIGHT_ASSIGN)}
"<<=" {load printReturn(LEFT_ASSIGN)}
"int" {load printReturn(TYPE)}
"struct" {load printReturn(STRUCT)}
"return" {load printReturn(RETURN)}
"if" {load printReturn(IF)}
"else" {load printReturn(ELSE)}
"break" {load printReturn(BREAK)}
"continue" {load printReturn(CONT)}
"for" {load printReturn(FOR)}
[a-zA-Z_][a-zA-Z0-9_]* {load printReturn(ID)}
([0-9]*|0[xX][0-9a-fA-F]+)          { load printReturn(INT) }
. {yyerror("Error!");}
%%














