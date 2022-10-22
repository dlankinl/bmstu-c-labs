#!/bin/bash

lcov -t "coverage" -o coverage.info -c -d . 
genhtml -o report coverage.info

echo "Coverage report was created."