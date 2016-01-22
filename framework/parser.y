%{
#include "header.h"
#include "lex.yy.c"
#include "syntax_tree.h"
#include "Node.h"

using namespace std;

extern int yylineno;
/*Solve warning: implicit declaration*/
int yyerror(const char* msg);
TreeNode * root;

%}

%union {
    char* string;
    TreeNode* node;
}


%token <string> ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN MOD_ASSIGN
%token <string> XOR_ASSIGN OR_ASSIGN RIGHT_OP LEFT_OP 
%token <string> AND_OP OR_OP EQ_OP NE_OP RIGHT_ASSIGN LEFT_ASSIGN 
%token <string> LOG_NOT_OP BIT_NOT_OP READ WRITE
%token <string> INT ID SEMI COMMA
%token <string> TYPE LP RP LB RB LC RC STRUCT RETURN
%token <string> IF ELSE BREAK CONT FOR DOT ASSIGN

%type <node> PROGRAM EXTDEFS EXTDEF SEXTVARS EXTVARS STSPEC FUNC PARAS STMTBLOCK STMTS
%type <node> STMT DEFS SDEFS SDECS DECS VAR INIT EXP EXPS ARRS ARGS UNARYOP

/*Precedence Declaration*/
%nonassoc  IF_NO_ELSE
%nonassoc ELSE_AFTER_IF
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN MOD_ASSIGN XOR_ASSIGN OR_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%left  OR_OP
%left  AND_OP
%left <string> BIT_OR_OP
%left <string> BIT_XOR_OP
%left <string> BIT_AND_OP
%left  EQ_OP NE_OP
%left <string> GE_OP LE_OP GT_OP LT_OP
%left LEFT_OP RIGHT_OP
%left <string> PLUS_OP MINUS_OP
%left <string> PRODUCT_OP DIV_OP MOD_OP
%right <string> INC_OP DEC_OP UNARY 
%left  DOT LP LB

%start PROGRAM

%%
PROGRAM:
			EXTDEFS 		{
								root = $$ = createNodeIns(yylineno,"PROGRAM","PROGRAM: EXTDEFS",1,$1);
							}
	;

EXTDEFS: 	
			EXTDEF EXTDEFS 	{
								$$ = createNodeIns(yylineno,"EXTDEFS","EXTDEFS: EXTDEF EXTDEFS",2,$1,$2);
							}

	| 		/*EMPTY*/		{
								$$ = createNodeIns(yylineno,"EXTDEFS", "EXTDEFS:null", 0);
							}
	;

EXTDEF: 	TYPE EXTVARS SEMI 		{ 
										$$ = createNodeIns(yylineno,"EXTDEF", "EXTDEF: TYPE EXTVARS ;", 2, createNodeIns(yylineno,"TYPE", $1, 0),$2);
									}
			
    | 		STSPEC SEXTVARS SEMI 	{ 
										$$ = createNodeIns(yylineno, "EXTDEF","EXTDEF: STSPEC SEXTVARS ;", 2, $1,$2); 
									}
	| 		TYPE FUNC STMTBLOCK 	{
										$$ = createNodeIns(yylineno,"EXTDEF", "EXTDEF: TYPE FUNC STMTBLOCK", 3, createNodeIns(yylineno,"TYPE", $1, 0),$2,$3); 
									}
	;


SEXTVARS: 	ID 						{ 
										$$ = createNodeIns(yylineno,"SEXTVARS", "SEXTVARS: ID",1,createNodeIns(yylineno,"ID",$1,0));
									}
	| 		ID COMMA SEXTVARS 		{ 	
										$$ = createNodeIns(yylineno, "SEXTVARS", "SEXTVARS: ID , SEXTVARS", 2, createNodeIns(yylineno,"ID", $1, 0),$3);
									}
	|		/*EMPTY*/				{
										$$ = createNodeIns(yylineno,"SEXTVARS", "SEXTVARS: null", 0);
									}
	;

