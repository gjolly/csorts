#!/bin/bash


#-----------------------------------------------------------------
# Get user input
SORT_ALGO=${SORT_ALGO:-merge}

printf "Compiling with SORT_ALGO=\e[96m%s\e[0m\n\n" "$SORT_ALGO"

#-----------------------------------------------------------------
# Build the test files for compilation
# If an expression is provided, only the tests matching this
# Expression are build

exp="$1"
./build_tests.sh "$exp"
if [ $? == 1 ]; then
	printf "\e[33mNo test found\e[0m\n"
	exit 1
fi

#-----------------------------------------------------------------
# Compile with the generated test files

set -e # if the make fails, we don't want to run the tests

make -B test SORT_ALGO="$SORT_ALGO" > /dev/null

#-----------------------------------------------------------------
# Run the tests
./test

