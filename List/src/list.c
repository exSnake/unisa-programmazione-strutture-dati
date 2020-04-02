#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"

struct node {
	item itm;
	struct node *next;
};

list newList(void){
	return NULL;
}

int emptyList(list l){
	return l == NULL;
}

list tailList(list l){
	if(!emptyList(l) && l->next != NULL){
		return l->next;
	}
	return NULL;
}

list consList(item elem, list l){
	struct node *newItem;
	newItem = (struct node*)malloc(sizeof(struct node));
	if(newItem != NULL){
		newItem->itm = elem;
		newItem->next = l;
	}
	return newItem;
}

item getFirst(list l){
	if(!emptyList(l)){
		return l->itm;
	}
	return NULLITEM;
}

void output_list(list l){
	printf("Stampo lista\n");
	while (!emptyList(l)) {
		printf(" %d ", l->itm);
		l = l->next;
	}
	printf("\n");
}

int sizeList(list l){
	int i = 0;
	while(!emptyList(l)){
		i++;
		l = l->next;
	}
	return i;
}
