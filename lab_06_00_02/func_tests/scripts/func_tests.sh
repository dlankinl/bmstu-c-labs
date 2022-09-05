#!/bin/bash

counter=1
failed_tests=0
file_in=$"../data/pos_0${counter}_in.txt"
file_out=$"../data/pos_0${counter}_out.txt"
args=$"../data/pos_0${counter}_args.txt"

while [ -f "$file_in" ]; do
    ./pos_case.sh "$file_in" "$file_out" "$args"
    exit_code="$?"
    if [ "$exit_code" = "0" ]; then
        echo -e "Positive test №${counter} | \033[32mSUCCEED\033[0m"
    else
        echo -e "Positive test №${counter} | \033[31mFAILED\033[0m"
        failed_tests=$((failed_tests+1))
    fi
    counter=$((counter+1))
    if [ "$counter" -gt "9" ]; then
        file_in=$"../data/pos_${counter}_in.txt"
        file_out=$"../data/pos_${counter}_out.txt"
        args=$"../data/pos_0${counter}_args.txt"
    elif [ "$counter" -le "9" ] && [ "$counter" -gt "1" ]; then
        file_in=$"../data/pos_0${counter}_in.txt"
        file_out=$"../data/pos_0${counter}_out.txt"
        args=$"../data/pos_0${counter}_args.txt"
    fi
done

counter=1
file_in=$"../data/neg_0${counter}_in.txt"
file_out=$"../data/neg_0${counter}_out.txt"
args=$"../data/neg_0${counter}_args.txt"

while [ -f "$file_in" ]; do
    ./neg_case.sh "$file_in" "$file_out" "$args"
    exit_code="$?"
    if [ "$exit_code" = "0" ]; then
        echo -e "Negative test №${counter} | \033[32mSUCCEED\033[0m"
    else
        echo -e "Negative test №${counter} | \033[31mFAILED\033[0m"
        failed_tests=$((failed_tests+1))
    fi
    counter=$((counter+1))
    if [ "$counter" -gt "9" ]; then
        file_in=$"../data/neg_${counter}_in.txt"
        file_out=$"../data/neg_${counter}_out.txt"
        args=$"../data/neg_0${counter}_args.txt"
    elif [ "$counter" -le "9" ] && [ "$counter" -gt "1" ]; then
        file_in=$"../data/neg_0${counter}_in.txt"
        file_out=$"../data/neg_0${counter}_out.txt"
        args=$"../data/neg_0${counter}_args.txt"
    fi
done

echo "Failed ${failed_tests} tests."
rm "../data/out.txt"