EXTVARS: 	VAR 						{ 	
											$$ = createNodeIns(yylineno,"EXTVARS", "EXTVARS: VAR", 1, $1);
										}

	|		VAR COMMA EXTVARS 			{	
											$$ = createNodeIns(yylineno,"EXTVARS", "EXTVARS:VAR , EXTVARS", 2, $1,$3);
										}

	|		VAR ASSIGN INIT 			{
											$$ = createNodeIns(yylineno,"EXTVARS", "EXTVARS:VAR ASSIGN INIT", 3, $1,createNodeIns(yylineno,"ASSIGN",$2,0),$3); 
										}
	|		VAR ASSIGN INIT COMMA EXTVARS	{ 
												$$ = createNodeIns(yylineno,"EXTVARS", "EXTVARS:VAR ASSIGN INIT , EXTVARS", 4, $1,createNodeIns(yylineno,"ASSIGN",$2,0),$3,$5);
											}
	| 		/*EMPTY*/					{
											$$ = createNodeIns(yylineno,"EXTVARS", "EXTVARS:null", 0);
										}
	;

STSPEC: 	STRUCT ID LC SDEFS RC 		{
											$$ = createNodeIns(yylineno,"STSPEC", "STSPEC: STRUCT ID { SDEFS }", 3, createNodeIns(yylineno,"STRUCT",$1,0),createNodeIns(yylineno,"ID", $2, 0),$4);
										}

	| 		STRUCT LC SDEFS RC 			{ 	
											$$ = createNodeIns(yylineno, "STSPEC","STSPEC: STRUCT { SDEFS }", 2, createNodeIns(yylineno,"STRUCT",$1,0),$3); 
										}

	| 		STRUCT ID 					{ 	
											$$ = createNodeIns(yylineno, "STSPEC","STSPEC: STRUCT ID", 2, createNodeIns(yylineno,"STRUCT",$1,0),createNodeIns(yylineno,"ID", $2, 0));
										}
	;

FUNC: 		ID LP PARAS RP 				{ 
											$$ = createNodeIns(yylineno, "FUNC","FUNC: ID ( PARAS )", 2, createNodeIns(yylineno,"ID" ,$1, 0),$3);
										}
	;


PARAS: 		TYPE ID COMMA PARAS			{ 
											$$ = createNodeIns(yylineno,"PARAS", "PARAS: TYPE ID , PARAS", 3, createNodeIns(yylineno,"TYPE", $1, 0), createNodeIns(yylineno,"ID", $2, 0),$4); 
										}
	| 		TYPE ID 					{ 
											$$ = createNodeIns(yylineno, "PARAS","PARAS: TYPE ID", 2, createNodeIns(yylineno,"TYPE", $1, 0), createNodeIns(yylineno,"ID", $2, 0)); 
										}

	| 		/*EMPTY*/					{
											$$ = createNodeIns(yylineno, "PARAS","PARAS: null", 0);
										}
	;

STMTBLOCK: 	LC DEFS STMTS RC 			{ $$ = createNodeIns(yylineno,"STMTBLOCK", "STMTBLOCK: { DEFS STMTS }", 2, $2,$3); }
	;

STMTS: 		STMT STMTS 					{ $$ = createNodeIns(yylineno, "STMTS","STMTS: STMT STMTS", 2, $1,$2); }
	| 		/*EMPTY*/					{ $$ = createNodeIns(yylineno,"STMTS", "STMTS: null", 0);}
	;

STMT:		EXP SEMI 					{ $$ = createNodeIns(yylineno,"STMT", "STMT: EXP ;", 1, $1); }
	| 		STMTBLOCK 					{ $$ = createNodeIns(yylineno,"STMT", "STMT: STMTBLOCK", 1, $1); }		
	| 		RETURN EXPS SEMI 			{ $$ = createNodeIns(yylineno,"STMT" ,"STMT: RETURN EXPS ;", 2, createNodeIns(yylineno,"RETURN", $1, 0),$2); }		
	| 		IF LP EXPS RP STMT %prec IF_NO_ELSE { $$ = createNodeIns(yylineno,"STMT" ,"STMT: if ( EXPS ) STMT", 2, $3,$5); }		
	| 		IF LP EXPS RP STMT ELSE STMT %prec ELSE_AFTER_IF { $$ = createNodeIns(yylineno,"STMT", "STMT: if ( EXPS ) STMT else STMT", 3, $3,$5,$7);}		
	| 		FOR LP EXP SEMI EXP SEMI EXP RP STMT { $$ = createNodeIns(yylineno, "STMT","STMT: for ( EXP ; EXP ; EXP ) STMT", 4, $3,$5,$7,$9); }		
	| 		CONT SEMI 					{ $$ = createNodeIns(yylineno,"STMT", "STMT: CONT ;", 1, createNodeIns(yylineno, "CONT",$1, 0)); }		
	| 		BREAK SEMI 					{ $$ = createNodeIns(yylineno, "STMT","STMT: BREAK ;", 1, createNodeIns(yylineno, "BREAK",$1, 0)); }		
	| 		READ LP EXPS RP SEMI		{$$ = createNodeIns(yylineno,"STMT", "STMT: read ( EXPS )",1, $3);}
	| 		WRITE LP EXPS RP SEMI		{$$ = createNodeIns(yylineno,"STMT", "STMT: write ( EXPS )",1, $3);}
	;

