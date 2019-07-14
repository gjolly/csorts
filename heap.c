#include <stdlib.h>
#include <stdbool.h>

#include "heap.h"
#include "utils.h"
#include "list.h"
#include "tree.h"

Heap* heap_new() {
    Heap* h = malloc(sizeof(Heap));
    h->root = tree();
    h->bottom = h->root;

    return h;
}

int heap_illegal_order(Tree* child, Tree* parent, int comp(void*, void*)) {
    if (parent == NULL)
        // If we are at the root, we stop
        return false;

    return comp(child->node, parent->node) < 0;
}

void insert(Heap* heap, void* node, int comp(void*, void*)) {
    Tree* current_tree = heap->bottom;

    heap->bottom = tree_insert_bottom(heap->bottom, node);

    while (heap_illegal_order(current_tree, current_tree->parent, comp)) {
        tree_swap_node(current_tree, current_tree->parent);

        current_tree = current_tree->parent;
    }
}

void* pop(Heap* heap, int comp(void*, void*)) {
    Tree* new_bottom = tree_previous_bottom(heap->bottom);

    //if we are at the root, its pretty simple
    if (!new_bottom) {
      void* n = heap->bottom->node;
      heap->bottom->node = NULL;
      return n;
    }

    tree_make_orphelin(heap->bottom);
    tree_destroy(heap->bottom);

    heap->bottom = new_bottom;

    void* node = heap->root->node;

    heap->root->node = new_bottom->node;
    new_bottom->node = NULL;

    Tree* current_tree = heap->root;
    while((current_tree = tree_down_node(current_tree, comp)));

    return node;
}
