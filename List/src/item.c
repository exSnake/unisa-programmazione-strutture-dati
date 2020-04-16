#include <stdio.h>
#include "item.h"
/*
 * item.c
 *
 *  Created on: 26 mar 2020
 *      Author: exSna
 */

int eq(item x, item y){
	return (equals(x,y));
}

item new_item(float x, float y){
	return crea_punto(x,y);
}

void input_item(item *x){
	item p = crea_punto_stdio();
	x = &p;
}

void output_item(item x){
	to_string(x);
}
