%{
#include "node.h"
#include <cstdio>
#include <cstdlib>
NBlock *programBlock; /* the top level root node of our final AST */

extern int yylex();
extern int yylineno;
extern char *yytext;
int yyerror (const char *msg);
std::vector<NExpression*> vec_temp_expr;
std::vector<NStatement*> vec_temp_stmt;
std::vector<NIdentifier*> vec_temp_ident;
std::vector<Node*> vec;
%}

/* Represents the many different ways we can access our data */
%union {
	Node *node;
	NBlock *block;
	NExpression *expr;
	NStatement *stmt;
	NIdentifier *ident;
	NVariableDeclaration *var_decl;
	std::vector<NVariableDeclaration*> *varvec;
	std::vector<NExpression*> *exprvec;
	std::string *string;
	char *token;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
// %token <string> TIDENTIFIER TINTEGER TDOUBLE
// %token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
// %token <token> SEMI COMMA DOT  LP RP LB RB LC RC STRUCT RETURN IF THEN ELSE BREAK CONT FOR
// %token <token> TPLUS TMINUS TMUL TDIV
// %token <token> TRETURN TEXTERN
// %token <token> PLUS


%token <string>INT    /*bind the yylval type*/
%token <string>HEXINT
%token <string>ID
%token <token>UNARYOP
%token <token>BINARYOP
%token <token>PLUS
%token <token>MINUS
%token <token>SHIFTOP
%token <token>COMPAREOP
%token <token>EQUALOP
%token <token>BITAND
%token <token>BITXOR
%token <token>BITOR
%token <token>LOGICALAND
%token <token>LOGICALOR
%token <token>BINASSIGNOP
%token <string>TYPE
%token SEMI COMMA DOT ASSIGNOP LP RP LB RB LC RC STRUCT RETURN IF THEN ELSE BREAK CONT FOR






/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
// %type <ident> ident
// %type <expr> numeric expr EXP
// %type <varvec> func_decl_args
// %type <exprvec> call_args
// %type <block> PROGRAM EXTDEFS stmts block
// %type <stmt> stmt var_decl func_decl extern_decl
// %type <token> comparison

%type <expr> EXP
%type <block> PROGRAM EXTDEFS STMTS
%type <stmt>  STMT
// %type <ident> ID


/* Operator precedence for mathematical operators */
// %left TPLUS TMINUS
// %left TMUL TDIV

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
								std::cout<<"deal with PROGRAM -> extdefs\n";
								Node* extdefs = vec.back();vec.pop_back();
								Node* program = new Node("PROGRAM",extdefs,NULL);
								programBlock = $1;

							}
	;

EXTDEFS:
		EXTDEFS EXTDEF		{
								std::cout<<"deal with extdefs -> extdef extdefs\n";
								Node* extdefs = vec.back();
								vec.pop_back();
								Node* extdef = vec.back();
								extdef->pnextSubling = extdefs;
								vec.pop_back();
								extdefs = new Node("EXTDEFS",extdef,NULL);
								vec.push_back(extdefs);
							}

	|	/*EMPTY*/			{
								std::cout<<"deal with extdefs -> empty\n";
								Node* empty = new Node("ϵ");
								Node* extdefs = new Node("EXTDEFS",empty,NULL);
								vec.push_back(extdefs);
							}	
	;

EXTDEF:
		SPEC EXTVARS SEMI   {
								std::cout<<"deal with extdef -> spec extvars semi\n";
								Node* semi= new Node(";");
								Node* extvars = vec.back();vec.pop_back();
								Node* spec = vec.back();vec.pop_back();
								extvars->pnextSubling = semi;
								spec->pnextSubling = extvars;
								// Node* extdef = new Node("EXTDEF",spec,NULL);

								Node* type = spec->pfirstChild;
								Node* ID = extvars->pfirstChild->pfirstChild->pfirstChild;
								std::cout<<type->node_name;
								Node* extdef = new Node("EXTDEF",spec,NULL);
								vec.push_back(extdef);

								new NVariableDeclaration(*type, *ID);



							}

	|	SPEC FUNC STMTBLOCK	{
								//cout<<"deal with extdef -> spec func stmtblock\n";
								// tokenNode* stmtblock= vec.back();vec.pop_back();
								// tokenNode* func = vec.back();vec.pop_back();
								// tokenNode* spec = vec.back();vec.pop_back();
								// func->pnextSubling = stmtblock;
								// spec->pnextSubling = func;
								// tokenNode* extdef = new tokenNode("EXTDEF",spec,NULL);
								// vec.push_back(extdef);	
							}
	;

