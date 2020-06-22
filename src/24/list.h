#ifndef List_h
#define List_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    struct Item *head;
    int size;
} List;

struct Item {
    struct Item *next;
    struct Item *prev;
    char* data;
};

typedef struct {
    struct Item *node;
} Iterator;

void list_create(List *l);
Iterator list_first(const List *l);
Iterator list_last(const List *l);
bool list_empty(const List *l);
int list_size(const List *l);
void list_insert_front(List *l,char* val);
void list_insert_after(List *l, char* val);
void list_delete_last(List *l);
void list_delete_front(List *l);
void list_destroy(List *l);
void list_print( List *l);

char* list_find(const List *l, int k);



bool Equal(const Iterator *lhs, const Iterator *rhs);

Iterator* it_next(Iterator *it);
Iterator* it_prev(Iterator *it);
char* it_fetch( Iterator *it);
void it_store(const Iterator *it, char t);




#endif 