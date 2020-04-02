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

void input_item(item *x){
	printf("Inserisci un numero\n");
	scanf("%d", &x);
}

void output_item(item x){
	printf("Intero: %d", x);
}
