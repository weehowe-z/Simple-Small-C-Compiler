#########################################################################
# File Name: easytest.sh
# Created Time: Mon 02 Nov 2015 06:46:41 PM CST
#########################################################################
#!/bin/bash
make clean;
make;
./a.out testcase-input/arth/arth.sc  			  testcase-output/arth.out
./a.out testcase-input/fib/fib.sc  				  testcase-output/fib.out
./a.out testcase-input/gcd/gcd.sc                 testcase-output/gcd.out
./a.out testcase-input/io/io.sc          		  testcase-output/io.out
./a.out testcase-input/if/if.sc                   testcase-output/if.out
./a.out testcase-input/queen/queen.sc             testcase-output/queen.out
./a.out testcase-input/struct/struct.sc           testcase-output/struct.out
make clean;
