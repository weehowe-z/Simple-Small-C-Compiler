all: parser

OBJS = parser.o  \
       codegen.o \
       main.o    \
       lex.o  \
       corefn.o  \
	   native.o  \

LLVMCONFIG = llvm-config-3.7
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --libs`

clean:
	$(RM) parser.cpp parser.hpp parser lex.cpp *.bc $(OBJS)

parser.cpp: parser.y
	bison -d -o $@ $^
	
parser.hpp: parser.cpp

lex.cpp: lex.l parser.hpp
	flex -o $@ $^

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<


parser: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

test: parser example.txt
	cat example.txt | ./parser
