#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "sorting.h"

#define get_elmt(x, i) ((char*)x+(i)*size)
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
	char* tmp = malloc((lenght_a+lenght_b)*size);	

	size_t i = 0;
	size_t j = 0;
	while (i < lenght_a && j < lenght_b) {
		int* ai = (int*)get_elmt(a,i);
		int* bj = (int*)get_elmt(b,j);
		debug("a=%d, b=%d\n", *ai, *bj);
		if (comp(get_elmt(a, i), get_elmt(b, j)) > 0) {
			memcpy(get_elmt(tmp, i+j), get_elmt(a, i), size);
			i++;
		} else {
			memcpy(get_elmt(tmp, i+j), get_elmt(b, j), size);
			j++;
		}
		debug("tmp at step %lu: ", i+j);
		debugArray((int*)tmp, lenght_a+lenght_b);
	}

	if (i < lenght_a) {
		debug("a[%lu:%lu] ", i, lenght_a);
		debugArray((int*)get_elmt(a, i), lenght_a-i);
		memcpy(get_elmt(tmp, i+j), get_elmt(a, i), (lenght_a-i)*size);
	} else {
		debug("b[%lu:%lu] ", j, lenght_b);
		debugArray((int*)get_elmt(b, j), lenght_b-j);
		debug("%lu+%lu=%lu\n", i, j, i+j);
		memcpy(get_elmt(tmp, i+j), get_elmt(b, j), (lenght_b-j)*size);
	}

	memcpy(get_elmt(a, 0), tmp, size*(lenght_a+lenght_b));

	debug("End merge: ");
	debugArray((int*)tmp, lenght_a+lenght_b);

	free(tmp);
	debug("\n\n");
}

SORT(merge) {
	size_t remains = 0;
	for (int sublist_size = 1; sublist_size <= lenght/2; sublist_size*=2) {

		debug("Sublist_size=%d\n\n", sublist_size);
		size_t sublist_nb = lenght/sublist_size;
	
		size_t sli; 
		for (sli = 0; sli < sublist_nb/2; sli++) {
			debug("merging (%lu, %lu)\n", 2*sli*sublist_size, (2*sli+1)*sublist_size);
			if (sli + 1 < sublist_nb/2 ) {
				// Not the last one
				merge_lists(array(2*sli*sublist_size), sublist_size, array((2*sli+1)*sublist_size), sublist_size, size, comp);
			} else if (sublist_nb % 2 == 0) {
				// if it is the last one
				merge_lists(array(2*sli*sublist_size), sublist_size, array((2*sli+1)*sublist_size), sublist_size+remains, size, comp);
			} else {
				merge_lists(array(2*sli*sublist_size), sublist_size, array((2*sli+1)*sublist_size), sublist_size, size, comp);
			}
			debug("sli in loop: %d\n", sli);
		}
			debug("sli after loop: %d\n", sli);
		if (sublist_nb % 2 == 1) {
			debug("merging remaining (%lu, %lu)\n", 2*(sli-1)*sublist_size, 2*sli*sublist_size);
			merge_lists(array(2*(sli-1)*sublist_size), sublist_size*2, array(2*sli*sublist_size), sublist_size+remains, size, comp);
			remains += sublist_size;
		}
		debug("remains: %lu\n", remains);
	}
}
