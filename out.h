#ifndef H_OUT
#define H_OUT

#include <stdlib.h>

#define out_print_array_int(a, l) out_print_array("%d ", a, l, sizeof(int))
#define out_debug_array_int(a, l) out_debug_array("%d ", a, l, sizeof(int))
#define COLOR_WHITE "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"

#define DEBUG 0

int out_printf_color(const char* color_code, const char* format, ...);
int out_debugf(const char* format, ...);
void out_print_array(char* format, void* a, size_t lenght, size_t size);
void out_debug_array(char* format, void* array, size_t length, size_t size);

#endif
