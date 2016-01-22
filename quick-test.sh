#########################################################################
# File Name: easytest.sh
# Created Time: Mon 02 Nov 2015 06:46:41 PM CST
#########################################################################
#!/bin/bash
# rm testcase-output-IR/*;
make;
./scc testcase-input/arth/arth.sc  			  	testcase-output-IR/arth.ll
./scc testcase-input/fib/fib.sc  				testcase-output-IR/fib.ll
./scc testcase-input/gcd/gcd.sc                 testcase-output-IR/gcd.ll
./scc testcase-input/io/io.sc          		  	testcase-output-IR/io.ll
./scc testcase-input/if/if.sc                   testcase-output-IR/if.ll
./scc testcase-input/queen/queen.sc             testcase-output-IR/queen.ll
./scc testcase-input/struct/struct.sc           testcase-output-IR/struct.ll
make clean;
#clang-3.7 hello.c -S -emit-llvm