#ifndef Iterator_h
#define Iterator_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Item {
    struct Item *next;
    struct Item *prev;
    int data;
};

typedef struct {
    struct Item *node;
} Iterator;

bool Equal(const Iterator *lhs, const Iterator *rhs);

Iterator* it_next(Iterator *it);
Iterator* it_prev(Iterator *it);
int it_fetch(const Iterator *it);
void it_store(const Iterator *it, const int t);
#endif 