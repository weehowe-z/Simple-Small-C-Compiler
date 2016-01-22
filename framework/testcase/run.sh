# !bin/bash
#set -evx

make 

scc="./scc"

testcase=`find ./testcase -name *.sc`
for test in ${testcase}
do
    # echo $test
    target=$(echo "${test}" | sed "s@.sc@.ll@" )
    $scc "${test}"  "${target}"
done
rm scc 

for test in ${testcase}
do
    echo "$test"
    dir="$(dirname $test)"/data/
    target=$(echo "${test}" | sed "s@.sc@.ll@" )
    ls "${dir}" | xargs -I % cat "${dir}"%
    lli "$target"
done
