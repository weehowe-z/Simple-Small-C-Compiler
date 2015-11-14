# Simple Small C Compiler


## Introduction

A simplified compiler frontend, including a **lexical analyzer** and a **syntax analyzer**, for `Small-C`, which is a C-like language containing a subset of the C programming language. Besides, it also implements a **code generator** to translate the intermediate representation, which is produced by syntax analyzer, into LLVM instructions.


Using **Flex**, **Bison** and **LLVM**

## Structure

- **lex.l**       	Lexical Analyzer
- **parse.y**     	Syntax Analyzer
- **node.h**      	Handle with the token node and tree structures
- **makefile**    	`make` to easy compile the compiler, and `make clean` to delete useless files
- **easy-test.sh** 	shell script for easy test, test input is based on 7 given testcase

## Usage

### Quick test with testcase

```
$ chmod +x easy-test.sh
$ ./easy-test.sh
```

All the testcase output will be saved at `testcase-output`.

**ATTENSION!!**  As I print the parse tree in lines for beauty, like this:

```
                  PROGRAM                  
                     |
                     |
                  EXTDEFS                  
                     |
                 |-------------------|
              EXTDEF              EXTDEFS 
                 |                   |
  |---------|-------------|          |
SPEC      FUNC        STMTBLOCK      ϵ 
  |         |             |
  |    |-|---|---| |---|----|---|
TYPE  ID ( PARAS ) { DEFS STMTS } 
  |    |     |         |    |
  |    |     |         |    |
 int main    ϵ         ϵ    ϵ 
 ```
 
 Thus, the output parse is **very wide** when the input code is complex. 
 
 You may need `MonoDevelop` under Ubuntu or some other text editors to open the output, otherwise some text editors like `sublime text3` will automatically create a new line for wide output which may affect the beauty. Or you can just input fewer codes to see the output.
 
### Run test manually

```
$ make
```

#### 1. Input from command line and output on command line
```
$ ./a.out
```

#### 2. Input from file and output on command line
```
$ ./a.out   inputPath
```

#### 3. Input from file and output to file
```
$ ./a.out   inputPath   outputPath
```

### Highlights

#### 1. Error Handling
If there is a syntax error, the compiler will return which line and what input causes the error.
For example:
```
Input:
int mian(
}

Output
YACC: syntax error at line 2
YACC: does not expect }
```

#### 2. Clear Tree Structure Printing
As mentioned above, I don't use preorder to print the parse tree. Instead, I use complicated functions to print a more distinct and clear tree structures for sake of beauty and more intuitive sense of the parse tree.

## Other

**All related information can be also found at [github](https://github.com/weehowe-z/Simple-Small-C-Compiler).**

**Any problems happen to my code(can't run.. etc), plz contact me at [weehowe.z@gmail.com](mailto:weehowe.z@gmail.com)**




 

