%{
#include <stdio.h>
#include <queue>
#include <vector>
#include "node.h"
extern FILE *yyin;
/*Solve warning: implicit declaration*/
int yyerror (const char *msg);
int yylex();
parseTree pTree;
vector<tokenNode*> vec;
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
%token <charValue>TYPE
%token SEMI COMMA DOT ASSIGNOP LP RP LB RB LC RC STRUCT RETURN IF THEN ELSE BREAK CONT FOR 

%nonassoc	BINARYOP 
%right		UNARYOP
%left		DOT

%start PROGRAM

%%
PROGRAM:
		EXTDEFS				{
								tokenNode* extdefs = vec.back();
								vec.pop_back();
								tokenNode* program = new tokenNode("program",extdefs,NULL);
								pTree.changeRoot(program);
								pTree.print();
								return 0;
							}
	//|	INT           {printf("haha%d\n", $1);return 0;}
	|	TEST        
	;

TEST:
		ID ID				{
								tokenNode* idval1= new tokenNode($1);
								tokenNode* idval2= new tokenNode($2);
								tokenNode* id2 = new tokenNode("id",idval2,NULL);
								tokenNode* id1 = new tokenNode("id",idval1,id2);
								tokenNode* test = new tokenNode("test",id1,NULL);
								pTree.changeRoot(test);
								pTree.print();
							}
	;

EXTDEFS:
		EXTDEF EXTDEFS		{
								tokenNode* extdefs = vec.back();
								vec.pop_back();
								tokenNode* extdef = vec.back();
								extdef->pnextSubling = extdefs;
								vec.pop_back();
								extdefs = new tokenNode("extdefs",extdef,NULL);
								vec.push_back(extdefs);
							}

	|	/*EMPTY*/			{
								tokenNode* empty = new tokenNode("epsilon");
								vec.push_back(empty);
							}	
	;

EXTDEF:
		SPEC EXTVARS SEMI   {
								tokenNode* semi= new tokenNode(";");
								tokenNode* extvars = vec.back();
								vec.pop_back();
								tokenNode* spec = vec.back();
								vec.pop_back();
								spec->pnextSubling = extvars;
								extvars->pnextSubling = semi;
								tokenNode* extdef = new tokenNode("extdef",spec,NULL);
								vec.push_back(extdef);

							}
	|	SPEC FUNC STMTBLOCK
	;

EXTVARS:
		DEC             	{
								tokenNode* dec = vec.back();
								vec.pop_back();
								tokenNode* extvars = new tokenNode("extvars",dec,NULL);
								vec.push_back(extvars);
							}

	|	DEC COMMA EXTVARS
	|	/*EMPTY*/
	;

SPEC:
		TYPE            	{
								tokenNode* type = new tokenNode($1);
								tokenNode* spec = new tokenNode("spec",type,NULL);
								vec.push_back(spec);
							}
	|	STSPEC
	;

STSPEC:
		STRUCT OPTTAG LC DEFS RC
	|	STRUCT ID

OPTTAG:
		ID
	|	/*EMPTY*/

VAR:
		ID              	{
								tokenNode* idval= new tokenNode($1);
								tokenNode* id = new tokenNode("id",idval,NULL);
								tokenNode* var = new tokenNode("var",id,NULL);
								vec.push_back(var);
							}
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
		VAR					{
								tokenNode* var = vec.back();
								vec.pop_back();
								tokenNode* dec = new tokenNode("dec",var,NULL);
								vec.push_back(dec);
							}		
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