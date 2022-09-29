#!/bin/bash

gcc -std=c99 -Wall -Werror -c check_main.c
gcc -std=c99 -Wall -Werror -c ../src/key.c
gcc -std=c99 -Wall -Werror -c ../src/mysort.c
gcc -std=c99 -Wall -Werror -c check_mysort.c
gcc -std=c99 -Wall -Werror -c check_key.c
gcc -std=c99 -Wall -Werror -c ../src/arr_handler.c
gcc -o app.exe key.o mysort.o arr_handler.o check_mysort.o check_key.o check_main.o -lcheck -lpthread -lrt -lsubunit -lm