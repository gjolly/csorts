#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "sorting.h"

#define get_elmt(a, i) (char*)a+(i)*size
#define array(i) get_elmt(array, i) 

SORT(insertion) {
	for (size_t i = 1; i < lenght; i++) {
		size_t j = i;
		while (j > 0 && comp(array(j), array(j-1)) > 0) {
			swap(array, size, j-1, j);
			j--;
		}
	}
}

SORT(selection) {
	for (size_t i = 0; i < lenght; i++) {
		size_t i_max = i;
		for (size_t j = i + 1; j < lenght; j++) {
			if (comp(array(i_max), array(j)) < 0)
				i_max = j;
		}
		swap(array, size, i_max, i);
	}
}

void merge_lists(void* a, size_t lenght_a, void* b, size_t lenght_b, size_t size, int comp(void*, void*)) {
	char* tmp = malloc((lenght_b+lenght_b)*size);	

	size_t i = 0;
	size_t j = 0;
	while (i < lenght_a && j < lenght_b) {
		int* ai = (int*)get_elmt(a,i);
		int* bj = (int*)get_elmt(b,j);
		printf("%lu+%lu=%lu\n", i, j, i+j);
		printf("a=%d, b=%d\n", *ai, *bj);
		if (comp(get_elmt(a, i), get_elmt(b, j)) > 0) {
			memcpy(get_elmt(tmp, i+j), get_elmt(a, i), size);
			i++;
		} else {
			memcpy(get_elmt(tmp, i+j), get_elmt(b, j), size);
			j++;
		}
		printf("tmp at step %lu: ", i+j);
		printArray((int*)tmp, lenght_a+lenght_b);
	}

	printf("%lu+%lu=%lu\n", i, j, i+j);
	if (i < lenght_a) {
		printf("a[%lu:%lu] ", i, lenght_a);
		printArray((int*)get_elmt(a, i), lenght_a-i);
		memcpy(get_elmt(tmp, i+j), get_elmt(a, i), (lenght_a-i)*size);
	} else {
		printf("b[%lu:%lu] ", j, lenght_b);
		printArray((int*)get_elmt(b, j), lenght_b-j);
		printf("%lu+%lu=%lu\n", i, j, i+j);
		memcpy(get_elmt(tmp, i+j), get_elmt(b, j), (lenght_b-j)*size);
	}
	printf("tmp before final merge: ");
	printArray((int*)tmp, lenght_a+lenght_b);

	memcpy(get_elmt(a, 0), tmp, size*(lenght_a+lenght_b));

	printf("End merge: ");
	printArray((int*)tmp, lenght_a+lenght_b);

	free(tmp);
	printf("\n\n");
}

SORT(merge) {
	for (int sublist_size = 1; sublist_size <= lenght/2; sublist_size*=2) {
		printf("Sublist_size=%d\n\n", sublist_size);
		size_t sublist_nb = lenght/sublist_size;
	
		size_t sli; 
		for (sli = 0; sli < sublist_nb/2; sli++) {
			printf("merging (%lu, %lu)\n", 2*sli*sublist_size, (2*sli+1)*sublist_size);
			merge_lists(array(2*sli*sublist_size), sublist_size, array((2*sli+1)*sublist_size), sublist_size, size, comp);
		}
		if ( sublist_nb % 2 == 1) {
			printf("merging remaining (%lu, %lu)\n", (2*sli-1)*sublist_size, 2*sli*sublist_size);
			merge_lists(array((2*sli-2)*sublist_size), sublist_size*2, array(2*sli*sublist_size), sublist_size, size, comp);
		}
	}

}
