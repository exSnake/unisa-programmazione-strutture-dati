#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
	int n = 0;
	int i = 0;
	list head;
	printf("Inserisci il numero di liste da creare\n");
	scanf("%d", &n);


	head = newList();
	list tmp = head;
	while(i < n){
		int val = 0;
		printf("Inserisci l'elemento n: %d\n", (i + 1) );
		scanf("%d", &val);
		tmp = consList(val,tmp);
		i++;
	}

	printf("First: %d\n", getFirst(tmp));
	output_list(tmp);
	printf("Lista dalla coda:\n");
	output_list(tailList(tmp));
	printf("Dimensione lista: %d\n", sizeList(tmp));

	system("PAUSE");
	return EXIT_SUCCESS;
}
