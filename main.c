#include <stdio.h>

#include "sorting.h"
#include "utils.h"

#define SORT_ALGO merge 

void basic() {
	int a[] = { 3, 43 , 32, 14, 65, 9, 8 };
	int lenght = sizeof(a)/sizeof(int);

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);
	printf("\n");
}

void basic2() {
	int a[] = { 10, 9 , 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int lenght = sizeof(a)/sizeof(int);

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);
	printf("\n");
}

void basic3() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int lenght = sizeof(a)/sizeof(int);

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);
	printf("\n");
}

void empty() {
	int* a = NULL;
	int lenght = 0;

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);
	printf("\n");
}

void hundred() {
	int a[110];

	int lenght = 110;

	for (int i = 0; i < lenght; i++) {
		a[i] = i;
	}

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);
}

int main() {
	basic();
	basic2();
	basic3();
	empty();
	hundred();

	return 0;
}
