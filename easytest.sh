#########################################################################
# File Name: easytest.sh
# Created Time: Mon 02 Nov 2015 06:46:41 PM CST
#########################################################################
#!/bin/bash
make clean;
make;
#./a.out
./a.out test.in
#./a.out reference/testcase/arth/arth.sc
#./a.out reference/testcase/fib/fib.sc
