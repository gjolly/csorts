#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>

#include "utils.h"

#define DEBUG 0 

int debug(const char *format, ...) {
	va_list args;
	va_start(args, format);

	int ret = 0;

	if(DEBUG)
		ret = vprintf(format, args);

	va_end(args);

	return ret;
}

int utils_printf_color(const char *color_code, const char *format, ...) {
	va_list args;
	va_start(args, format);

	int ret = 0;

	printf(color_code);
	ret = vprintf(format, args);
	printf(COLOR_WHITE); 

	va_end(args);

	return ret;
}

void printArray(char* format, void* array, size_t lenght, size_t size) {
	printf("[ ");
	for	(size_t i = 0; i < lenght; i++) {
		printf(format, *((char*)array+i*size));
	}
	printf("]\n");
}

void debugArray(int array[], size_t lenght) {
	debug("[ ");
	for	(int i = 0; i < lenght; i++) {
		debug("%d ", array[i]);
	}
	debug("]\n");
}

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
