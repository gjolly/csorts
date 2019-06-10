#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

int debug(const char* format, ...);
int compInt(int*, int*);
void swap(void* a[], size_t, int, int);
void printArray(int a[], size_t);
void debugArray(int a[], size_t);

#endif
