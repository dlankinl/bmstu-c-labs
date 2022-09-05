#!/bin/bash

args=""

if [ "$#" -ge 3 ]; then
    args="$(cat "../data/$3")"
fi

if [ -n "$USE_VALGRIND" ]; then
    eval valgrind -q --error-exitcode=1 ../../app.exe "$args"  < "$1" > ../data/out.txt
else
    eval ../../app.exe "$args"  < "$1" > ../data/out.txt
fi

./comparator.sh "../data/out.txt" "$2"

exit_code="$?"
if [ "$exit_code" = 0 ]; then
    exit 0;
else
    exit 1;
fi
