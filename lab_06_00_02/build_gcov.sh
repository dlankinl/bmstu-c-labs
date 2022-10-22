#!/bin/bash

gcc -c items.c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla --coverage

gcc -c main.c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla --coverage
gcc -o app.exe main.o items.o -lm --coverage
