#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>

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

void printArray(int array[], size_t lenght) {
	printf("[ ");
	for	(int i = 0; i < lenght; i++) {
		printf("%d ", array[i]);
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

void swap(void** array, size_t size, size_t i, size_t j) {
	char* tmp = malloc(size);

	memcpy(tmp, (char*)array+i*size, size);
	memcpy((char*)array+i*size, (char*)array+j*size, size);
	memcpy((char*)array+j*size, tmp, size);

	free(tmp);
}

int compInt(int* a, int* b) {
	return *a-*b;
}

