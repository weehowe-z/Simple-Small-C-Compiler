%{
#include <stdio.h>
#include <queue>
#include <vector>
#include "node.h"
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern char *yytext;
/*Solve warning: implicit declaration*/
int yyerror (const char *msg);
int yylex();
bool printFlag = true;
parseTree pTree;
vector<tokenNode*> vec;
%}

%union
{ 
     int intValue; /* integer value */ 
     char* charValue; /* string value */ 
};

%token <intValue>INT    /*bind the yylval type*/
%token <charValue>HEXINT
%token <charValue>ID
%token <charValue>UNARYOP
%token <charValue>BINARYOP
%token <charValue>PLUS
%token <charValue>MINUS
%token <charValue>SHIFTOP
%token <charValue>COMPAREOP
%token <charValue>EQUALOP
%token <charValue>BITAND
%token <charValue>BITXOR
%token <charValue>BITOR
%token <charValue>LOGICALAND
%token <charValue>LOGICALOR
%token <charValue>BINASSIGNOP
%token <charValue>TYPE
%token SEMI COMMA DOT ASSIGNOP LP RP LB RB LC RC STRUCT RETURN IF THEN ELSE BREAK CONT FOR

%right	NOELSE ELSE
%right 		ASSIGNOP BINASSIGNOP
%left       LOGICALOR
%left		LOGICALAND
%left       BITOR
%left		BITXOR
%left       BITAND
%left		EQUALOP
%left		COMPAREOP 
%left		SHIFTOP 
%left		PLUS MINUS
%left    	BINARYOP 
%right		UNARYOP UNMINUS
%left		DOT LP RP LB RB

%start PROGRAM

%%
PROGRAM:
		EXTDEFS				{
								//cout<<"deal with PROGRAM -> extdefs\n";
								tokenNode* extdefs = vec.back();vec.pop_back();
								tokenNode* program = new tokenNode("PROGRAM",extdefs,NULL);
								pTree.changeRoot(program);
							}
	;

EXTDEFS:
		EXTDEF EXTDEFS		{
								//cout<<"deal with extdefs -> extdef extdefs\n";
								tokenNode* extdefs = vec.back();
								vec.pop_back();
								tokenNode* extdef = vec.back();
								extdef->pnextSubling = extdefs;
								vec.pop_back();
								extdefs = new tokenNode("EXTDEFS",extdef,NULL);
								vec.push_back(extdefs);
							}

	|	/*EMPTY*/			{
								//cout<<"deal with extdefs -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* extdefs = new tokenNode("EXTDEFS",empty,NULL);
								vec.push_back(extdefs);
							}	
	;

EXTDEF:
		SPEC EXTVARS SEMI   {
								//cout<<"deal with extdef -> spec extvars semi\n";
								tokenNode* semi= new tokenNode(";");
								tokenNode* extvars = vec.back();
								vec.pop_back();
								tokenNode* spec = vec.back();
								vec.pop_back();
								extvars->pnextSubling = semi;
								spec->pnextSubling = extvars;
								tokenNode* extdef = new tokenNode("EXTDEF",spec,NULL);
								vec.push_back(extdef);

							}

	|	SPEC FUNC STMTBLOCK	{
								//cout<<"deal with extdef -> spec func stmtblock\n";
								tokenNode* stmtblock= vec.back();vec.pop_back();
								tokenNode* func = vec.back();vec.pop_back();
								tokenNode* spec = vec.back();vec.pop_back();
								func->pnextSubling = stmtblock;
								spec->pnextSubling = func;
								tokenNode* extdef = new tokenNode("EXTDEF",spec,NULL);
								vec.push_back(extdef);	
							}
	;

EXTVARS:
		DEC             	{
								//cout<<"deal with extvars -> dec\n";
								tokenNode* dec = vec.back();
								vec.pop_back();
								tokenNode* extvars = new tokenNode("EXTVARS",dec,NULL);
								vec.push_back(extvars);
							}

	|	DEC COMMA EXTVARS   {
								//cout<<"deal with extvars -> dec comma extvars\n";
								tokenNode* extvars = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",");
								tokenNode* dec = vec.back();
								vec.pop_back();
								dec->pnextSubling = comma;
								comma->pnextSubling = extvars;
								extvars = new tokenNode("EXTVARS",dec,NULL);
								vec.push_back(extvars);
							}

	|	/*EMPTY*/			{
								//cout<<"deal with extvars -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* extvars = new tokenNode("EXTVARS",empty,NULL);
								vec.push_back(extvars);
							}
	;

