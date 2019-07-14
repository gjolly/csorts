#include <string.h>
#include <malloc.h>

#include "utils.h"

void swap(void* a, void* b, size_t size) {
    char* tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}

void array_swap(void* array, size_t size, size_t i, size_t j) {
    swap((char*)array+j*size, (char*)array+i*size, size);
}

int compInt(int* a, int* b) {
    return *a-*b;
}

int compChar(char* a, char* b) {
    return *a-*b;
}
