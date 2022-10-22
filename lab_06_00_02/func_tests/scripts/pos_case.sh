#!/bin/bash

args=""

if [ "$#" -ge 3 ]; then
    args="$(cat "../data/$3")"
fi

if [ -n "$USE_VALGRIND" ]; then
    if [ -z "$args" ]; then
        eval valgrind -q --error-exitcode=1 ../../app.exe "$args"  < "$1" > ../data/out.txt
    else
        eval valgrind -q --error-exitcode=1 ../../app.exe "$args" > ../data/out.txt
    fi
else
    if [ -z "$args" ]; then
        eval ../../app.exe < "$1" > ../data/out.txt
    else
        eval ../../app.exe "$args" > ../data/out.txt
    fi
fi

./comparator.sh "../data/out.txt" "$2"

exit_code="$?"
if [ "$exit_code" = 0 ]; then
    exit 0;
else
    exit 1;
fi
