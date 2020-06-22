#include "list.h"
#include <string.h>
#include <stdio.h>

void list_create(List *l)
{
    l->head = malloc(sizeof(struct Item));
    
    l->head->prev = l->head->next = l->head;
    l->size = 0;
}

Iterator list_first(const List *l)
{
    Iterator res = {l->head};
    
    return res;
}

Iterator list_last(const List *l)
{
    Iterator res = {l->head->prev};
    
    return  res;
}

int list_size(const List *l)
{
    return l->size;
}

bool Equal(const Iterator *lhs, const Iterator *rhs)
{
    return lhs->node == rhs->node;
}

bool notEqual(const Iterator *lhs, const Iterator *rhs)
{
    return !Equal(lhs, rhs);
}

void list_insert_front(List *l, char* val)
{
    if (l->size == 0){
       Iterator i = list_first(l);
        
        i.node->data = (char*)malloc(sizeof(char) * (strlen(val) + 1));
        strcpy(i.node->data, val);
        l->size++;
        return;
    }

    Iterator res = {malloc(sizeof(struct Item))};
    
    Iterator it = list_first(l);

    l->head = res.node;
    res.node->data = (char*)malloc(sizeof(char) * strlen(val) + 1);
    strcpy(res.node->data, val);

    res.node->next = it.node;
    res.node->prev = it.node->prev;
    it.node->prev->next = res.node;
    it.node->prev = res.node;
    l->size++;    
    return ;
}

void list_insert_after(List *l, char* val)
{
    if (l->size == 0){
        Iterator i = list_first(l);
        
        i.node->data = (char*)malloc(sizeof(char) * strlen(val) + 1);
        strcpy(i.node->data, val);
        l->size++;
        return;
    
    }

    Iterator res = {malloc(sizeof(struct Item))};
    if (!res.node)
        return; 
    Iterator i = list_last(l);
    res.node->data = (char*)malloc(sizeof(char) * strlen(val) + 1);
    strcpy(res.node->data, val);
    res.node->prev = i.node;
    res.node->next = i.node->next;
    i.node->next->prev = res.node;
    i.node->next = res.node;
    l->size++;
    
}

void list_delete_last(List *l)
{
    Iterator res = list_first(l);
    Iterator i = list_last(l);
    if (list_size == 0){
        return;
    }else if (Equal(&i, &res)) {
        if(list_size(l) == 1){
            i.node = 0;
            l->size--;
            return;
        }
    }else {

    res.node = i.node->next;
    res.node->prev = i.node->prev;
    res.node->prev->next = res.node;
    
    free(i.node);
    i.node = NULL;
    l->size--;
    
    return;
    }
}

void list_delete_front(List *l)
{
    Iterator i = list_first(l);
    Iterator res = list_last(l);
    if (list_size == 0){
        return;
    }else if (Equal(&i, &res)) {
        if(list_size(l) == 1){
            i.node = 0;
            l->size--;
            return;
        }
    }else {

    l->head = i.node->next;
    res.node = i.node->next;
    res.node->prev = i.node->prev;
    res.node->prev->next = res.node;
    
    free(i.node);
    i.node = NULL;
    l->size--;
    
    return;
    }
}

void list_destroy(List *l)
{
    struct Item *i = l->head->next;
    while (i != l->head) {
        struct Item *pi = i;
        i = i->next;
        free(pi);
    }
    free(l->head);
    l->head = NULL;
    l->size = 0;
}

void list_print(List *l)
{
    if (list_size(l) > 0) {
        Iterator i = list_first(l);
        do {
            printf("%s ", it_fetch(&i));
            i.node = i.node->next;
        } while (i.node != l->head);
    
        printf("\n");
    } else {
        printf("List is empty\n");
    }
}

char* list_find(const List *l, int k)
{

     if (list_size(l) == 0) {
        return NULL;
    } else{

     Iterator it = list_first(l);
     if (k > 0){

            for(int i = 0; i < k - 1; i++){
                it = *it_next(&it);
            }
        } else {
            for(int i = 0; i < -k; i++){
                it = *it_prev(&it);
            }
        }


    return it_fetch(&it);    
    }    
    
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


void it_store(const Iterator *i, char t)
{
    i->node->data = strdup(&t);
}

char* it_fetch( Iterator *i)
{
    return i->node->data;
}



