#include <stdlib.h>

#include "heap.h"
#include "utils.h"

Tree* bottom(Heap* h) {
	
}

void insert_bottom(Heap* heap, void* child) {
	Tree* b	= bottom(heap);
	b->node = child;
}

int illegal_order(void* child, void* parent, int comp(void*, void*)) {
	return comp(child, parent) < 0;
}

void sift_up(Heap* heap, void* node, size_t size, int comp(void*, void*)) {
	insert_bottom(heap, node);
	
	Tree* current_tree = heap->bottom->node;
	while (illegal_order(current_tree->node, current_tree->parent->node, comp)){
		swap(current_tree->node, current_tree->parent->node, size);
		current_tree = current_tree->parent;
	}
}
