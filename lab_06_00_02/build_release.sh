#!/bin/bash

gcc -c items.c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

gcc -c main.c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion
g++ -o app.exe main.o items.o -lm