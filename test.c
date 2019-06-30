#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "test.h"
#include "out.h"
#include "utils.h"
#include "test_functions.h"

#define FAIL_FAST 0

void test_fail(Test* t, char reason[]) {
	t->failed = 1;
	strncpy(t->reason, reason, MAX_SIZE_REASON);
}

void test_assert(Test* t, int boolean, char reason[]) {
	if (!boolean) {
		test_fail(t, reason);
	}
}

void test_assert_array_equal(Test* t, void* a, void* b, size_t size, size_t length, int comp(void*, void*)) {
	for (int i = 0; i < length; i++) {
		if (comp((char*)a+i*size, (char*)b+i*size) != 0) {
			test_fail(t, "Arrays not equal");
			return;
		}
	}
}

void test_after_run(Test* t) {
	if (t->failed) {
		out_printf_color(COLOR_RED, "FAILED");
		printf(": %s: %s\n", t->name, t->reason);
		t->failed = 0;
		if (FAIL_FAST)
			exit(1);
	} else {
		out_printf_color(COLOR_GREEN, "SUCCES");
		printf(": %s\n", t->name);
	}
}

void test_before_run(Test* t, char name[MAX_SIZE_NAME]){
	strncpy(t->name, name, MAX_SIZE_REASON);
}

int main() {
	Test t;
#include "test_functions_call"

	return 0;
}
