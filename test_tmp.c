#include <stdlib.h>
#include <string.h>

#include "test.h"
#include "test_functions.h"

void test_fail(Test* t, char reason[]) {
    t->failed = 1;
    strncpy(t->reason, reason, 100);
}

int main() {

    toto_test(t)
    fist_test(t)
}
