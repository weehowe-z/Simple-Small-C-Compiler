#include <iostream>
#include "codegen.h"
#include "node.h"

using namespace std;

extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern NBlock* programBlock;

void createCoreFunctions(CodeGenContext& context);

int main(int argc, char const *argv[])
{
	if (argc == 1){
		fprintf(stderr, "\n%s\n", "Please write your code in the shell. Input <CTRL-D> to exit.");
		fprintf(stderr, "%s\n", "Or you can specify the source code path. \nexample --> $./parser InputFile OutputFile\n");
		yyparse();
	}
	else if (argc == 2){
		FILE *fin = fopen(argv[1],"r");
		if (!fin) { 
			return fprintf (stderr, "Error: Input file '%s' does not exist!\n", argv[1]);
		}
		yyin = fin;
		while(!feof(yyin)){
			yyparse();
		}
		// if (printFlag) {
		// 	pTree.printQueue(yyout);
		// }
		fclose(fin);
	}
	else if (argc == 3){
		FILE *fin = fopen(argv[1], "r");
		FILE *fout = fopen(argv[2],"w");
		if (!fin) {
			return fprintf (stderr, "Error: Input file '%s' does not exist!\n", argv[1]);
		}
		if (!fout) {
			return fprintf (stderr, "Error: Open output file '%s' failed!\n", argv[2]);
		}
		yyin = fin;
		yyout = fout;
		while (!feof(yyin)){
			yyparse();
		}
		// if (printFlag) {
		// 	pTree.printQueue(yyout);
		// }
		fclose(fin);
		fclose(fout);
	}
	else {
		return fprintf (stderr, "Error: Invalid number of args!\n");
	}


	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	
	CodeGenContext context;
	createCoreFunctions(context);
	context.generateCode(*programBlock);
	context.saveByteCode("haha.bc");
	context.runCode();
	
	return 0;
}

