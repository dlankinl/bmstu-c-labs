#!/bin/bash
bash ./build_gcov.sh
cd func_tests/scripts || exit
bash func_tests.sh
cd ../../
gcov -r main.c
