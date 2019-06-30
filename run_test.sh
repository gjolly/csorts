#!/bin/bash

set -e

#-----------------------------------------------------
# Get user input
SORT_ALGO=${SORT_ALGO:-merge}

printf "Compiling with SORT_ALGO=\e[96m%s\e[0m\n\n" "$SORT_ALGO"

#-----------------------------------------------------
# Build the test files for compilation
./build_tests.sh

#-----------------------------------------------------
# Compile with the generated test files
make -B test SORT_ALGO="$SORT_ALGO" > /dev/null

#-----------------------------------------------------
# Run the tests
./test "$1"

