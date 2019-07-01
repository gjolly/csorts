#include "list.h"
#include "test.h"

TEST(list_basic) {
	List* l = list_new();

	int a[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++)
		list_push(&l, a+i);

	for (int i = 5; i > 0; i--)
		test_assert(t, *(int*)list_pop(&l) == i, "wrong list");

	list_destroy(&l);
}

TEST(list_touch) {
	List* l = list_new();
	int elmt = 1;

	list_push(&l, &elmt);

	for (int i = 0; i < 10; i++)
		test_assert(t, *(int*)list_touch(l) == elmt, "wrong item");
}
