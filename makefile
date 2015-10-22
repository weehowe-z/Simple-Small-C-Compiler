all: a.out

lex.yy.c:	lex.l
	flex lex.l

y.tab.c:	parse.y
	yacc -d parse.y	

a.out:	lex.yy.c y.tab.c
	gcc lex.yy.c  y.tab.c

clean:
	rm y.tab.* lex.yy.c a.out