all: scc


CC= g++
CPPFLAGS= -std=c++11

clean:
	$(RM) *.o *.c *.tab.h *.output *.log *.ll scc NVM_RC_VERSION=

scc:lex.yy.o y.tab.o header.h syntax_tree.h syntax_tree.cpp TreeNode.h TreeNode.cpp utility.h
	$(CC) -o $@  $(CPPFLAGS) y.tab.c TreeNode.cpp syntax_tree.cpp -g -ly -ll

y.tab.c y.tab.h: parser.y
	yacc parser.y -v -d

lex.yy.c:	lex.l
	flex 	lex.l

lex.yy.o: lex.yy.c y.tab.h
	$(CC) -c $(CPPFLAGS) lex.yy.c 2> error.lex.log

y.tab.o: y.tab.c header.h syntax_tree.h syntax_tree.cpp TreeNode.h TreeNode.cpp utility.h
	$(CC) -c $(CPPFLAGS) y.tab.c 2> error.y.log
