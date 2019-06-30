#ifndef H_TEST
#define H_TEST

#include <stdlib.h>

#define TEST(name) void name ##_test(Test* t)
#define MAX_SIZE_REASON 100
#define MAX_SIZE_NAME 100

typedef struct Test {
	char name[MAX_SIZE_NAME];
	int failed;
	char reason[MAX_SIZE_REASON];
} Test;

// test_fail mark the test as 'failed'.
// If FAILED_FAST is TRUE, this will stop the
// test run.
void test_fail(Test* t, char reason[]);

// test_assert marks the test as failed if the
// boolean is FALSE.
void test_assert(Test* t, int boolean, char reason[]);

// test_assert_array_equal mark the test as
// failed if the two arrays are different.
void test_assert_array_equal(Test* t, void* a, void* b, size_t size, size_t length, int comp(void*, void*));

#endif
