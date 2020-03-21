#!/bin/bash

VALGRIND="$(command -v valgrind)"

if [[ $? -eq 0 ]]; then
  echo "Running with Valgrind"
  VALGRIND_CMD="$VALGRIND --leak-check=full -q --error-exitcode=1"
fi

#-----------------------------------------------------------------
# Get user input
SORT_ALGO=${SORT_ALGO:-heap}

printf "Compiling with SORT_ALGO=\e[96m%s\e[0m\n" "$SORT_ALGO"

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
${VALGRIND_CMD} ./test 2>> valgrind_report.txt

