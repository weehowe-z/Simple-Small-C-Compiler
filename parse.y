%{
#include <stdio.h>
#include <queue>
#include <vector>
#include "node.h"
extern FILE *yyin;
extern FILE *yyout;
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
								pTree.fprint(yyout);
								pTree.printWidth(yyout);
								pTree.printpos(yyout);
								return 0;
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
		ID                  {
								tokenNode* idval= new tokenNode($1);
								tokenNode* id = new tokenNode("id",idval,NULL);
								tokenNode* opttag = new tokenNode("opttag",id,NULL);
								vec.push_back(opttag);
							}

	|	/*EMPTY*/			{
								tokenNode* empty = new tokenNode("epsilon");
								vec.push_back(empty);
							}	
	;

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

	|	VAR ASSIGNOP INIT	{
								tokenNode* var = vec.back();
								vec.pop_back();
								tokenNode* dec = new tokenNode("dec",var,NULL);
								vec.push_back(dec);
							}	
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
		EXP COMMA ARGS      {
								tokenNode* args = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",",NULL,args);
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = comma;							
								args = new tokenNode("args",exp,NULL);
								vec.push_back(args);
							}	

	|	EXP					{
								tokenNode* exp = vec.back();
								vec.pop_back();
								tokenNode* args = new tokenNode("args",exp,NULL);
								vec.push_back(args);
							}	
	;


%%


int main (int argc, char const *argv[]) {

	if (argc == 1){
		fprintf(stderr, "%s\n", "YACC: please write your code in the shell. input CTRL-D to exit.");
		fprintf(stderr, "%s\n", "YACC: or you can specify the source code path. \nexample --> $./a.out  inputFile outputFile\n");
		return yyparse();
	}

	else if (argc == 2){
		FILE *fin = fopen(argv[1],"r");
		if (!fin) { 
			return fprintf (stderr, "YACC: Input file %s does not exist!\n", argv[1]);
		}
		yyin = fin;
		while(!feof(yyin)){
			yyparse();
		}
		fclose(fin);
	}

	else if (argc == 3){
		FILE *fin = fopen(argv[1], "r");
		FILE *fout = fopen(argv[2],"w");
		if (!fin) {
			return fprintf (stderr, "YACC: Input file %s does not exist!\n", argv[1]);
		}
		if (!fout) {
			return fprintf (stderr, "YACC: Output file %s does not exist!\n", argv[2]);
		}
		yyin = fin;
		yyout = fout;
		while (!feof(yyin)){
			yyparse();
		}
		fclose(fin);
		fclose(fout);
	}

	else {
		fprintf(stderr, "%s\n" , "YACC: Wrong fromat.");
		fprintf(stderr, "%s\n" , "YACC: or you can specify the source code path. \nexample --> $./a.out  inputFile outputFile\n");
	}
	return 0;
}

/* Added because panther doesn't have liby.a installed. */
int yyerror (const char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
}