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

item input_item(){
	return create_stdio();
}

void output_item(item x){
	to_string(x);
}
