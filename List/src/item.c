#include <stdio.h>
#include "item.h"
/*
 * item.c
 *
 *  Created on: 26 mar 2020
 *      Author: exSna
 */

int eq(item x, item y){
	return x == y;
}

item new_item(int i){
	return i;
}

void input_item(item *x){
	printf("Inserisci un numero\n");
	scanf("%d", x);
}

void output_item(item x){
	printf("Intero: %d\n", x);
}
