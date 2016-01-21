%{
	#include "node.h"
        #include <cstdio>
        #include <cstdlib>
	NBlock *programBlock; /* the top level root node of our final AST */

	extern int yylex();
	extern int yylineno;
	extern char *yytext;
	int yyerror (const char *msg);
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
%token <string> TIDENTIFIER TINTEGER TDOUBLE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> SEMI COMMA DOT  LP RP LB RB LC RC STRUCT RETURN IF THEN ELSE BREAK CONT FOR
%token <token> TPLUS TMINUS TMUL TDIV
%token <token> TRETURN TEXTERN
%token <token> PLUS

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <expr> numeric expr 
%type <varvec> func_decl_args
%type <exprvec> call_args
%type <block> program stmts block
%type <stmt> stmt var_decl func_decl extern_decl
%type <token> comparison

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : stmts { programBlock = $1; }
		;
		
stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
	  | stmts stmt { $1->statements.push_back($<stmt>2); }
	  ;

stmt :
	;

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