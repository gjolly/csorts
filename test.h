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

void test_fail(Test* t, char reason[]);
void test_assert(Test* t, int boolean, char reason[]);
void test_assert_array_equal(Test* t, void* a, void* b, size_t size, size_t length, int comp(void*, void*));

#endif
