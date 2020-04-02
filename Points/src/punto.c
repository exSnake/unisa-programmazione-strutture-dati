#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct miopunto{
	float x;
	float y;
};
      
punto creapunto(float x, float y){
	struct miopunto* p;
	p = (struct miopunto*)malloc(sizeof(struct miopunto));
	p->x = x;
	p->y = y;

	return p;
}

float ascissa(punto p){
	return p->x;
}

float ordinata(punto p){
	return p->y;
}

float distanza(punto p1, punto p2){
	float dx = ascissa(p1) - ascissa(p2);
	float dy = ordinata(p1) - ordinata(p2);

	return sqrt(dx*dx + dy*dy);
}


