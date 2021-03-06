#include <stdio.h>

#include "out.h"
#include "sorting.h"
#include "test.h"
#include "utils.h"

#ifndef SORT_ALGO
#define SORT_ALGO insertion
#endif

TEST(sort_basic) {
    int a[] = {3, 43, 32, 14, 65, 9, 8};
    int out[] = {3, 8, 9, 14, 32, 43, 65};
    int length = sizeof(a) / sizeof(int);

    out_debug_array_int(a, length);

    SORT_ALGO((void*)a, length, sizeof(int), (int (*)(void*, void*))compInt);

    test_assert_array_equal(t, a, out, sizeof(int), length,
                            (int (*)(void*, void*))compInt);
    out_debug_array_int(a, length);
    out_debugf("\n");
}

TEST(sort_basic2) {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int out[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof(int);

    out_debug_array_int(a, length);

    SORT_ALGO((void*)a, length, sizeof(int), (int (*)(void*, void*))compInt);

    test_assert_array_equal(t, a, out, sizeof(int), length,
                            (int (*)(void*, void*))compInt);
    out_debug_array_int(a, length);
    out_debugf("\n");
}

TEST(sort_basic3) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int out[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof(int);

    out_debug_array_int(a, length);

    SORT_ALGO((void*)a, length, sizeof(int), (int (*)(void*, void*))compInt);

    test_assert_array_equal(t, a, out, sizeof(int), length,
                            (int (*)(void*, void*))compInt);
    out_debug_array_int(a, length);
    out_debugf("\n");
}

TEST(sort_empty) {
    int* a = NULL;
    int length = 0;

    out_debug_array_int(a, length);

    SORT_ALGO((void*)a, length, sizeof(int), (int (*)(void*, void*))compInt);

    test_assert(t, a == NULL, "a is not NULL");
    out_debug_array_int(a, length);
    out_debugf("\n");
}

TEST(sort_hundred) {
    int a[110];
    int out[110];

    int length = 110;

    for (int i = 0; i < length; i++) {
        out[i] = i;
        a[i] = 110 - i - 1;
    }

    out_debug_array_int(a, length);

    SORT_ALGO((void*)a, length, sizeof(int), (int (*)(void*, void*))compInt);

    test_assert_array_equal(t, a, out, sizeof(int), length,
                            (int (*)(void*, void*))compInt);
    out_debug_array_int(a, length);
    out_debugf("\n");
}

TEST(sort_characters) {
    char a[] = {'s', 'a', 'g', 'j', 'f', 'd', 'e',
                'h', 'u', 'r', 't', '3', 'b'};

    int length = 13;

    out_debug_array("%c ", a, length, sizeof(char));

    SORT_ALGO((void*)a, length, sizeof(char), (int (*)(void*, void*))compChar);

    out_debug_array("%c ", a, length, sizeof(char));
    out_debugf("\n");
}
