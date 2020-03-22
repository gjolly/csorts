#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>

#define SORT(name) \
    void name(void* array[], size_t length, size_t size, int comp(void*, void*))

SORT(insertion);
SORT(selection);
SORT(merge);
SORT(heap);

#endif
