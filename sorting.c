#include <stdlib.h>
#include <string.h>

#include "utils.c"

void insertion(void* array[], size_t lenght, int comp(void*, void*)) {
	for (size_t i = 0; i < lenght; i++) {
		size_t j = i;
		while (j > 0) {
			if (comp(array[i], array[j]) < 0)
				swap(array, i, j);
		}
	}
}
