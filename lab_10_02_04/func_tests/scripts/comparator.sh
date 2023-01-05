#!/bin/bash

file_1="$1"
file_2="$2"
data_1=$(cat "$file_1")
data_2=$(cat "$file_2")

# echo -e $data_1
# echo -e $data_2
# echo

if [ "$data_1" != "$data_2" ]; then
    exit 1;
else
    exit 0;
fi
