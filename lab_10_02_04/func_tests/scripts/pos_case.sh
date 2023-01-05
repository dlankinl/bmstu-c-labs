#!/bin/bash

args=""

if [ "$#" -ge 3 ]; then
    args="$(cat "$3")"
fi

if [ -n "$USE_VALGRIND" ]; then
    if [ -z "$args" ]; then
        eval valgrind -q --error-exitcode=1 ./app.exe "$args"  < "$1" > func_tests/data/out.txt
    else
        eval valgrind -q --error-exitcode=1 ./app.exe "$args" > func_tests/data/out.txt
    fi
else
    if [ -z "$args" ]; then
        eval ./app.exe < "$1" > func_tests/data/out.txt
    else
        eval ./app.exe "$args" > ./func_tests/data/out.txt
        # echo $args
        # eval ./app.exe "$args"
    fi
fi

./func_tests/scripts/comparator.sh "func_tests/data/out.txt" "$2"

# echo $(cat "func_tests/data/out.txt")
# echo $(cat $2)

exit_code="$?"
if [ "$exit_code" = 0 ]; then
    exit 0;
else
    exit 1;
fi
