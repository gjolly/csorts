#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

typedef struct Tree {
	void* node;
	struct Tree* parent;
	struct Tree* left;
	struct Tree* righ;	
} Tree;

typedef struct Heap {
	Tree* root;
	size_t size;
} Heap;

void sift_down(Heap* t, void* node, size_t size, int comp(void*, void*));
void sift_up(Heap* t, void* node, size_t size, int comp(void*, void*));

#endif
