#!/bin/bash
args=""

if [ "$#" -ge 2 ]; then
    args="$(cat "../data/$2")"
fi


if [ -n "$USE_VALGRIND" ]; then
    if [ -z "$args" ]; then
        eval valgrind -q --error-exitcode=1 ../../app.exe < "$1" > ../data/out.txt
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

exit_code="$?"
if [ "$exit_code" = 0 ]; then
        exit 1;
else
        exit 0;
fi
