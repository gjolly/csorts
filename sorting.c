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
	
	// tmp is a auxiliary array used to merge 
	// a and b
	char* tmp = malloc((lenght_a+lenght_b)*size);	

	size_t i = 0; // indexes a
	size_t j = 0; // indexes b

	// Choose the biggest item between a[j] and b[j]
	// and place it at tmp[i+j]. Repeat until a or b is
	// 'empty'
	while (i < lenght_a && j < lenght_b) {
		if (comp(get_elmt(a, i), get_elmt(b, j)) > 0) {
			memcpy(get_elmt(tmp, i+j), get_elmt(a, i), size);
			i++;
		} else {
			memcpy(get_elmt(tmp, i+j), get_elmt(b, j), size);
			j++;
		}
	}

	// once the smallest array is 'empty', place the end
	// of the biggest one at the end of tmp.
	if (i < lenght_a)
		memcpy(get_elmt(tmp, i+j), get_elmt(a, i), (lenght_a-i)*size);
	else
		memcpy(get_elmt(tmp, i+j), get_elmt(b, j), (lenght_b-j)*size);


	// tmp is copied and replace the array [[a] [b]]
	memcpy(get_elmt(a, 0), tmp, size*(lenght_a+lenght_b));
	free(tmp);
}

// Inplace merge sort.
// [ w d a c e d q c g y w b  ]
// The first step merges the items one by one to
// form sublist of 2 elements sorted.
// [ [d w] [a c] [d e] [q c] [g y] [b w] ]
// then sublists are merged again
// [[a c d w] [c d e q] [ b g w y ]] 
// At this stage the number of sublist is not odd
// Then the last one is merged with the two previous ones
// to finally have a sorted array 
SORT(merge) {
	// (length of the last list) == (sublist_size + remains) 
	size_t remains = 0;

	for (int sublist_size = 1; sublist_size <= lenght/2; sublist_size*=2) {
		size_t sublist_nb = lenght/sublist_size;
	
		size_t sli; // Sublist index 

		// For each iteration, sublist size is fixed and at
		// the end of a given iteration sublist sizes are double.
		// The last sublist is an exception.
		// At the beginning of each iteration, the size of the last
		// sublist is (sublist_size+remains) and at the end it is
		// (2*sublist_size+remains)
		for (sli = 0; sli + 1 < sublist_nb/2; sli++) {
			// Not the last one
			merge_lists(array(2*sli*sublist_size), sublist_size, array((2*sli+1)*sublist_size), sublist_size, size, comp);
		}

		if (sublist_nb % 2 == 1) {
			// If one list is left alone, [ ... x y z]:
			// x and y are merged...
			merge_lists(array(2*sli*sublist_size), sublist_size, array((2*sli+1)*sublist_size), sublist_size, size, comp);

			// z (wich contains the remains) is merged with [x y]  
			merge_lists(array(2*sli*sublist_size), sublist_size*2, array(2*(sli+1)*sublist_size), sublist_size+remains, size, comp);
			remains += sublist_size;
		} else {
			// if there is no sublist remaining at this point. The
			// two final sublists are merged.
			// Don't forget the previous remains!!
			merge_lists(array(2*sli*sublist_size), sublist_size, array((2*sli+1)*sublist_size), sublist_size+remains, size, comp);
		}
	}
}