EXTVARS:
		DEC             	{
								std::cout<<"deal with extvars -> dec\n";
								Node* dec = vec.back();
								vec.pop_back();
								Node* extvars = new Node("EXTVARS",dec,NULL);
								vec.push_back(extvars);
							}

	|	DEC COMMA EXTVARS   {
								//cout<<"deal with extvars -> dec comma extvars\n";
								// tokenNode* extvars = vec.back();
								// vec.pop_back();
								// tokenNode* comma = new tokenNode(",");
								// tokenNode* dec = vec.back();
								// vec.pop_back();
								// dec->pnextSubling = comma;
								// comma->pnextSubling = extvars;
								// extvars = new tokenNode("EXTVARS",dec,NULL);
								// vec.push_back(extvars);
							}

	|	/*EMPTY*/			{
								//cout<<"deal with extvars -> empty\n";
								// tokenNode* empty = new tokenNode("ϵ");
								// tokenNode* extvars = new tokenNode("EXTVARS",empty,NULL);
								// vec.push_back(extvars);
							}
	;

SPEC:
		TYPE            	{
								std::cout<<"deal with spec -> type\n";
								NIdentifier* type = new NIdentifier(*$1); delete $1;
								Node* spec = new Node("SPEC",type,NULL);
								vec.push_back(spec);
								// tokenNode* typeVal = new tokenNode($1);
								// tokenNode* type = new tokenNode("TYPE",typeVal,NULL);
								// tokenNode* spec = new tokenNode("SPEC",type,NULL);
								// vec.push_back(spec);
							}

	|	STSPEC				{
								//cout<<"deal with spec -> stspec\n";
								// tokenNode* stspec = vec.back();
								// vec.pop_back();
								// tokenNode* spec = new tokenNode("SPEC",stspec,NULL);
								// vec.push_back(spec);
							}
	;

STSPEC:
		STRUCT OPTTAG LC DEFS RC	{
										//cout<<"deal with stspec -> struct opttag lc defs rc\n";
										// tokenNode* rc = new tokenNode("}");
										// tokenNode* defs = vec.back();vec.pop_back();
										// defs->pnextSubling = rc;
										// tokenNode* lc = new tokenNode("{",NULL,defs);
										// tokenNode* opttag = vec.back();vec.pop_back();
										// opttag->pnextSubling = lc;
										// tokenNode* structToken = new tokenNode("STRUCT",NULL,opttag);
										// tokenNode* stspec = new tokenNode("STSPEC",structToken,NULL);
										// vec.push_back(stspec);
									}

	|	STRUCT ID           		{
										//cout<<"deal with stspec -> struct id\n";					
										// tokenNode* idval= new tokenNode($2);
										// tokenNode* id = new tokenNode("ID",idval,NULL);
										// tokenNode* structToken = new tokenNode("STRUCT",NULL,id);
										// tokenNode* stspec = new tokenNode("STSPEC",structToken,NULL);
										// vec.push_back(stspec);										
									}

OPTTAG:
	ID                  			{
										//cout<<"deal with opttag -> id\n";
										// tokenNode* idval= new tokenNode($1);
										// tokenNode* id = new tokenNode("ID",idval,NULL);
										// tokenNode* opttag = new tokenNode("OPTTAG",id,NULL);
										// vec.push_back(opttag);
									}

	|	/*EMPTY*/					{
										//cout<<"deal with opttag -> empty\n";
										// tokenNode* empty = new tokenNode("ϵ");
										// tokenNode* opttag = new tokenNode("OPTTAG",empty,NULL);
										// vec.push_back(opttag);
									}	
	;

