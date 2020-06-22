#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "Iterator.h"

bool Equal(const Iterator *lhs, const Iterator *rhs)
{
	return lhs->node == rhs->node;
}

bool notEqual(const Iterator *lhs, const Iterator *rhs)
{
	return !Equal(lhs, rhs);
}

Iterator* it_next(Iterator *i)
{
	i->node = i->node->next;
	return i;
}

Iterator* it_prev(Iterator *i)
{
	i-> node = i->node->prev;
	return i;
}

int it_fetch(const Iterator *i)
{
	return i->node->data;
}

void it_store(const Iterator *i, const int t)
{
	i->node->data = t;
}