SPEC:
		TYPE            	{
								//cout<<"deal with spec -> type\n";
								tokenNode* typeVal = new tokenNode($1);
								tokenNode* type = new tokenNode("TYPE",typeVal,NULL);
								tokenNode* spec = new tokenNode("SPEC",type,NULL);
								vec.push_back(spec);
							}

	|	STSPEC				{
								//cout<<"deal with spec -> stspec\n";
								tokenNode* stspec = vec.back();
								vec.pop_back();
								tokenNode* spec = new tokenNode("SPEC",stspec,NULL);
								vec.push_back(spec);
							}
	;

STSPEC:
		STRUCT OPTTAG LC DEFS RC	{
										//cout<<"deal with stspec -> struct opttag lc defs rc\n";
										tokenNode* rc = new tokenNode("}");
										tokenNode* defs = vec.back();vec.pop_back();
										defs->pnextSubling = rc;
										tokenNode* lc = new tokenNode("{",NULL,defs);
										tokenNode* opttag = vec.back();vec.pop_back();
										opttag->pnextSubling = lc;
										tokenNode* structToken = new tokenNode("STRUCT",NULL,opttag);
										tokenNode* stspec = new tokenNode("STSPEC",structToken,NULL);
										vec.push_back(stspec);
									}

	|	STRUCT ID           		{
										//cout<<"deal with stspec -> struct id\n";					
										tokenNode* idval= new tokenNode($2);
										tokenNode* id = new tokenNode("ID",idval,NULL);
										tokenNode* structToken = new tokenNode("STRUCT",NULL,id);
										tokenNode* stspec = new tokenNode("STSPEC",structToken,NULL);
										vec.push_back(stspec);										
									}

OPTTAG:
	ID                  			{
										//cout<<"deal with opttag -> id\n";
										tokenNode* idval= new tokenNode($1);
										tokenNode* id = new tokenNode("ID",idval,NULL);
										tokenNode* opttag = new tokenNode("OPTTAG",id,NULL);
										vec.push_back(opttag);
									}

	|	/*EMPTY*/					{
										//cout<<"deal with opttag -> empty\n";
										tokenNode* empty = new tokenNode("ϵ");
										tokenNode* opttag = new tokenNode("OPTTAG",empty,NULL);
										vec.push_back(opttag);
									}	
	;

VAR:
		ID               			{
										//cout<<"deal with var -> id \n";
										tokenNode* idval= new tokenNode($1);
										tokenNode* id = new tokenNode("ID",idval,NULL);
										tokenNode* var = new tokenNode("VAR",id,NULL);
										vec.push_back(var);
									}

	|	VAR LB INT RB				{
										//cout<<"deal with var -> var lb int rb\n";
										tokenNode* rb = new tokenNode("]");
										tokenNode* integer = new tokenNode($3,NULL,rb);
										tokenNode* lb = new tokenNode("[",NULL,integer);
										tokenNode* var = vec.back();vec.pop_back();
										var->pnextSubling = lb;
										var = new tokenNode("VAR",var,NULL);
										vec.push_back(var);
									}

	|	VAR LB HEXINT RB			{
										//cout<<"deal with var -> var lb hexint rb\n";
										tokenNode* rb = new tokenNode("]");
										tokenNode* integer = new tokenNode($3,NULL,rb);
										tokenNode* lb = new tokenNode("[",NULL,integer);
										tokenNode* var = vec.back();vec.pop_back();
										var->pnextSubling = lb;
										var = new tokenNode("VAR",var,NULL);
										vec.push_back(var);
									}

	;

