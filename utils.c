#include <string.h>
#include <stdio.h>

void swap(void* array[], size_t i, size_t j) {
	int size = sizeof(array[0]);
	char tmp[size];
	memcpy(tmp, array+i, size);
	memcpy(array+i, array+j, size);
	memcpy(array+j, tmp, size);
}

void printArray(int array[], char format[], size_t lenght) {
	printf("[ ");
	for	(int i = 0; i < lenght; i++) {
		printf(format, array[i]);
	}
	printf("]");
}

int compInt(int a, int b) {
	return a-b;
}
