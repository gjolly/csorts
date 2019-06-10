#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

#define printArrayInt(a, l) printArray("%d ", a,  l, sizeof(int))

int debug(const char* format, ...);
int compInt(int*, int*);
void swap(void* a[], size_t, int, int);
void printArray(char* format, void* a, size_t length, size_t size);
void debugArray(int a[], size_t);
int compChar(char* a, char* b);

#endif
