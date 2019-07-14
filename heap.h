#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

#include "tree.h"

typedef struct Heap {
	Tree* root;
	Tree* bottom;
	size_t length;
} Heap;

Heap* heap_new();
void insert(Heap* heap, void* node, int comp(void*, void*));
void* pop(Heap* heap, int comp(void*, void*));

#endif