FUNC:
		ID LP PARAS RP				{
										//cout<<"deal with func -> id lp paras rp\n";
										tokenNode* rp = new tokenNode(")");
										tokenNode* paras = vec.back();vec.pop_back();paras->pnextSubling = rp;
										tokenNode* lp = new tokenNode("(",NULL,paras);
										tokenNode* idval= new tokenNode($1);
										tokenNode* id = new tokenNode("ID",idval,lp);
										tokenNode* func = new tokenNode("FUNC",id,NULL);
										vec.push_back(func);
									}
	;

PARAS:
		PARA COMMA PARAS            {
										//cout<<"deal with paras -> para comma paras\n";
										tokenNode* paras = vec.back();vec.pop_back();
										tokenNode* comma = new tokenNode(",",NULL,paras);
										tokenNode* para = vec.back();vec.pop_back();para->pnextSubling = comma;
										paras = new tokenNode("PARAS",para,NULL);
										vec.push_back(paras);
									}

	|	PARA                        {
										//cout<<"deal with paras -> para\n";
										tokenNode* para = vec.back();
										vec.pop_back();
										tokenNode* paras = new tokenNode("PARAS",para,NULL);
										vec.push_back(paras);
									}
	|	/*EMPTY*/				    {
										//cout<<"deal with paras -> empty\n";
										tokenNode* empty = new tokenNode("ϵ");
										tokenNode* paras = new tokenNode("PARAS",empty,NULL);
										vec.push_back(paras);									
									}
	;

PARA:							
		SPEC VAR                    {
										//cout<<"deal with para -> spec var\n";
										tokenNode* var = vec.back();
										vec.pop_back();
										tokenNode* spec = vec.back();
										vec.pop_back();
										spec->pnextSubling = var;
										tokenNode* para = new tokenNode("PARA",spec,NULL);
										vec.push_back(para);
									}
	;

STMTBLOCK:							
		LC DEFS STMTS RC            {
										//cout<<"deal with stmtblock -> lc defs stmts rc\n";
										tokenNode* rc = new tokenNode("}");
										tokenNode* stmts = vec.back();vec.pop_back();stmts->pnextSubling = rc;
										tokenNode* defs = vec.back();vec.pop_back();defs->pnextSubling = stmts;
										tokenNode* lc = new tokenNode("{",NULL,defs);
										tokenNode* stmtblock = new tokenNode("STMTBLOCK",lc,NULL);
										vec.push_back(stmtblock);
									}
	;

STMTS:
		STMT STMTS                  {
										//cout<<"deal with stmts -> stmt stmts\n";
										tokenNode* stmts = vec.back();vec.pop_back();
										tokenNode* stmt = vec.back();vec.pop_back();stmt->pnextSubling = stmts;
										stmts = new tokenNode("STMTS",stmt,NULL);
										vec.push_back(stmts);
									}

	|	/*EMPTY*/					{
										//cout<<"deal with stmts -> empty\n";
										tokenNode* empty = new tokenNode("ϵ");
										tokenNode* stmts = new tokenNode("STMTS",empty,NULL);
										vec.push_back(stmts);										
									}
	;

