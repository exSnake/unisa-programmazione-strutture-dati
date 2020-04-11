#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct miopunto{
	float x;
	float y;
};

punto crea_punto_stdio(){
	struct miopunto* p = malloc(sizeof(struct miopunto));
	printf("Inserisci ascissa: ");
	scanf("%f",&p->x);
	printf("Inserisci ordinata: ");
	scanf("%f",&p->y);
	return p;
}
      
punto crea_punto(float x, float y){
	struct miopunto* p = malloc(sizeof(struct miopunto));
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
	//printf("Distanza: p1(%.2f,%.2f), p2(%.2f,%.2f) = %.2f\n", ascissa(p1), ordinata(p1), ascissa(p2), ordinata(p2), sqrt(dx * dx + dy * dy));
	return sqrt(dx*dx + dy*dy);
}

void print_punto(punto p){
	printf("Punto(%.2f,%.2f)\n", p->x, p->y);
}