VAR:
		ID               			{

										std::cout<<"deal with var -> id \n";
										NIdentifier* id = new NIdentifier(*$1); delete $1; 
										Node* var = new Node("VAR",id,NULL);
										vec.push_back(var);

										// tokenNode* idval= new tokenNode($1);
										// tokenNode* id = new tokenNode("ID",idval,NULL);
										// tokenNode* var = new tokenNode("VAR",id,NULL);
										// vec.push_back(var);
									}

	|	VAR LB INT RB				{
										//cout<<"deal with var -> var lb int rb\n";
										// tokenNode* rb = new tokenNode("]");
										// tokenNode* integer = new tokenNode($3,NULL,rb);
										// tokenNode* lb = new tokenNode("[",NULL,integer);
										// tokenNode* var = vec.back();vec.pop_back();
										// var->pnextSubling = lb;
										// var = new tokenNode("VAR",var,NULL);
										// vec.push_back(var);
									}

	|	VAR LB HEXINT RB			{
										//cout<<"deal with var -> var lb hexint rb\n";
										// tokenNode* rb = new tokenNode("]");
										// tokenNode* integer = new tokenNode($3,NULL,rb);
										// tokenNode* lb = new tokenNode("[",NULL,integer);
										// tokenNode* var = vec.back();vec.pop_back();
										// var->pnextSubling = lb;
										// var = new tokenNode("VAR",var,NULL);
										// vec.push_back(var);
									}

	;

FUNC:
		ID LP PARAS RP				{
										//cout<<"deal with func -> id lp paras rp\n";
										// tokenNode* rp = new tokenNode(")");
										// tokenNode* paras = vec.back();vec.pop_back();paras->pnextSubling = rp;
										// tokenNode* lp = new tokenNode("(",NULL,paras);
										// tokenNode* idval= new tokenNode($1);
										// tokenNode* id = new tokenNode("ID",idval,lp);
										// tokenNode* func = new tokenNode("FUNC",id,NULL);
										// vec.push_back(func);
									}
	;

 PARAS:
		PARA COMMA PARAS            {
										//cout<<"deal with paras -> para comma paras\n";
										// tokenNode* paras = vec.back();vec.pop_back();
										// tokenNode* comma = new tokenNode(",",NULL,paras);
										// tokenNode* para = vec.back();vec.pop_back();para->pnextSubling = comma;
										// paras = new tokenNode("PARAS",para,NULL);
										// vec.push_back(paras);
									}

	|	PARA                        {
										//cout<<"deal with paras -> para\n";
										// tokenNode* para = vec.back();
										// vec.pop_back();
										// tokenNode* paras = new tokenNode("PARAS",para,NULL);
										// vec.push_back(paras);
									}
	|	/*EMPTY*/				    {
										//cout<<"deal with paras -> empty\n";
										// tokenNode* empty = new tokenNode("ϵ");
										// tokenNode* paras = new tokenNode("PARAS",empty,NULL);
										// vec.push_back(paras);									
									}
	;

PARA:							
		SPEC VAR                    {
										//cout<<"deal with para -> spec var\n";
										// tokenNode* var = vec.back();
										// vec.pop_back();
										// tokenNode* spec = vec.back();
										// vec.pop_back();
										// spec->pnextSubling = var;
										// tokenNode* para = new tokenNode("PARA",spec,NULL);
										// vec.push_back(para);
									}
	;

STMTBLOCK:							
		LC DEFS STMTS RC            {
										//cout<<"deal with stmtblock -> lc defs stmts rc\n";
										// tokenNode* rc = new tokenNode("}");
										// tokenNode* stmts = vec.back();vec.pop_back();stmts->pnextSubling = rc;
										// tokenNode* defs = vec.back();vec.pop_back();defs->pnextSubling = stmts;
										// tokenNode* lc = new tokenNode("{",NULL,defs);
										// tokenNode* stmtblock = new tokenNode("STMTBLOCK",lc,NULL);
										// vec.push_back(stmtblock);
									}
	;

STMTS:
		// STMT STMTS                  {
		STMTS STMT                  {
										{$1->statements.push_back($<stmt>2); }
										//cout<<"deal with stmts -> stmt stmts\n";
										// tokenNode* stmts = vec.back();vec.pop_back();
										// tokenNode* stmt = vec.back();vec.pop_back();stmt->pnextSubling = stmts;
										// stmts = new tokenNode("STMTS",stmt,NULL);
										// vec.push_back(stmts);
									}

	|	/*EMPTY*/					{
										//cout<<"deal with stmts -> empty\n";
										// tokenNode* empty = new tokenNode("ϵ");
										// tokenNode* stmts = new tokenNode("STMTS",empty,NULL);
										// vec.push_back(stmts);										
									}
	;