STMT:
		EXP SEMI                                        {
															//cout<<"deal with stmt -> exp semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* exp = vec.back();
															vec.pop_back();
															exp->pnextSubling = semi;
															tokenNode* stmt = new tokenNode("STMT",exp,NULL);
															vec.push_back(stmt);
														}
	|	STMTBLOCK                                       {
															//cout<<"deal with stmt -> stmtblock\n";
															tokenNode* stmtblock = vec.back();vec.pop_back();
															tokenNode* stmt = new tokenNode("STMT",stmtblock,NULL);
															vec.push_back(stmt);
														}
	|	RETURN EXP SEMI                                 {
															//cout<<"deal with stmt -> stmtblock\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* exp = vec.back();
															vec.pop_back();
															exp->pnextSubling = semi;
															tokenNode* returnToken = new tokenNode("RETURN",NULL,exp);
															tokenNode* stmt = new tokenNode("STMT",returnToken,NULL);
															vec.push_back(stmt);
														}

	|	IF LP EXP RP STMT ESTMT                         {
															//cout<<"deal with stmt -> if lp exp rp stmt estmt\n";
															tokenNode* estmt = vec.back();vec.pop_back();
															tokenNode* stmt = vec.back();vec.pop_back();stmt->pnextSubling = estmt;
															tokenNode* rp = new tokenNode(")",NULL,stmt);
															tokenNode* exp = vec.back();vec.pop_back();exp->pnextSubling = rp;
															tokenNode* lp = new tokenNode("(",NULL,exp);
															tokenNode* ifToken = new tokenNode("IF",NULL,lp);
															stmt = new tokenNode("STMT",ifToken,NULL);
															vec.push_back(stmt);
														}

	|	FOR LP FEXP SEMI FEXP SEMI FEXP RP STMT            {
															//cout<<"deal with stmt -> for loop \n";
															tokenNode* stmt = vec.back();vec.pop_back();
															tokenNode* rp = new tokenNode(")",NULL,stmt);
															tokenNode* fexp = vec.back();vec.pop_back();fexp->pnextSubling = rp;
															tokenNode* semi = new tokenNode(";",NULL,fexp);
															fexp = vec.back();vec.pop_back();fexp->pnextSubling = semi;
															semi = new tokenNode(";",NULL,fexp);
															fexp = vec.back();vec.pop_back();fexp->pnextSubling = semi;
															tokenNode* lp = new tokenNode("(",NULL,fexp);
															tokenNode* forToken = new tokenNode("FOR",NULL,lp);
															stmt = new tokenNode("STMT",forToken,NULL);
															vec.push_back(stmt);
														}

	|	CONT SEMI                                       {
															//cout<<"deal with stmt -> cont semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* cont = new tokenNode("CONTINUE",NULL,semi);
															tokenNode* stmt = new tokenNode("STMT",NULL,cont);
															vec.push_back(stmt);
														} 

	|	BREAK SEMI                                      {
															//cout<<"deal with stmt -> break semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* breakToken = new tokenNode("BREAK",NULL,semi);
															tokenNode* stmt = new tokenNode("STMT",NULL,breakToken);
															vec.push_back(stmt);
														} 
	;

ESTMT:
		ELSE STMT           		                    {
															//cout<<"deal with estmt -> else stmt\n";
															tokenNode* stmt = vec.back();vec.pop_back();
															tokenNode* elseToken = new tokenNode("ELSE",NULL,stmt);
															tokenNode* estmt = new tokenNode("ESTMT",elseToken,NULL);
															vec.push_back(estmt);
														}
	|						%prec NOELSE                {
															//cout<<"deal with estmt -> empty\n";
															tokenNode* empty = new tokenNode("ϵ");
															tokenNode* estmt = new tokenNode("ESTMT",empty,NULL);
															vec.push_back(estmt);
														}

	;




DEFS:
		DEF DEFS                                       {
															//cout<<"deal with defs -> def defs\n";
															tokenNode* defs = vec.back();vec.pop_back();
															tokenNode* def = vec.back();vec.pop_back();
															def->pnextSubling = defs;
															defs = new tokenNode("DEFS",def,NULL);
															vec.push_back(defs);
														}

	|	/*EMPTY*/	      				          		{
															//cout<<"deal with defs -> empty\n";
															tokenNode* empty = new tokenNode("ϵ");
															tokenNode* defs = new tokenNode("DEFS",empty,NULL);
															vec.push_back(defs);										
														}
	;
     
DEF:
		SPEC DECS SEMI      			                {
															//cout<<"deal with def -> spec decs semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* decs = vec.back();vec.pop_back();decs->pnextSubling = semi;
															tokenNode* spec = vec.back();vec.pop_back();spec->pnextSubling = decs;
															tokenNode* def = new tokenNode("DEF",spec,NULL);
															vec.push_back(def);
														}
	;

DECS:
		DEC COMMA DECS      {
								//cout<<"deal with decs -> dec comma decs\n";
								tokenNode* decs = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",",NULL,decs);
								tokenNode* dec = vec.back();
								vec.pop_back();
								dec->pnextSubling = comma;
								decs = new tokenNode("DECS",dec,NULL);
								vec.push_back(decs);
							}
	|	DEC                 {
								//cout<<"deal with decs -> dec\n";
								tokenNode* dec = vec.back();vec.pop_back();
								tokenNode* decs = new tokenNode("DECS",dec,NULL);
								vec.push_back(decs);								
							}
	;

