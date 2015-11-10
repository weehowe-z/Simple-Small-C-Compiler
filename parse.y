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
								//pTree.fprint(yyout);
								//pTree.printWidth(yyout);
								//pTree.printpos(yyout);
								pTree.printQueue(yyout);
								return 0;
							}
	;

EXTDEFS:
		EXTDEF EXTDEFS		{
								cout<<"deal with extdefs -> extdef extdefs\n";
								tokenNode* extdefs = vec.back();
								vec.pop_back();
								tokenNode* extdef = vec.back();
								extdef->pnextSubling = extdefs;
								vec.pop_back();
								extdefs = new tokenNode("extdefs",extdef,NULL);
								vec.push_back(extdefs);
							}

	|	/*EMPTY*/			{
								cout<<"deal with extdefs -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* extdefs = new tokenNode("extdefs",empty,NULL);
								vec.push_back(extdefs);
							}	
	;

EXTDEF:
		SPEC EXTVARS SEMI   {
								cout<<"deal with extdef -> spec extvars semi\n";
								tokenNode* semi= new tokenNode(";");
								tokenNode* extvars = vec.back();
								vec.pop_back();
								tokenNode* spec = vec.back();
								vec.pop_back();
								extvars->pnextSubling = semi;
								spec->pnextSubling = extvars;
								tokenNode* extdef = new tokenNode("extdef",spec,NULL);
								vec.push_back(extdef);

							}

	|	SPEC FUNC STMTBLOCK	{
								cout<<"deal with extdef -> spec func stmtblock\n";
								tokenNode* stmtblock= vec.back();
								vec.pop_back();
								tokenNode* func = vec.back();
								vec.pop_back();
								tokenNode* spec = vec.back();
								vec.pop_back();
								func->pnextSubling = stmtblock;
								spec->pnextSubling = func;
								tokenNode* extdef = new tokenNode("extdef",spec,NULL);
								vec.push_back(extdef);	
							}
	;

EXTVARS:
		DEC             	{
								cout<<"deal with extvars -> dec\n";
								tokenNode* dec = vec.back();
								vec.pop_back();
								tokenNode* extvars = new tokenNode("extvars",dec,NULL);
								vec.push_back(extvars);
							}

	|	DEC COMMA EXTVARS   {
								cout<<"deal with extvars -> dec comma extvars\n";
								tokenNode* extvars = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",");
								tokenNode* dec = vec.back();
								vec.pop_back();
								dec->pnextSubling = comma;
								comma->pnextSubling = extvars;
								extvars = new tokenNode("extvars",dec,NULL);
								vec.push_back(extvars);
							}

	|	/*EMPTY*/			{
								cout<<"deal with extvars -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* extvars = new tokenNode("extvars",empty,NULL);
								vec.push_back(extvars);
							}
	;

SPEC:
		TYPE            	{
								cout<<"deal with spec -> type\n";
								tokenNode* type = new tokenNode($1);
								tokenNode* spec = new tokenNode("spec",type,NULL);
								vec.push_back(spec);
							}

	|	STSPEC				{
								cout<<"deal with spec -> stspec\n";
								tokenNode* stspec = vec.back();
								vec.pop_back();
								tokenNode* spec = new tokenNode("spec",stspec,NULL);
								vec.push_back(spec);
							}
	;

STSPEC:
		STRUCT OPTTAG LC DEFS RC	{
										cout<<"deal with stspec -> struct opttag lc defs rc\n";
										tokenNode* rc = new tokenNode("}");
										tokenNode* defs = vec.back();
										vec.pop_back();
										tokenNode* lc = new tokenNode("{");
										tokenNode* opttag = vec.back();
										vec.pop_back();
										tokenNode* structToken = vec.back();
										vec.pop_back();
										structToken->pnextSubling = opttag;
										opttag->pnextSubling = lc;
										lc->pnextSubling = defs;
										defs->pnextSubling = rc;
										tokenNode* stspec = new tokenNode("stspec",structToken,NULL);
										vec.push_back(stspec);
									}

	|	STRUCT ID           		{
										cout<<"deal with stspec -> struct id\n";					
										tokenNode* idval= new tokenNode($2);
										tokenNode* id = new tokenNode("id",idval,NULL);
										tokenNode* structToken = new tokenNode("struct",NULL,id);
										tokenNode* stspec = new tokenNode("stspec",structToken,NULL);
										vec.push_back(stspec);										
									}

OPTTAG:
	ID                  			{
										cout<<"deal with opttag -> id\n";
										tokenNode* idval= new tokenNode($1);
										tokenNode* id = new tokenNode("id",idval,NULL);
										tokenNode* opttag = new tokenNode("opttag",id,NULL);
										vec.push_back(opttag);
									}

	|	/*EMPTY*/					{
										cout<<"deal with opttag -> empty\n";
										tokenNode* empty = new tokenNode("ϵ");
										tokenNode* opttag = new tokenNode("opttag",empty,NULL);
										vec.push_back(opttag);
									}	
	;

VAR:
		ID              			{
										cout<<"deal with var -> id\n";
										tokenNode* idval= new tokenNode($1);
										tokenNode* id = new tokenNode("id",idval,NULL);
										tokenNode* var = new tokenNode("var",id,NULL);
										vec.push_back(var);
									}

	|	VAR LB INT RB				{
										cout<<"deal with var -> var lb int rb\n";
										tokenNode* rb = new tokenNode("]");
										tokenNode* integer = new tokenNode($3,NULL,rb);
										tokenNode* lb = new tokenNode("[",NULL,integer);
										tokenNode* var = vec.back();
										vec.pop_back();
										var->pnextSubling = lb;
										var = new tokenNode("var",var,NULL);
										vec.push_back(var);
									}
	;

FUNC:
		ID LP PARAS RP				{
										cout<<"deal with func -> id lp paras rp\n";
										tokenNode* rp = new tokenNode(")");
										tokenNode* paras = vec.back();
										vec.pop_back();
										paras->pnextSubling = rp;
										tokenNode* lp = new tokenNode("(",NULL,paras);
										tokenNode* idval= new tokenNode($1);
										tokenNode* id = new tokenNode("id",idval,lp);
										tokenNode* func = new tokenNode("func",id,NULL);
										vec.push_back(func);
									}
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