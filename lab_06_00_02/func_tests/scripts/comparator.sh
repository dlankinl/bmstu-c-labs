#!/bin/bash

file_1="$1"
file_2="$2"
data_1=$(cat "$file_1")
data_2=$(cat "$file_2")

if [ "$data_1" != "$data_2" ]; then
    exit 1;
else
    exit 0;
fi
