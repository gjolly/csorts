#include "tree.h"

#include <stdio.h>

#include "test.h"

TEST(tree_next_bottom_simple) {
    Tree* t0 = tree();
    Tree* t1 = tree_new_child(t0, false);

    Tree* nb = tree_next_bottom(t1);

    char txt[100];
    sprintf(txt, "wrong next bottom expected %p got %p", (void*)(t0->right),
            (void*)(nb));
    test_assert(t, nb && nb == t0->right, txt);

    tree_destroy(t1);
    tree_destroy(t0->right);
    tree_destroy(t0);
}

TEST(tree_previous_bottom) {
    Tree* t0 = tree();
    Tree* t2 = tree_new_child(t0, false);
    tree_new_child(t0, true);
    Tree* b = tree_new_child(t2, false);

    Tree* pb = tree_previous_bottom(b);

    char txt[100];
    sprintf(txt, "wrong next bottom expected %p got %p", (void*)(t0->right),
            (void*)(pb));
    test_assert(t, pb && pb == t0->right, txt);

    tree_destroy(b);
    tree_destroy(pb);
    tree_destroy(t2);
    tree_destroy(t0);
}

TEST(tree_next_bottom_3nodes) {
    Tree* t0 = tree();
    tree_new_child(t0, false);
    Tree* t2 = tree_new_child(t0, true);

    Tree* nb = tree_next_bottom(t2);
    test_assert(t, nb && nb == t0->left->left, "wrong next bottom");

    tree_destroy(t2);
    tree_destroy(t0->left->left);
    tree_destroy(t0->left);
    tree_destroy(t0);
}

TEST(tree_next_bottom_root_only) {
    Tree* t0 = tree();
    Tree* nb = tree_next_bottom(t0);
    test_assert(t, nb && nb == t0->left, "wrong next bottom");

    tree_destroy(nb);
    tree_destroy(t0);
}
