#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "sorting.h"
#include "heap.h"

#define get_elmt(x, i) ((char*)x+(i)*size)
#define array(i) get_elmt(array, i)

SORT(insertion) {
    for (size_t i = 1; i < length; i++) {
        size_t j = i;
        while (j > 0 && comp(array(j), array(j-1)) < 0) {
            array_swap(array, size, j-1, j);
            j--;
        }
    }
}

SORT(selection) {
    for (size_t i = 0; i < length; i++) {
        size_t i_min = i;
        for (size_t j = i + 1; j < length; j++) {
            if (comp(array(i_min), array(j)) > 0)
                i_min = j;
        }
        array_swap(array, size, i_min, i);
    }
}

void merge_lists(void* a, size_t length_a, void* b, size_t length_b, size_t size, int comp(void*, void*)) {

    // tmp is a auxiliary array used to merge
    // a and b
    char* tmp = malloc((length_a+length_b)*size);

    size_t i = 0; // indexes a
    size_t j = 0; // indexes b

    // Choose the biggest item between a[j] and b[j]
    // and place it at tmp[i+j]. Repeat until a or b is
    // 'empty'
    while (i < length_a && j < length_b) {
        if (comp(get_elmt(a, i), get_elmt(b, j)) < 0) {
            memcpy(get_elmt(tmp, i+j), get_elmt(a, i), size);
            i++;
        } else {
            memcpy(get_elmt(tmp, i+j), get_elmt(b, j), size);
            j++;
        }
    }

    // once the smallest array is 'empty', place the end
    // of the biggest one at the end of tmp.
    if (i < length_a)
        memcpy(get_elmt(tmp, i+j), get_elmt(a, i), (length_a-i)*size);
    else
        memcpy(get_elmt(tmp, i+j), get_elmt(b, j), (length_b-j)*size);


    // tmp is copied and replace the array [[a] [b]]
    memcpy(get_elmt(a, 0), tmp, size*(length_a+length_b));
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

    for (int sublist_size = 1; sublist_size <= length/2; sublist_size*=2) {
        size_t sublist_nb = length/sublist_size;

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

SORT(heap) {
    Heap* heap = heap_new();
    for (size_t i = 0; i < length; i++)
        insert(heap, array(i), comp);

    char* tmp_array = malloc(length*size);

    for (size_t i = 0; i < length; i++)
        memcpy(tmp_array + i*size, pop(heap, comp), size);

    for (size_t i = 0; i < length; i++)
        memcpy((char*)array + i*size, tmp_array + i*size, size);

    free(tmp_array);
    free(heap->root);
    free(heap);
}
