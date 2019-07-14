#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "tree.h"

Tree* tree() {
  Tree* t = malloc(sizeof(Tree));
  t->parent = NULL;
  t->left= NULL;
  t->right= NULL;

  return t;
}

// Create a new node and make it a child of p.
Tree* tree_new_child(Tree* p, int right) {
  if (right) {
    p->right = malloc(sizeof(Tree));
    p->right->parent = p;
    p->right->right = NULL;
    p->right->left = NULL;

    return p->right;
  }

  p->left = malloc(sizeof(Tree));
  p->left->parent = p;
  p->left->right = NULL;
  p->left->left = NULL;

  return p->left;
}

// Return a boolean defining if the
// current node is a right of left child.
// Will SEGFAULT if t->parent is NULL.
int tree_am_I_right(Tree* t) {
    return t->parent->right == t;
}

void* tree_insert_bottom(Tree* bottom, void* child) {
    bottom->node = child;

    return tree_next_bottom(bottom);
}

void tree_swap_node(Tree* a, Tree* b) {
    void* tmp = a->node;
    a->node = b->node;
    b->node = tmp;
}


void tree_destroy(Tree* t) {
    //free(t);
}

void tree_make_orphelin(Tree* t) {
    if (t->parent && tree_am_I_right(t))
        t->parent->right = NULL;
    else if (t->parent)
        t->parent->left = NULL;

    t->parent = NULL;
}

Tree* tree_down_node(Tree* t, int comp(void*, void*)) {
  if (!t->left || !t->left->node)
    return NULL;

  int diff_left = comp(t->node, t->left->node);
  if (!t->right->node && diff_left > 0) {
    tree_swap_node(t, t->left);
    return t->left;
  }

  if (!t->right->node)
    return NULL;

  int diff_right = comp(t->node, t->right->node);

  if (diff_right > 0 && diff_right > diff_left) {
    tree_swap_node(t, t->right);
    return t->right;
  }

  if (diff_left > 0) {
    tree_swap_node(t, t->left);
    return t->left;
  }

  // if current node is smaller than its
  // children
  return NULL;
}

// Returns a pointer where the previous element
// of the heap.
// 3 cases:
//  - the current bottom is the root
//  - the current bottom is a right child
//  - the current bottom is a left child
void* tree_previous_bottom(Tree* bottom) {
  // the current bottom is the root
  if (!bottom->parent) return NULL;

  if (tree_am_I_right(bottom))
    return bottom->parent->left;

  // the current bottom is a left node
  // First while we comme from left, we
  // go up.
  Tree* p = bottom->parent;
  Tree* c = bottom;
  while (p && !tree_am_I_right(c)) {
     c = p;
     p = p->parent;
   }

  // if we are at the root, we restart
  // from the root node
  p = p?p->left:c;

  // Then we go down by the left as much
  // as possible
  while (p->right) p = p->right;

  return p;
}

// Returns a pointer where the next element
// to be inserted in the heap should be
// placed.
// 3 cases:
//  - the current bottom is the root
//  - the current bottom is a left child
//  - the current bottom is a right child
void* tree_next_bottom(Tree* bottom) {
  // the current bottom is the root
  if (!bottom->parent)
    return tree_new_child(bottom, false);

  // the current bottom is a left node
  if (!tree_am_I_right(bottom))
    return tree_new_child(bottom->parent, true);

  // the current bottom is a right node
  // First while we comme from right, we
  // go up.
  Tree* p = bottom->parent;
  Tree* c = bottom;
  while (p && tree_am_I_right(c)) {
     c = p;
     p = p->parent;
   }

  // if we are at the root, we restart
  // from the root node
  if (!p) p = c; else p = p->right;

  // Then we go down by the left as much
  // as possible
  while (p->left) p = p->left;

  return tree_new_child(p, false);;
}