STMT:
		EXP SEMI                                        {
															$$ = new NExpressionStatement(*$1);
															//cout<<"deal with stmt -> exp semi\n";
															// tokenNode* semi = new tokenNode(";");
															// tokenNode* exp = vec.back();
															// vec.pop_back();
															// exp->pnextSubling = semi;
															// tokenNode* stmt = new tokenNode("STMT",exp,NULL);
															// vec.push_back(stmt);
														}
	|	STMTBLOCK                                       {
															//cout<<"deal with stmt -> stmtblock\n";
															// tokenNode* stmtblock = vec.back();vec.pop_back();
															// tokenNode* stmt = new tokenNode("STMT",stmtblock,NULL);
															// vec.push_back(stmt);
														}
	|	RETURN EXP SEMI                                 {
															//cout<<"deal with stmt -> stmtblock\n";
															// tokenNode* semi = new tokenNode(";");
															// tokenNode* exp = vec.back();
															// vec.pop_back();
															// exp->pnextSubling = semi;
															// tokenNode* returnToken = new tokenNode("RETURN",NULL,exp);
															// tokenNode* stmt = new tokenNode("STMT",returnToken,NULL);
															// vec.push_back(stmt);
														}

	|	IF LP EXP RP STMT ESTMT                         {
															//cout<<"deal with stmt -> if lp exp rp stmt estmt\n";
															// tokenNode* estmt = vec.back();vec.pop_back();
															// tokenNode* stmt = vec.back();vec.pop_back();stmt->pnextSubling = estmt;
															// tokenNode* rp = new tokenNode(")",NULL,stmt);
															// tokenNode* exp = vec.back();vec.pop_back();exp->pnextSubling = rp;
															// tokenNode* lp = new tokenNode("(",NULL,exp);
															// tokenNode* ifToken = new tokenNode("IF",NULL,lp);
															// stmt = new tokenNode("STMT",ifToken,NULL);
															// vec.push_back(stmt);
														}

	|	FOR LP FEXP SEMI FEXP SEMI FEXP RP STMT            {
															//cout<<"deal with stmt -> for loop \n";
															// tokenNode* stmt = vec.back();vec.pop_back();
															// tokenNode* rp = new tokenNode(")",NULL,stmt);
															// tokenNode* fexp = vec.back();vec.pop_back();fexp->pnextSubling = rp;
															// tokenNode* semi = new tokenNode(";",NULL,fexp);
															// fexp = vec.back();vec.pop_back();fexp->pnextSubling = semi;
															// semi = new tokenNode(";",NULL,fexp);
															// fexp = vec.back();vec.pop_back();fexp->pnextSubling = semi;
															// tokenNode* lp = new tokenNode("(",NULL,fexp);
															// tokenNode* forToken = new tokenNode("FOR",NULL,lp);
															// stmt = new tokenNode("STMT",forToken,NULL);
															// vec.push_back(stmt);
														}

	|	CONT SEMI                                       {
															//cout<<"deal with stmt -> cont semi\n";
															// tokenNode* semi = new tokenNode(";");
															// tokenNode* cont = new tokenNode("CONTINUE",NULL,semi);
															// tokenNode* stmt = new tokenNode("STMT",NULL,cont);
															// vec.push_back(stmt);
														} 

	|	BREAK SEMI                                      {
															//cout<<"deal with stmt -> break semi\n";
															// tokenNode* semi = new tokenNode(";");
															// tokenNode* breakToken = new tokenNode("BREAK",NULL,semi);
															// tokenNode* stmt = new tokenNode("STMT",NULL,breakToken);
															// vec.push_back(stmt);
														} 
	;

ESTMT:
		ELSE STMT           		                    {
															//cout<<"deal with estmt -> else stmt\n";
															// tokenNode* stmt = vec.back();vec.pop_back();
															// tokenNode* elseToken = new tokenNode("ELSE",NULL,stmt);
															// tokenNode* estmt = new tokenNode("ESTMT",elseToken,NULL);
															// vec.push_back(estmt);
														}
	|						%prec NOELSE                {
															//cout<<"deal with estmt -> empty\n";
															// tokenNode* empty = new tokenNode("ϵ");
															// tokenNode* estmt = new tokenNode("ESTMT",empty,NULL);
															// vec.push_back(estmt);
														}

	;




