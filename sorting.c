#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "sorting.h"

#define get_elmt(a, i) (char*)a+i*size
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

void merge_lists(void** a, size_t lenght_a, void** b, size_t lenght_b, size_t size, int comp(void*, void*)) {
	size_t lenght = (lenght_a>lenght_b)?lenght_b:lenght_a; 
	for (int i = 0; i < lenght; i++) {
		// sort using an auxiliary array
	}
}

SORT(merge) {
	for (int sublist_size = 2; sublist_size <= lenght; sublist_size*=2) {
		size_t sublist_nb = lenght/sublist_size;
	
		size_t sli; 
		for (sli = 0; sli < sublist_nb; sli+=2) {
			merge_lists(array(sli*sublist_size), sublist_size, array((sli+1)*sublist_size), sublist_size, size, comp);
		}
		if (sli == sublist_nb - 2) {
			merge_lists(array((sli-1)*(sublist_size+1)), sublist_size*2, array((sli+1)*sublist_size), sublist_size, size, comp);
		}
	}

}