DEC:
		VAR					{
								//cout<<"deal with dec -> var\n";
								tokenNode* var = vec.back();vec.pop_back();
								tokenNode* dec = new tokenNode("DEC",var,NULL);
								vec.push_back(dec);
							}	

	|	VAR ASSIGNOP INIT	{
								//cout<<"deal with dec -> var assignop init\n";
								tokenNode* init = vec.back();
								vec.pop_back();
								tokenNode* assignop = new tokenNode("=",NULL,init);
								tokenNode* var = vec.back();
								vec.pop_back();
								var->pnextSubling = assignop;
								tokenNode* dec = new tokenNode("DEC",var,NULL);
								vec.push_back(dec);
							}	
	;

INIT:
		EXP                 {
								//cout<<"deal with init -> exp\n";
								tokenNode* exp = vec.back();
								vec.pop_back();
								tokenNode* init = new tokenNode("INIT",exp,NULL);
								vec.push_back(init);
		                    }

	|	LC ARGS RC          {
								//cout<<"deal with init -> lc args rc\n";
								tokenNode* rc = new tokenNode("}");
								tokenNode* args = vec.back();
								vec.pop_back();
								args->pnextSubling = rc;
								tokenNode* lc = new tokenNode("{",NULL,args);
								tokenNode* init = new tokenNode("INIT",lc,NULL);
								vec.push_back(init);
							}
	;

