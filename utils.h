#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

int utils_printf_color(const char *color_code, const char *format, ...);
int compInt(int*, int*);
void array_swap(void* a, size_t size, size_t i, size_t j);
void swap(void* a, void* b, size_t size);
int compChar(char* a, char* b);

#endif