DEFS: 		TYPE DECS SEMI DEFS			{ $$ = createNodeIns(yylineno,"DEFS", "DEFS: TYPE DECS ; DEFS", 3, createNodeIns(yylineno,"TYPE", $1, 0),$2,$4); }
	| 		STSPEC SEXTVARS SEMI DEFS 	{ $$ = createNodeIns(yylineno, "DEFS","DEFS: STSPEC SEXTVARS ; DEFS", 3, $1,$2,$4); }
	| 		/*EMPTY*/					{$$ = createNodeIns(yylineno, "DEFS","DEFS: null", 0);}
	;

SDEFS:	TYPE SDECS SEMI SDEFS 	{ $$ = createNodeIns(yylineno, "SDEFS","SDEFS: TYPE SDECS ; SDEFS", 3, createNodeIns(yylineno, "TYPE",$1, 0),$2,$4); }
	| 	/*EMPTY*/				{ $$ = createNodeIns(yylineno, "SDEFS", "SDEFS: null", 0);}
	;

SDECS: 	ID COMMA SDECS 			{ $$ = createNodeIns(yylineno,"SDECS", "SDECS: ID , SDECS", 2, createNodeIns(yylineno, "ID",$1, 0),$3); }
	| 	ID 						{ $$ = createNodeIns(yylineno,"SDECS", "SDECS: ID ", 1,createNodeIns(yylineno,"ID",$1,0)); }
	;

DECS: 	VAR 						{ $$ = createNodeIns(yylineno, "DECS", "DECS: VAR", 1, $1); }
	| 	VAR COMMA DECS 				{ $$ = createNodeIns(yylineno, "DECS", "DECS: VAR, DECS", 2, $1,$3); }
	| 	VAR ASSIGN INIT COMMA DECS 	{ $$ = createNodeIns(yylineno, "DECS", "DECS: VAR ASSIGN INIT, DECS", 4, $1,createNodeIns(yylineno,"ASSIGN", $2, 0),$3,$5); }
	| 	VAR ASSIGN INIT 			{ $$ = createNodeIns(yylineno, "DECS", "DECS: VAR ASSIGN INIT", 3, $1,createNodeIns(yylineno,"ASSIGN", $2, 0),$3); }
	;	

VAR:	ID 						{ $$ = createNodeIns(yylineno, "VAR", "VAR: ID", 1,createNodeIns(yylineno,"ID", $1, 0)); }
	|	ID LB INT RB 			{ $$ = createNodeIns(yylineno, "VAR",  "VAR: ID [ INT ]", 2, createNodeIns(yylineno,"ID", $1, 0) ,createNodeIns(yylineno,"INT", $3, 0)); }
	;

INIT: 	EXPS 					{ $$ = createNodeIns(yylineno, "INIT", "INIT: EXPS", 1, $1); }
	| 	LC ARGS RC				{ $$ = createNodeIns(yylineno, "INIT", "INIT: { ARGS }", 1, $2); }
	; 

EXP: 	EXPS 					{ $$ = createNodeIns(yylineno, "EXP", "EXP: EXPS", 1, $1); }
	| 	/*EMPTY*/				{ $$ = createNodeIns(yylineno, "EXP", "EXP: null", 0); }
	;

