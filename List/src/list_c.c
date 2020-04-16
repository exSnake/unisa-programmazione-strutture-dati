#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"

struct node
{
    item itm;
    struct node *next;
};

struct c_list
{
    struct node *first;
    int size;
};

list new_list(void){
	struct c_list *l = malloc(sizeof(struct c_list));
	if(l != NULL){
		l->size = 0;
		l->first = NULL;
	}
	return l;
}

int empty_list(list l){
    if( l != NULL)
        return -1;
    return (l->size == 0 ? 1 : 0);
}

int size_list(list l){
    return l->size;
}

struct node *cons_list(struct node *l, item val){
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL)
        return NULL;
    new->itm = val;
    new->next = l;
    return new;
}

struct node *tail_list(struct node *l){
    return l->next;
}

int insert_list(list l, int pos, item elem){
    if(empty_list(l) == -1 || elem == NULL || pos > size_list(l) || pos < 0)
        return -1;
    l->first = insert_item(l->first, pos, elem);
    l->size++;
    return 1;
}

struct node *insert_item(struct node *l, int pos, item elem){
    if(pos == 0)
        return cons_list(l, elem);
    struct node *tmp = l, *prec;
    //allochiamo il nuovo nodo
    struct node *new = malloc(sizeof(struct node));
    new->itm = elem;
    int i = 0;
    //scorriamo la lista fino a pos
    while (tmp != NULL && i < pos - 1){
        prec = tmp; //puntatore precedente (a_pos-1, elem, a_pos)
        tmp = tail_list(tmp); //a_pos alla fine del while
        i++;
    }
    if(tmp == NULL)
        return NULL;
    tmp = cons_list()
    prec->next = new;
    new->next = tmp;
    return l;
}