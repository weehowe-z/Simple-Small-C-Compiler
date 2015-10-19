all: a.out

lex.yy.c:	calculator.l
	flex calculator.l

y.tab.c:	calculator.y
	yacc -d calculator.y	

a.out:	lex.yy.c y.tab.c
	gcc lex.yy.c  y.tab.c -ly -ll -lm

clean:
	rm y.tab.* lex.yy.c a.out