#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "test.h"
#include "utils.h"
#include "test_functions.h"

#define FAIL_FAST 0

void test_fail(Test* t, char reason[]) {
	t->failed = 1;
	strncpy(t->reason, reason, MAX_SIZE_REASON);
}

void test_after_run(Test* t) {
	if (t->failed) {
		utils_printf_color(COLOR_RED, "FAILED");
		printf(": %s: %s\n", t->name, t->reason);
		t->failed = 0;
		if (FAIL_FAST)
			exit(1);
	} else {
		utils_printf_color(COLOR_GREEN, "SUCCES");
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
