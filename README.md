# Simple Small C Compiler


## Introduction

A simplified compiler frontend, including a **lexical analyzer** and a **syntax analyzer**, for `Small-C`, which is a C-like language containing a subset of the C programming language. Besides, it also implements a **code generator** to translate the intermediate representation, which is produced by syntax analyzer, into LLVM instructions.


Using **Flex**, **Bison** and **LLVM**

## Structure

- lex.l       	Lexical Analyzer
- parse.y     	Syntax Analyzer
- node.h      	Handle with the token node and tree structures
- makefile    	`make` to easy compile the compiler, and `make clean` to delete useless files
- easy-test.sh 	shell script for easy test, test input is based on 7 given testcase


