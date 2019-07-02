#!/bin/bash

# Find all the tests function to compile. Add their signatures in one
# file and their call in an other
# Usage: $0 [EXP]
# If an EXP is provided, only the tests matching this EXP are built.
# Return: 1 if no test was found

#------------------------------------------------------------------------
# Define output files

test_function_call="test_functions_call.tmp"
test_function_signatures="test_functions_signatures.tmp"

#------------------------------------------------------------------------
# Clean up old runs

rm -rf $test_function_signatures $test_function_call

#------------------------------------------------------------------------
# Reading user input
exp=".*$1.*"

#------------------------------------------------------------------------
# Extract function names from _test files

# list all the tests function
# from the test files
test_func="$(grep -hE "TEST($exp)" *_test.c)"
test_func_name="$(echo "$test_func" | sed "s/.*TEST(\(.*\)).*/\1/g")"

#------------------------------------------------------------------------
# Generate a file calling all the test functions
if [ -z "$test_func_name" ]; then
	exit 1
fi

for tf in $test_func_name; do
	printf "    test_before_run(&t, \"%s\"), %s_test(&t); test_after_run(&t);\n" "$tf" "$tf" >> $test_function_call
	printf "void %s_test(Test* t);\n" "$tf" >> $test_function_signatures
done


