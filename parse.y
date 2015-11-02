%{
#include <stdio.h>
#include "node.h"
extern FILE *yyin;
/*Solve warning: implicit declaration*/
int yyerror (const char *msg);
int yylex();
%}

%union
{ 
     int intValue; /* integer value */ 
     char* charValue; /* string value */ 
};

%token <intValue>INT    /*bind the yylval type*/
%token <charValue>ID
%token <charValue>BINARYOP
%token <charValue>UNARYOP
%token SEMI COMMA DOT ASSIGNOP TYPE LP RP LB RB LC RC STRUCT RETURN IF THEN ELSE BREAK CONT FOR 

%nonassoc	BINARYOP 
%right		UNARYOP
%left		DOT

%start PROGRAM

%%
PROGRAM:
		EXTDEFS
	|	INT           {printf("haha%d\n", $1);return 0;}
	|	TEST
	;

TEST:
		ID ID				{
								tokenNode* idval1= new tokenNode($1);
								tokenNode* idval2= new tokenNode($2);
								tokenNode* id2 = new tokenNode("id",idval2,NULL);
								tokenNode* id1 = new tokenNode("id",idval1,id2);
								tokenNode* test = new tokenNode("test",id1,NULL);
								parseTree p(test);
								p.print();
							}
	;

EXTDEFS:
		EXTDEF EXTDEFS
	|	/*EMPTY*/
	;

EXTDEF:
		SPEC EXTVARS SEMI
	|	SPEC FUNC STMTBLOCK
	;

EXTVARS:
		DEC
	|	DEC COMMA EXTVARS
	|	/*EMPTY*/
	;

SPEC:
		TYPE
	|	STSPEC
	;

STSPEC:
		STRUCT OPTTAG LC DEFS RC
	|	STRUCT ID

OPTTAG:
		ID
	|	/*EMPTY*/

VAR:
		ID
	|	VAR LB INT RB
	;

FUNC:
		ID LP PARAS RP
	;

PARAS:
		PARA COMMA PARAS
	|	PARA
	;

PARA:
		SPEC VAR
	;

STMTBLOCK:
		LC DEFS STMTS RC
	;

STMTS:
		STMT STMTS
	|	/*EMPTY*/
	;

STMT:
		EXP SEMI
	|	STMTBLOCK
	|	RETURN EXP SEMI
	|	IF LP EXP RP STMT STMT /*there is a problem*/
	|	FOR LP EXP SEMI EXP SEMI EXP RP STMT
	|	CONT SEMI
	|	BREAK SEMI
	;

DEFS:
		DEF DEFS
	|	/*EMPTY*/
	;

DEF:
		SPEC DECS SEMI
	;

DECS:
		DEC COMMA DECS
	|	DEC
	;

DEC:
		VAR
	|	VAR ASSIGNOP INIT
	;

INIT:
		EXP
	|	LC ARGS RC
	;

EXP:
		LP EXP RP
	|	ID LP ARGS RP
	|	ID ARRS
	|	EXP DOT ID /*what if x.length()?*/
	|	INT
	|	UNARYOP EXP
	|	EXP BINARYOP EXP
	|	/*EMPTY*/
	;

ARRS:
		LB EXP RB ARRS
	|	/*EMPTY*/
	;

ARGS:
		EXP COMMA ARGS
	|	EXP
	;


%%


int main (int argc, char const *argv[]) {

	if (argc == 1){
		printf("%s\n", "YACC: please write your code in the shell. input CTRL-D to exit.");
		printf("%s\n", "YACC: or you can specify the source code path. \nexample --> $./a.out  sourceFile outputFile\n");
		return yyparse();
	}
	else {
		FILE *file = fopen(argv[1], "r");
		if (!file) {
			return fprintf (stderr, "YACC: file %s does not exist!\n", argv[1]);
		}
		yyin = file;

		while (!feof(yyin)){
			yyparse();
		}
		fclose(file);
	}
}

/* Added because panther doesn't have liby.a installed. */
int yyerror (const char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
}