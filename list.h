#ifndef LIST_H
#define LIST_H

typedef struct List {
	void* elmt;
	struct List* sl;
} List;

List* list_new();
void list_destroy(List** l);
void* list_pop(List** l);
void list_push(List** l, void* elmt);
void* list_touch(List* l);

#endif
