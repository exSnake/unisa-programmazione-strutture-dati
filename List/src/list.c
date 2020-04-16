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

static struct node *insertNode(struct node *l, int pos, item val);

list new_list(void){
	struct c_list *l = malloc(sizeof(struct c_list));
	if(l != NULL){
		l->size = 0;
		l->first = NULL;
	}
	return l;
}

int empty_list(list l){
	return size_list(l) == 0;
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

void tail_list(list l){
	//Controlla che la lista non sia vuota e che l'elemento successivo
	//che associeremo alla testa della lista, non sia null
	if(!empty_list(l)){
		struct node *tmp = l->first;
		l->first = l->first->next;
		l->size--;
	}
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

item get_item(list l, int pos){
	if(size_list(l) == 0 || pos >= size_list(l) || pos < 0)
		return NULLITEM;
	int p = 0;
	struct node *tmp = l->first;
	while (tmp != NULL){
		if (p == pos){
			return tmp->itm;
		} else {
			tmp = tmp->next;
			p++;
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
	printf("\nStampo Lista:\n");
	struct node *tmp = l->first;
	while (tmp != NULL){
		output_item(tmp->itm);
		tmp = tmp->next;
	}
}

list clone_list(list l){
	list cloned_list = new_list();
	struct node *tmp = l->first;
	int size_tmp = size_list(l);

	while (!empty_list(l)){
		cons_list(l->first->itm, cloned_list);
		tail_list(l);
	}
	cloned_list = reverse_list(cloned_list);
	l->first = tmp;
	l->size = size_tmp;
	return cloned_list;
}

int delete_item(list l, int pos)
{
	if (pos < 0 || pos >= size_list(l) || size_list(l) == 0)
		return 0;

	struct node *tmp = l->first;

	if(pos == 0){
		l->first = l->first->next;
		l->size--;
		free(tmp);
		return 1;
	}

	int p = 0;
	struct node *prec = l->first;

	while (tmp != NULL){
		if (p == pos){
			prec->next = tmp->next;
			l->size--;
			free(tmp);
			return 1;
		} else {
			prec = tmp;
			tmp = tmp->next;
			p++;
		}
	}
	return 0;	
}

int insert_item(list l, int pos, item val)
{
	struct node *tmp = insertNode(l->first, pos, val);
	if (tmp == NULL){
		printf("errror inserting size: %d pos: %d\n", l->size, pos);
		return 0;
	}
	l->first = tmp;
	l->size++;
	return 1;
}

static struct node *insertNode(struct node *l, int pos, item val)
{
	int i = 0;
	struct node *prec = l;
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL)
		return NULL;
	new->itm = val;
	// inserimento in testa
	if (pos == 0){ 
		new->next = l;
		return new;
	}
	// scorro la lista fino ad arrivare a pos
	while (i < pos - 1 && prec != NULL){
		prec = prec->next;
		i++;
	}
	 // la lista di input ha meno di pos elementi
	if (prec == NULL){
		free(new);
		return NULL;
	}
	new->next = prec->next;
	// aggiungo in posizione pos
	prec->next = new; 
	return l;
}