DEFS:
		DEF DEFS                                       {
															//cout<<"deal with defs -> def defs\n";
															// tokenNode* defs = vec.back();vec.pop_back();
															// tokenNode* def = vec.back();vec.pop_back();
															// def->pnextSubling = defs;
															// defs = new tokenNode("DEFS",def,NULL);
															// vec.push_back(defs);
														}

	|	/*EMPTY*/	      				          		{
															//cout<<"deal with defs -> empty\n";
															// tokenNode* empty = new tokenNode("ϵ");
															// tokenNode* defs = new tokenNode("DEFS",empty,NULL);
															// vec.push_back(defs);										
														}
	;
     
DEF:
		SPEC DECS SEMI      			                {
															//cout<<"deal with def -> spec decs semi\n";
															// tokenNode* semi = new tokenNode(";");
															// tokenNode* decs = vec.back();vec.pop_back();decs->pnextSubling = semi;
															// tokenNode* spec = vec.back();vec.pop_back();spec->pnextSubling = decs;
															// tokenNode* def = new tokenNode("DEF",spec,NULL);
															// vec.push_back(def);
														}
	;

DECS:
		DEC COMMA DECS      {
								//cout<<"deal with decs -> dec comma decs\n";
								// tokenNode* decs = vec.back();
								// vec.pop_back();
								// tokenNode* comma = new tokenNode(",",NULL,decs);
								// tokenNode* dec = vec.back();
								// vec.pop_back();
								// dec->pnextSubling = comma;
								// decs = new tokenNode("DECS",dec,NULL);
								// vec.push_back(decs);
							}
	|	DEC                 {
								//cout<<"deal with decs -> dec\n";
								// tokenNode* dec = vec.back();vec.pop_back();
								// tokenNode* decs = new tokenNode("DECS",dec,NULL);
								// vec.push_back(decs);								
							}
	;

DEC:
		VAR					{
								std::cout<<"deal with dec -> var\n";
								Node* var = vec.back();vec.pop_back();
								Node* dec = new Node("DEC",var,NULL);
								vec.push_back(dec);
							}	

	|	VAR ASSIGNOP INIT	{
								// $$ = new NVariableDeclaration(*$1, *$2, $4);
								//cout<<"deal with dec -> var assignop init\n";
								// tokenNode* init = vec.back();
								// vec.pop_back();
								// tokenNode* assignop = new tokenNode("=",NULL,init);
								// tokenNode* var = vec.back();
								// vec.pop_back();
								// var->pnextSubling = assignop;
								// tokenNode* dec = new tokenNode("DEC",var,NULL);
								// vec.push_back(dec);
							}	
	;

INIT:
		EXP                 {
								//cout<<"deal with init -> exp\n";
								// tokenNode* exp = vec.back();
								// vec.pop_back();
								// tokenNode* init = new tokenNode("INIT",exp,NULL);
								// vec.push_back(init);
		                    }

	|	LC ARGS RC          {
								//cout<<"deal with init -> lc args rc\n";
								// tokenNode* rc = new tokenNode("}");
								// tokenNode* args = vec.back();
								// vec.pop_back();
								// args->pnextSubling = rc;
								// tokenNode* lc = new tokenNode("{",NULL,args);
								// tokenNode* init = new tokenNode("INIT",lc,NULL);
								// vec.push_back(init);
							}
	;