EXPS: EXPS AND_OP EXPS			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS OR_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS LE_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS GE_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS EQ_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS NE_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS ASSIGN EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS ADD_ASSIGN EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS SUB_ASSIGN EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS MUL_ASSIGN EXPS		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS DIV_ASSIGN EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS AND_ASSIGN EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS MOD_ASSIGN EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS XOR_ASSIGN EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS OR_ASSIGN EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS RIGHT_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS LEFT_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS RIGHT_ASSIGN EXPS 	{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS LEFT_ASSIGN EXPS 	{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS PLUS_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS MINUS_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS BIT_AND_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS PRODUCT_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS DIV_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS MOD_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS LT_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS GT_OP EXPS 			{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS BIT_XOR_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| EXPS BIT_OR_OP EXPS 		{ $$ = createNodeIns(yylineno, "EXPS", $2, 2, $1, $3); }
	| UNARYOP EXPS %prec UNARY 	{ $$ = createNodeIns(yylineno, "EXPS", "EXPS: UNARYOP EXPS", 2, $1, $2); }
	| LP EXPS RP 				{ $$ = createNodeIns(yylineno, "EXPS", "EXPS: ( EXPS )", 1, $2); }
	| ID LP ARGS RP 			{ $$ = createNodeIns(yylineno, "EXPS", "EXPS: ID ( ARGS )", 2, createNodeIns(yylineno,"ID", $1, 0),$3); }
	| ID ARRS 					{ $$ = createNodeIns(yylineno, "EXPS", "EXPS: ID ARRS", 2, createNodeIns(yylineno,"ID", $1, 0),$2); }
	| ID DOT ID 				{ $$ = createNodeIns(yylineno, "EXPS", "EXPS: ID DOT ID", 3, createNodeIns(yylineno,"ID", $1, 0),createNodeIns(yylineno,"DOT", $2, 0),createNodeIns(yylineno, "ID",$3, 0)); }
	| INT 						{ $$ = createNodeIns(yylineno, "INT",  $1, 0); }
	;

ARRS: 		LB EXPS RB  		{ $$ = createNodeIns(yylineno, "ARRS", "ARRS: [ EXPS ]", 1, $2); }
	| 							{ $$ = createNodeIns(yylineno, "ARRS", "ARRS: null", 0);}
	;

ARGS: 		EXPS COMMA ARGS 	{ $$ = createNodeIns(yylineno,"ARGS",  "ARGS: EXPS, ARGS", 2, $1,$3); }
	| 		EXP 				{ $$ = createNodeIns(yylineno,"ARGS", "args", 1, $1); }
	;

UNARYOP:	PLUS_OP 			{ $$ = createNodeIns(yylineno, "UNARYOP", $1, 0); }
	|		MINUS_OP			{ $$ = createNodeIns(yylineno, "UNARYOP", $1, 0); }
	|		BIT_NOT_OP			{ $$ = createNodeIns(yylineno, "UNARYOP", $1, 0); }
	|		LOG_NOT_OP			{ $$ = createNodeIns(yylineno, "UNARYOP", $1, 0); }
	|		INC_OP				{ $$ = createNodeIns(yylineno, "UNARYOP", $1, 0); }
	|		DEC_OP				{ $$ = createNodeIns(yylineno, "UNARYOP", $1, 0); }
	;

%%

#include "header.h"
#include "syntax_tree.h"

int yyerror(const char *msg)
{
	fflush(stdout);
	fprintf(stderr, "Error: %s at line %d\n", msg,yylineno);
	fprintf(stderr, "Parser does not expect '%s\n'",yytext);
}


int main(int argc, char const *argv[])
{
	if (argc == 1){
		fprintf(stderr, "\n%s\n", "Please write your code in the shell. Input <CTRL-D> to exit.");
		fprintf(stderr, "%s\n", "Or you can specify the source code path. \nExample --> $./parser InputFile OutputFile\n");
	}

	freopen(argv[1], "r", stdin);
    	freopen(argv[2], "w", stdout);
	if(!yyparse()){
		fprintf(stderr,"Parsing complete.\n");
		//printTree(root,0);
        root->CodePrint();
        fprintf(stderr,"Translation success\n\n\n");
	}
	else{
		printf("ERROR! parse failed.\n");
	}

	return 0;
}

int yywrap()
{
	return 1;
}
