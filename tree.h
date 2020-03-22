#ifndef H_TREE
#define H_TREE

#include <stdbool.h>

typedef struct Tree {
    void* node;
    struct Tree* parent;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* tree();
Tree* tree_new_child(Tree* p, int right);
int tree_am_I_right(Tree* t);
void tree_swap_node(Tree* a, Tree* b);
void tree_destroy(Tree* t);
void tree_make_orphelin(Tree* t);
Tree* tree_down_node(Tree* t, int comp(void*, void*));
void* tree_insert_bottom(Tree* bottom, void* child);
void* tree_previous_bottom(Tree* bottom);
void* tree_next_bottom(Tree* bottom);

#endif
