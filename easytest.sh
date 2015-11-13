#########################################################################
# File Name: easytest.sh
# Created Time: Mon 02 Nov 2015 06:46:41 PM CST
#########################################################################
#!/bin/bash
make clean;
make;
#./a.out
#./a.out test.in test.out
#./a.out reference/testcase/arth/arth.sc  test.out
#./a.out reference/testcase/fib/fib.sc  test.out
#./a.out reference/testcase/gcd/gcd.sc  test.out
#./a.out reference/testcase/if/if.sc  test.out
./a.out reference/testcase/queen/queen.sc  test.out
#./a.out reference/testcase/struct/struct.sc  test.out
