#include "sorting.h"
#include "utils.h"

#define SORT_ALGO selection 

int main() {
	int a[] = { 3, 43 , 32, 14, 65, 9, 8 };
	int lenght = sizeof(a)/sizeof(int);

	printArray(a, lenght);

	SORT_ALGO((void**)a, lenght, sizeof(int), (int (*)(void*, void*))compInt);

	printArray(a, lenght);
}
