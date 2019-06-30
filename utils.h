#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

#define printArrayInt(a, l) printArray("%d ", a,  l, sizeof(int))
#define COLOR_WHITE "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"

int utils_printf_color(const char *color_code, const char *format, ...);
int debug(const char* format, ...);
int compInt(int*, int*);
void array_swap(void* a, size_t size, size_t i, size_t j);
void swap(void* a, void* b, size_t size);
void printArray(char* format, void* a, size_t length, size_t size);
void debugArray(int a[], size_t);
int compChar(char* a, char* b);

#endif
