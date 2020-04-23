#include<stdio.h>
#include<stdlib.h>
#include"list.h"

struct node{
	item e;
	struct node* next;
};

struct c_list{
	struct node* first;
	int n;
};

list new_list(){
	list l = malloc(sizeof(struct c_list));

	if(l != NULL){
		l -> first = NULL;
		l -> n = 0; 
	} else {
		printf("Memoria insufficiente");
		exit(EXIT_FAILURE);
	}
	return l;
}

int empty_list(list l){
	if(l == NULL)
		return -1;
	return (l -> n == 0) ? 1 : 0;
}

int size_list(list l){
	return l -> n;
}

static struct node* cons_list(struct node* l,item e){
	struct node *new = malloc(sizeof(struct node));
	if( new == NULL)
		return NULL;
	new -> e = e;
	new -> next = l;
	return new;
}

static struct node* tail_list(struct node* l){
	return l -> next;
}

int insert_list(list l, int pos, item e){
	if(l == NULL)
		return -1;
	struct node* tmp = insert_item(l -> first,pos,e);
	if( tmp == NULL)
		return -1;
	l -> first = tmp;
	l -> n++;
	return 1;
}

static struct node* insert_item(struct node *l, int pos, item e){
	if(pos == 0)
		return cons_list(l,e);
	
	struct node* tmp = l, *prec;
	int i=0;
	while(tmp != NULL && i < pos){
		i++;
		prec = tmp;
		tmp = tail_list(tmp);
	}

	if(tmp == NULL){
		struct node *last = malloc(sizeof(struct node));
		last -> e = e;
		last -> next = NULL;
		
		prec -> next = last;
	}
	else{
		tmp = cons_list(tmp,e);
		prec -> next = tmp;
	}

	return l;
}

int remove_list(list l, int pos){
	if (l == NULL)
		return -1;
	struct node* tmp = remove_item(l->first,pos);
	if( tmp == NULL)
		return -1;
	l -> first = tmp;
	l -> n--;
	return 1;
}

static struct node* remove_item(struct node* l, int pos){
	struct node* tmp,*prec;
	if(pos == 0){
		tmp = tail_list(l);
		free(l);
		return tmp;
	}

	tmp = l;
	int i = 0;
	while (tmp != NULL && i < pos ){
		i++;
		prec = tmp;
		tmp = tail_list(tmp);
	}

	if(tmp == NULL)
		return NULL;
	else{
		prec -> next = tail_list(tmp);
		free(tmp);
	}

	return l;
}

list clone_list(list l){
	list l1 = new_list();
	struct node* tmp = l -> first;
	while(tmp != NULL){
		if(insert_list(l1,l1 -> n,tmp -> e) == 0){
			free_list(l1);
			return NULL;
		}
		tmp = tmp -> next;
	}

	return l1;
}

item get_first(list l){
	return empty_list(l) ? NULLITEM : l -> first -> e;
}

item get_item(list l, int pos){
	if(pos < 0 || pos >= l -> n)
		return NULLITEM;

	struct node* tmp = l -> first;
	for (int i = 0; i < pos; i++)
		tmp = tail_list(tmp);

	return tmp -> e;
}

int search_item(list l, item itm){
	for (int i = 0; i < size_list(l); i++)
	{
		if (eq(get_item(l, i),itm) == 1) 
			return i;
	}
	return -1;
}

int searchItem(list l, item e){
	for (int i = 0; i < size_list(l); i++)
	{
		if (eq(get_item(l, i), e) == 1)
			return i;
	}
	return -1;
}

list input_fist(){
	int n;
	do{
		printf("Quanti elementi vuoi inserire? \n");
		scanf("%d",&n);
	}while( n < 0);

	list l = new_list();
	item e;
	for (int i = 0; i < n; i++)
	{
		printf("Elemento %d: ",i);
		input_item(&e);
		insert_list(l,l->n,e);
	}
	
	return l;
}

void output_list(list l){
	for (int i = 0; i < l -> n; i++)
	{
		printf("Elemento %d: ",i);
		output_item(get_item(l,i));
	}
}

list merge_list(list l1,list l2){
	list l3=new_list();
	struct node* tmp1=l1->first;
	struct node* tmp2=l2->first;
	for(int i=0;i<l1->n;i++){
			insert_list(l3,l3->n,tmp1->e);
			tmp1=tmp1->next;
	}

	for(int i=0;i<l2->n;i++){
			insert_list(l3,l3->n,tmp2->e);
			tmp2=tmp2->next;
	}
	return l3;
}

void free_list(list l){
	while(!empty_list(l))
		remove_list(l,0);
	free(l);
}

