#!/bin/bash

test_function_call="test_functions_call.tmp"
test_function_signatures="test_functions_signatures.tmp"

#------------------------------------------------------------------------
# Clean up old runs

rm -rf $test_function_signatures $test_function_call

#------------------------------------------------------------------------
# Extract function names from _test files

# list all the tests function
# from the test files
test_func="$(grep -hE 'TEST(.*)' *_test.c)"
test_func_name="$(echo "$test_func" | sed "s/.*TEST(\(.*\)).*/\1_test/g")"

#------------------------------------------------------------------------
# Generate a file calling all the test functions

for tf in $test_func_name; do
	printf "    test_before_run(&t, \"%s\"), %s(&t); test_after_run(&t);\n" "$tf" "$tf" >> $test_function_call
	printf "void %s(Test* t);\n" "$tf" >> $test_function_signatures
done


