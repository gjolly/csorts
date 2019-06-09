#include "sorting.h"
#include "utils.h"

#define SORT_ALGO merge

void basic() {
	int a[] = { 3, 43 , 32, 14, 65, 9, 8 };
	int lenght = sizeof(a)/sizeof(int);

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);
}

void thousand(int size) {
	int* a = malloc(size);

	for (int i = 0; i < size; i++) {
		a[i] = size - i;
	}
	
	int lenght = size;

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);

	free(a);
}

int main() {
	basic();
	thousand(100);
	thousand(0);

	return 0;
}
