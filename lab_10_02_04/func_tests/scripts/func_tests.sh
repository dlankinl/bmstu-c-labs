#!/bin/bash

counter=1
failed_tests=0
file_in=$"func_tests/data/pos_0${counter}_in.txt"
file_out=$"func_tests/data/pos_0${counter}_out.txt"
args=$"func_tests/data/pos_0${counter}_args.txt"

while [ -f "$file_in" ]; do
    if [ -f "$args" ]; then
        ./func_tests/scripts/pos_case.sh "$file_in" "$file_out" "$args"
    else
        ./func_tests/scripts/pos_case.sh "$file_in" "$file_out"
    fi
    exit_code="$?"
    if [ "$exit_code" = "0" ]; then
        echo -e "Positive test №${counter} | \033[32mSUCCEED\033[0m"
    else
        echo -e "Positive test №${counter} | \033[31mFAILED\033[0m"
        failed_tests=$((failed_tests+1))
    fi
    counter=$((counter+1))
    if [ "$counter" -gt "9" ]; then
        file_in=$"func_tests/data/pos_${counter}_in.txt"
        file_out=$"func_tests/data/pos_${counter}_out.txt"
        args=$"func_tests/data/pos_${counter}_args.txt"
    elif [ "$counter" -le "9" ] && [ "$counter" -gt "1" ]; then
        file_in=$"func_tests/data/pos_0${counter}_in.txt"
        file_out=$"func_tests/data/pos_0${counter}_out.txt"
        args=$"func_tests/data/pos_0${counter}_args.txt"
    fi
done


counter=1
file_in=$"func_tests/data/neg_0${counter}_in.txt"
args=$"func_tests/data/neg_0${counter}_args.txt"

while [ -f "$file_in" ]; do
    if [ -f "$args" ]; then
        ./func_tests/scripts/neg_case.sh "$file_in" "$args"
    else
        ./func_tests/scripts/neg_case.sh "$file_in"
    fi
    exit_code="$?"
    if [ "$exit_code" = "0" ]; then
        echo -e "Negative test №${counter} | \033[32mSUCCEED\033[0m"
    else
        echo -e "Negative test №${counter} | \033[31mFAILED\033[0m"
        failed_tests=$((failed_tests+1))
    fi
    counter=$((counter+1))
    if [ "$counter" -gt "9" ]; then
        file_in=$"func_tests/data/neg_${counter}_in.txt"
        args=$"func_tests/data/neg_${counter}_args.txt"
    elif [ "$counter" -le "9" ] && [ "$counter" -gt "1" ]; then
        file_in=$"func_tests/data/neg_0${counter}_in.txt"
        args=$"func_tests/data/neg_0${counter}_args.txt"
    fi
done

echo "Failed ${failed_tests} tests."
rm "func_tests/data/out.txt"
