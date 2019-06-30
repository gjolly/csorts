#ifndef H_TEST
#define H_TEST

#define TEST(name) void name ##_test(Test* t)
#define MAX_SIZE_REASON 100
#define MAX_SIZE_NAME 100

typedef struct Test {
	char name[MAX_SIZE_NAME];
	int failed;
	char reason[MAX_SIZE_REASON];
} Test;

void test_fail(Test* t, char reason[]);

#endif
