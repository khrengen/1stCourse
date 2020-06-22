#ifndef List_h
#define List_h

#include <stdio.h>
#include "Iterator.h"

typedef struct {
    struct Item *head;
    int size;
} List;

void list_create(List *l);
Iterator list_first(const List *l);
Iterator list_last(const List *l);
bool list_empty(const List *l);
int list_size(const List *l);
Iterator list_insert(List *l, Iterator *i, int index, const int val);
Iterator list_insert_after(List *l, Iterator *i, const int val);
Iterator list_delete(List *l, Iterator *i);
void list_destroy(List *l);
void list_print(const List *l);
//возвращает итератор на k-ый элемент
Iterator list_find(const List *l, int k);

void exec(List *l);


#endif 