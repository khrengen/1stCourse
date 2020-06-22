#include "List.h"

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

bool list_empty(const List *l)
{
    
    return (l->head->next == NULL);
}

int list_size(const List *l)
{
    return l->size;
}

Iterator list_insert(List *l, Iterator *i, int index, const int val)
{
    if (index > list_size(l)){
        printf("u can`t use this index\n");
        return list_first(l);
    }
    if (l->size == 0){
        Iterator i = {l->head};
        i.node->data = val;
        l->size++;
    
        return i;
    }

    Iterator res = {malloc(sizeof(struct Item))};
    if (!res.node)
        return list_first(l);


   Iterator it = list_find(l, index);


    if (index == 0) l->head = res.node; 

    res.node->data = val;
    res.node->next = it.node;
    res.node->prev = it.node->prev;
    it.node->prev->next = res.node;
    it.node->prev = res.node;
    l->size++;

    
    return res;
}

Iterator list_insert_after(List *l, Iterator *i,  const int val)
{
    if (l->size == 0){
        Iterator i = {l->head};
        i.node->data = val;
        l->size++;
    
        return i;
    }

    Iterator res = {malloc(sizeof(struct Item))};
    if (!res.node)
        return list_first(l); 
    res.node->data = val;
    res.node->prev = i->node;
    res.node->next = i->node->next;
    i->node->next->prev = res.node;
    i->node->next = res.node;
    l->size++;
    
    return res;
}

Iterator list_delete(List *l, Iterator *i)
{
    Iterator res = list_first(l);
    if (Equal(i, &res)) {
        if(list_size(l) == 1){
            i->node = 0;
            l->size--;
            return list_first(l);
        }
        res = *it_next(&res);
        l->head = res.node;
    }

    res.node = i->node->next;
    res.node->prev = i->node->prev;
    res.node->prev->next = res.node;
    
    free(i->node);
    i->node = 0;
    l->size--;
    
    return res;
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

void list_print(const List *l)
{
    if (list_size(l) > 0) {
        struct Item *i = l->head;
        do {
            printf("%d ", i->data);
            i = i->next;
        } while (i != l->head);
    
        printf("\n");
    } else {
        printf("List is empty\n");
    }
}

Iterator list_find(const List *l, int k)
{
    Iterator it = list_first(l);
    while (k != 0) {
        it = *it_next(&it);
        --k;
    }
    
    return it;
}




void exec(List *l)
{
    int d, q;
   Iterator itT = list_last(l);
    Iterator itH = list_first(l);

    printf("how many elements? ");
    scanf("%d", &d);
    if (d < 1){
        printf("no\n");
        return;
    }
    if (list_size(l) == 0){
        printf("there`s no elements\n");
        return;
    
    } else{
        q =  l->head->data;
        l->head->data = it_fetch(&itT);
        list_insert_after(l, &itH, q);

        for (int w = 1; w < d; ++w){

            list_insert_after(l, &itH, it_fetch(&itH));
        }
    }    
        list_print(l);
        return;
}