EXP:
		LP EXP RP           {
								//cout<<"deal with exp -> lp exp rp\n";
								// tokenNode* rp = new tokenNode(")");
								// tokenNode* exp = vec.back();
								// vec.pop_back();
								// exp->pnextSubling = rp;
								// tokenNode* lp = new tokenNode("(",NULL,exp);
								// exp = new tokenNode("EXP",lp,NULL);
								// vec.push_back(exp);
							}
	|	ID LP ARGS RP       {
								//cout<<"deal with exp -> id lp args rp\n";
								// tokenNode* rp = new tokenNode(")");
								// tokenNode* args = vec.back();
								// vec.pop_back();
								// args->pnextSubling = rp;
								// tokenNode* lp = new tokenNode("(",NULL,args);
								// tokenNode* idval= new tokenNode($1);
								// tokenNode* id = new tokenNode("ID",idval,lp);
								// tokenNode* exp = new tokenNode("EXP",id,NULL);
								// vec.push_back(exp);						
							}
	|	ID ARRS             {
								//cout<<"deal with exp -> id arrs\n";
								// tokenNode* arrs = vec.back();
								// vec.pop_back();
								// tokenNode* idval= new tokenNode($1);
								// tokenNode* id = new tokenNode("ID",idval,arrs);
								// tokenNode* exp = new tokenNode("EXP",id,NULL);
								// vec.push_back(exp);
							}
	|	EXP DOT ID /*x.length()?*/{
								//cout<<"deal with exp -> exp dot id\n";
								// tokenNode* idval= new tokenNode($3);
								// tokenNode* id = new tokenNode("ID",idval,NULL);
								// tokenNode* dot = new tokenNode(".",NULL,id);
								// tokenNode* exp = vec.back();
								// vec.pop_back();
								// exp->pnextSubling = dot;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);								
							}

	|	INT                 {
								$$ = new NInteger(atol($1->c_str())); delete $1;
								//cout<<"deal with exp -> int\n";
								// tokenNode* intVal = new tokenNode($1);
								// tokenNode* intToken = new tokenNode("INT",intVal,NULL);
								// tokenNode* exp = new tokenNode("EXP",intToken,NULL);
								// vec.push_back(exp);								
							}

	|	HEXINT                {
								//cout<<"deal with exp -> HEXint\n";
								// tokenNode* intVal = new tokenNode($1);
								// tokenNode* intToken = new tokenNode("INT",intVal,NULL);
								// tokenNode* exp = new tokenNode("EXP",intToken,NULL);
								// vec.push_back(exp);								
							}

	|	UNARYOP EXP         {
								//cout<<"deal with exp -> unaryop exp\n";
								// tokenNode* exp = vec.back();
								// vec.pop_back();
								// tokenNode* unaryopVal = new tokenNode($1);
								// tokenNode* unaryop = new tokenNode("UNARYOP",unaryopVal,exp);
								// exp = new tokenNode("EXP",unaryop,NULL);
								// vec.push_back(exp);
	                        }

	|	EXP BINARYOP EXP    	{
								//cout<<"deal with exp -> exp BINARYOP exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}	

	|	MINUS EXP %prec	UNMINUS {
								//cout<<"deal with exp -> MINUS exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($1,NULL,exp);
								// exp = new tokenNode("EXP",binaryop,NULL);
								// vec.push_back(exp);	
							}	

	|	EXP MINUS EXP    	{
								//cout<<"deal with exp -> exp MINUS exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}	


	|	EXP PLUS EXP    	{
								//cout<<"deal with exp -> exp PLUS exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}	       


	|	EXP SHIFTOP EXP    	{
								//cout<<"deal with exp -> exp SHIFTOP exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}	                     

	|	EXP COMPAREOP EXP    	{
								//cout<<"deal with exp -> exp COMPAREOP exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}


	|	EXP EQUALOP EXP    	{
								//cout<<"deal with exp -> exp EQUALOP exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}


	|	EXP BITXOR EXP    	{
								//cout<<"deal with exp -> exp BITXOR exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}

	|	EXP BITOR EXP    	{
								//cout<<"deal with exp -> exp BITOR exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}

	|	EXP BITAND EXP    	{
								//cout<<"deal with exp -> exp BITAND exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);	
							}

	|	EXP LOGICALAND EXP  {
								//cout<<"deal with exp -> exp LOGICALAND exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);		
	                        }

	|	EXP LOGICALOR EXP   {
								//cout<<"deal with exp -> exp LOGICALOR exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);		
	                        }

	|	EXP BINASSIGNOP EXP    {
								//cout<<"deal with exp -> exp BINASSIGNOP exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* binaryop = new tokenNode($2,NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = binaryop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);		
	                        }

	|	EXP ASSIGNOP EXP    {
								// //cout<<"deal with exp -> exp assignop exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* assignop = new tokenNode("=",NULL,exp);
								// exp = vec.back();vec.pop_back();
								// exp->pnextSubling = assignop;
								// exp = new tokenNode("EXP",exp,NULL);
								// vec.push_back(exp);
							}	
	;
FEXP:
		EXP 				{
								//cout<<"deal with fexp -> exp\n";
								// tokenNode* exp = vec.back();vec.pop_back();
								// tokenNode* fexp = new tokenNode("FEXP",exp,NULL);
								// vec.push_back(fexp);
							}
	|	/*EMPTY*/           {   //cout<<"deal with fexp -> empty\n";
								// tokenNode* empty = new tokenNode("ϵ");
								// tokenNode* fexp = new tokenNode("FEXP",empty,NULL);
								// vec.push_back(fexp);
							}


ARRS:
		LB EXP RB ARRS      {
								//cout<<"deal with arrs -> lb exp rb arrs\n";
								// tokenNode* arrs = vec.back();
								// vec.pop_back();
								// tokenNode* rb = new tokenNode("]",NULL,arrs);
								// tokenNode* exp = vec.back();
								// vec.pop_back();
								// exp->pnextSubling = rb;
								// tokenNode* lb = new tokenNode("[",NULL,exp);
								// arrs = new tokenNode("ARRS",lb,NULL);
								// vec.push_back(arrs);
							}
	|	/*EMPTY*/			{
								//cout<<"deal with arrs -> empty\n";
								// tokenNode* empty = new tokenNode("ϵ");
								// tokenNode* arrs = new tokenNode("ARRS",empty,NULL);
								// vec.push_back(arrs);						
							}
	;

ARGS:
		EXP COMMA ARGS      {
								//cout<<"deal with args -> exp comma args\n";
								// tokenNode* args = vec.back();
								// vec.pop_back();
								// tokenNode* comma = new tokenNode(",",NULL,args);
								// tokenNode* exp = vec.back();
								// vec.pop_back();
								// exp->pnextSubling = comma;							
								// args = new tokenNode("ARGS",exp,NULL);
								// vec.push_back(args);
							}	

	|	EXP					{
								//cout<<"deal with args -> exp\n";
								// tokenNode* exp = vec.back();
								// vec.pop_back();
								// tokenNode* args = new tokenNode("ARGS",exp,NULL);
								// vec.push_back(args);
							}	
	;




// PROGRAM : 
// 			EXTDEFS { programBlock = $1; }
// 		;
		
// EXTDEFS :
// 			EXTDEF EXTDEFS {}
// 		|

		// { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
	  
	  // | stmts stmt { $1->statements.push_back($<stmt>2); }
// 	  ;

// stmt :
// 	;

// stmt : var_decl | func_decl | extern_decl
// 	 | expr { $$ = new NExpressionStatement(*$1); }
// 	 | TRETURN expr { $$ = new NReturnStatement(*$2); }
//      ;

// block : LB stmts RB { $$ = $2; }
// 	  | LB RB { $$ = new NBlock(); }
// 	  ;

// var_decl : ident ident { $$ = new NVariableDeclaration(*$1, *$2); }
// 		 | ident ident TEQUAL expr { $$ = new NVariableDeclaration(*$1, *$2, $4); }
// 		 ;

// extern_decl : TEXTERN ident ident LP func_decl_args RP
//                 { $$ = new NExternDeclaration(*$2, *$3, *$5); delete $5; }
//             ;

// func_decl : ident ident LP func_decl_args RP block 
// 			{ $$ = new NFunctionDeclaration(*$1, *$2, *$4, *$6); delete $4; }
// 		  ;
	
// func_decl_args : /*blank*/  { $$ = new VariableList(); }
// 		  | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
// 		  | func_decl_args COMMA var_decl { $1->push_back($<var_decl>3); }
// 		  ;

// ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
// 	  ;

// numeric : TINTEGER { $$ = new NInteger(atol($1->c_str())); delete $1; }
// 		| TDOUBLE { $$ = new NDouble(atof($1->c_str())); delete $1; }
// 		;
	
// expr : ident TEQUAL expr { $$ = new NAssignment(*$<ident>1, *$3); }
// 	 | ident LP call_args RP { $$ = new NMethodCall(*$1, *$3); delete $3; }
// 	 | ident { $<ident>$ = $1; }
// 	 | numeric
//          | expr TMUL expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
//          | expr TDIV expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
//          | expr PLUS expr { $$ = new NBinaryOperator(*$1, $2, *$3);}
//          | expr TMINUS expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
//  	 | expr comparison expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
//      | LP expr RP { $$ = $2; }
// 	 ;
	
// call_args : /*blank*/  { $$ = new ExpressionList(); }
// 		  | expr { $$ = new ExpressionList(); $$->push_back($1); }
// 		  | call_args COMMA expr  { $1->push_back($3); }
// 		  ;

// comparison : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE;

%%


int yyerror (const char *msg) {
	fprintf(stderr, "YACC: %s at line %d\n", msg,yylineno);
	fprintf(stderr, "YACC: does not expect %s\n",yytext);
	//fprintf(yyout, "YACC: %s at line %d\n", msg,yylineno);
	//fprintf(yyout, "YACC: does not expect %s\n",yytext);
	return -1;
}