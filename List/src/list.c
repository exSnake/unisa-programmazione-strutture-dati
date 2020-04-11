#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"

struct c_list{
	struct node *first;
	int size;
};

struct node{
	item itm;
	struct node *next;
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
	return l->size == 0;
}

int cons_list(item elem, list l)
{
	struct node *newItem = malloc(sizeof(struct node));
	if (newItem != NULL)
	{
		newItem->itm = elem;
		newItem->next = l->first;
		l->first = newItem;
		l->size++;
	} else {
		printf("memoria insufficiente, la lista e' rimasta invariata");
		return 0;
	}
	return 1;
}

list tail_list(list l){
	//Controlla che la lista non sia vuota e che l'elemento successivo
	//che associeremo alla testa della lista, non sia null
	if(!empty_list(l)){
		l->first = l->first->next;
		l->size--;
	}
	return l;
}

item get_first(list l){
	if(!empty_list(l)){
		return l->first->itm;
	}
	return NULLITEM;
}

int size_list(list l){
	return l->size;
}

int pos_item(list l, item itm){
	int pos = 0;
	struct node *tmp = l->first;
	while (tmp != NULL){
		if (eq(itm,tmp->itm)){
			return pos;
		} else {
			tmp = tmp->next;
			pos++;
		}
	}
	return -1;
}

item get_item(list l, int p){
	if(l->size == 0 || p >= l->size)
		return NULLITEM;
	int pos = 0;
	struct node *tmp = l->first;
	while (tmp != NULL){
		if (pos == p){
			return tmp->itm;
		} else {
			tmp = tmp->next;
			pos++;
		}
	}
}

list reverse_list(list l){
	list reverse = new_list();
	struct node *n = l->first;
	while (n != NULL){
		cons_list(n->itm, reverse);
		n = n->next;
	}
	return reverse;
}

void output_list(list l){
	struct node *tmp = l->first;
	while (tmp != NULL){
		output_item(tmp->itm);
		tmp = tmp->next;
	}
}

list clone_list(list l){
	list cloned_list = new_list();
	struct node *tmp = l->first;
	int size_tmp = l->size;

	while (!empty_list(l)){
		cons_list(l->first->itm, cloned_list);
		l = tail_list(l);
	}
	cloned_list = reverse_list(cloned_list);
	l->first = tmp;
	l->size = size_tmp;
	return cloned_list;
}