EXP:
		LP EXP RP           {
								//cout<<"deal with exp -> lp exp rp\n";
								tokenNode* rp = new tokenNode(")");
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = rp;
								tokenNode* lp = new tokenNode("(",NULL,exp);
								exp = new tokenNode("EXP",lp,NULL);
								vec.push_back(exp);
							}
	|	ID LP ARGS RP       {
								//cout<<"deal with exp -> id lp args rp\n";
								tokenNode* rp = new tokenNode(")");
								tokenNode* args = vec.back();
								vec.pop_back();
								args->pnextSubling = rp;
								tokenNode* lp = new tokenNode("(",NULL,args);
								tokenNode* idval= new tokenNode($1);
								tokenNode* id = new tokenNode("ID",idval,lp);
								tokenNode* exp = new tokenNode("EXP",id,NULL);
								vec.push_back(exp);						
							}
	|	ID ARRS             {
								//cout<<"deal with exp -> id arrs\n";
								tokenNode* arrs = vec.back();
								vec.pop_back();
								tokenNode* idval= new tokenNode($1);
								tokenNode* id = new tokenNode("ID",idval,arrs);
								tokenNode* exp = new tokenNode("EXP",id,NULL);
								vec.push_back(exp);
							}
	|	EXP DOT ID /*x.length()?*/{
								//cout<<"deal with exp -> exp dot id\n";
								tokenNode* idval= new tokenNode($3);
								tokenNode* id = new tokenNode("ID",idval,NULL);
								tokenNode* dot = new tokenNode(".",NULL,id);
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = dot;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);								
							}

	|	INT                 {
								//cout<<"deal with exp -> int\n";
								tokenNode* intVal = new tokenNode($1);
								tokenNode* intToken = new tokenNode("INT",intVal,NULL);
								tokenNode* exp = new tokenNode("EXP",intToken,NULL);
								vec.push_back(exp);								
							}

	|	HEXINT                {
								//cout<<"deal with exp -> HEXint\n";
								tokenNode* intVal = new tokenNode($1);
								tokenNode* intToken = new tokenNode("INT",intVal,NULL);
								tokenNode* exp = new tokenNode("EXP",intToken,NULL);
								vec.push_back(exp);								
							}

	|	UNARYOP EXP         {
								//cout<<"deal with exp -> unaryop exp\n";
								tokenNode* exp = vec.back();
								vec.pop_back();
								tokenNode* unaryopVal = new tokenNode($1);
								tokenNode* unaryop = new tokenNode("UNARYOP",unaryopVal,exp);
								exp = new tokenNode("EXP",unaryop,NULL);
								vec.push_back(exp);
	                        }

	|	EXP BINARYOP EXP    	{
								//cout<<"deal with exp -> exp BINARYOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}	

	|	MINUS EXP %prec	UNMINUS {
								//cout<<"deal with exp -> MINUS exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($1,NULL,exp);
								exp = new tokenNode("EXP",binaryop,NULL);
								vec.push_back(exp);	
							}	

	|	EXP MINUS EXP    	{
								//cout<<"deal with exp -> exp MINUS exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}	


	|	EXP PLUS EXP    	{
								//cout<<"deal with exp -> exp PLUS exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}	       


	|	EXP SHIFTOP EXP    	{
								//cout<<"deal with exp -> exp SHIFTOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}	                     

	|	EXP COMPAREOP EXP    	{
								//cout<<"deal with exp -> exp COMPAREOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}


	|	EXP EQUALOP EXP    	{
								//cout<<"deal with exp -> exp EQUALOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}


	|	EXP BITXOR EXP    	{
								//cout<<"deal with exp -> exp BITXOR exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}

	|	EXP BITOR EXP    	{
								//cout<<"deal with exp -> exp BITOR exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}

	|	EXP BITAND EXP    	{
								//cout<<"deal with exp -> exp BITAND exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}

	|	EXP LOGICALAND EXP  {
								//cout<<"deal with exp -> exp LOGICALAND exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);		
	                        }

	|	EXP LOGICALOR EXP   {
								//cout<<"deal with exp -> exp LOGICALOR exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);		
	                        }

	|	EXP BINASSIGNOP EXP    {
								//cout<<"deal with exp -> exp BINASSIGNOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode($2,NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);		
	                        }

	|	EXP ASSIGNOP EXP    {
								//cout<<"deal with exp -> exp assignop exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* assignop = new tokenNode("=",NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = assignop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);
							}	
	;
FEXP:
		EXP 				{
								//cout<<"deal with fexp -> exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* fexp = new tokenNode("FEXP",exp,NULL);
								vec.push_back(fexp);
							}
	|	/*EMPTY*/           {   //cout<<"deal with fexp -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* fexp = new tokenNode("FEXP",empty,NULL);
								vec.push_back(fexp);
							}


ARRS:
		LB EXP RB ARRS      {
								//cout<<"deal with arrs -> lb exp rb arrs\n";
								tokenNode* arrs = vec.back();
								vec.pop_back();
								tokenNode* rb = new tokenNode("]",NULL,arrs);
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = rb;
								tokenNode* lb = new tokenNode("[",NULL,exp);
								arrs = new tokenNode("ARRS",lb,NULL);
								vec.push_back(arrs);
							}
	|	/*EMPTY*/			{
								//cout<<"deal with arrs -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* arrs = new tokenNode("ARRS",empty,NULL);
								vec.push_back(arrs);						
							}
	;

ARGS:
		EXP COMMA ARGS      {
								//cout<<"deal with args -> exp comma args\n";
								tokenNode* args = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",",NULL,args);
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = comma;							
								args = new tokenNode("ARGS",exp,NULL);
								vec.push_back(args);
							}	

	|	EXP					{
								//cout<<"deal with args -> exp\n";
								tokenNode* exp = vec.back();
								vec.pop_back();
								tokenNode* args = new tokenNode("ARGS",exp,NULL);
								vec.push_back(args);
							}	
	;


%%


int main (int argc, char const *argv[]) {

	if (argc == 1){
		fprintf(stderr, "%s\n", "YACC: please write your code in the shell. input CTRL-D to exit.");
		fprintf(stderr, "%s\n", "YACC: or you can specify the source code path. \nexample --> $./a.out  inputFile outputFile\n");
		yyparse();
		if (printFlag) {
			pTree.printQueue(yyout);
		}
		return 0;
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
		if (printFlag) {
			pTree.printQueue(yyout);
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
		if (printFlag) {
			pTree.printQueue(yyout);
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
	printFlag = false;
	fprintf(stderr, "YACC: %s at line %d\n", msg,yylineno);
	fprintf(stderr, "YACC: does not expect %s\n",yytext);
	fprintf(yyout, "YACC: %s at line %d\n", msg,yylineno);
	fprintf(yyout, "YACC: does not expect %s\n",yytext);
	return -1;
}