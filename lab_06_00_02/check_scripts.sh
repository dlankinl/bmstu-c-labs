#!/bin/bash
shellcheck -- *.sh
cd ./func_tests/scripts/ || exit
shellcheck -- *.sh
cd ../../
