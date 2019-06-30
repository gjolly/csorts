#include <stdlib.h>

#include "list.h"

List* list_new() {
	List* l = malloc(sizeof(List));

	l->sl = NULL;

	return l;
}

void list_push(List** l, void* elmt) {
	if ((*l)->sl == NULL) {
		(*l)->elmt = elmt;
		return;
	}

	List* new_list = malloc(sizeof(List));
	new_list->elmt = elmt;
	new_list->sl = *l;

	*l = new_list;
}

void* list_touch(List* l) {
	return l->elmt;
}

void* list_pop(List** l) {
	void* elmt = list_touch(*l);
	List* new_list = (*l)->sl;
	free(*l);
	l = &new_list; 

	return elmt;
}

void list_destroy(List** l) {
	while(*l != NULL) {
		list_pop(l);
	}	
}
