LEX=lex
YACC=yacc
CC="g++"
STD="-std=c++11"

scc:lex.yy.o y.tab.o header.h syntax_tree.h syntax_tree.cpp TreeNode.h TreeNode.cpp utility.h
	$(CC) $(STD) y.tab.c TreeNode.cpp syntax_tree.cpp -g -ly -ll -o scc 

lex.yy.o:lex.yy.c y.tab.h
	$(CC) -c $(STD) lex.yy.c 2> error_lex_yy.err

y.tab.o:y.tab.c header.h syntax_tree.h syntax_tree.cpp TreeNode.h TreeNode.cpp utility.h
	$(CC) -c $(STD) y.tab.c 2> error_y_tab.err

y.tab.c y.tab.h:smallc.y header.h syntax_tree.h syntax_tree.cpp TreeNode.h TreeNode.cpp utility.h
	$(YACC) smallc.y -v -d

lex.yy.c:tokens.l header.h syntax_tree.h syntax_tree.cpp TreeNode.h TreeNode.cpp utility.h
	$(LEX) tokens.l

clean:
	rm -f *.o *.c *.tab.h *.output *.err scc
