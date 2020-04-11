#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
	item itm;
	list l = new_list();
	if(l == NULL)
		exit(EXIT_FAILURE);

	for(int i = 0; i < 112; (i = i + 11)){
		item j = new_item(i);
		if(cons_list(j, l) == 0)
			exit(EXIT_FAILURE);
	}

	output_list(l);
	itm = new_item(55);
	int pos = pos_item(l,itm);
	printf("Cerco: "); output_item(itm);
	printf(pos == -1 ? " non trovato\n" : " e' in posizione %d\n", pos);
	itm = new_item(25);
	pos = pos_item(l,itm);
	printf("Cerco: "); output_item(itm);
	printf(pos == -1 ? " non trovato\n" : " e' in posizione %d\n",pos);
	list l1 = reverse_list(l);
	output_list(l1);
}
