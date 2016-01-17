all: a.out

lex.yy.c:	lex.l
	flex lex.l

y.tab.c:	parse.y
	yacc -d -v parse.y	

a.out:	lex.yy.c y.tab.c
	#g++ lex.yy.c  y.tab.c
	g++ lex.yy.c  y.tab.c `llvm-config-3.7 --cxxflags --ldflags --libs core`


clean:
	rm y.tab.* lex.yy.c *.out y.output
