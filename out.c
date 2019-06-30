#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "out.h"

int out_debugf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	int ret = 0;

	if(DEBUG)
		ret = vprintf(format, args);

	va_end(args);

	return ret;
}

int out_printf_color(const char *color_code, const char *format, ...) {
	va_list args;
	va_start(args, format);

	int ret = 0;

	printf(color_code);
	ret = vprintf(format, args);
	printf(COLOR_WHITE); 

	va_end(args);

	return ret;
}

void out_print_array(char* format, void* array, size_t length, size_t size) {
	printf("[ ");
	for	(size_t i = 0; i < length; i++) {
		printf(format, *((char*)array+i*size));
	}
	printf("]\n");
}

void out_debug_array(char* format, void* array, size_t length, size_t size) {
	out_debugf("[ ");
	for	(int i = 0; i < length; i++) {
		out_debugf(format, *((char*)array+i*size));
	}
	out_debugf("]\n");
}
