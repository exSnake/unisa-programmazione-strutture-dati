#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

struct miolibro{
	char titolo[100];
	char editore[50];
	float prezzo;
	int anno;
};

libro creaLibro(char *t, char* e, float p, int a)
{
	libro l = malloc(sizeof(*l));
	strcpy(l->titolo, t);
	strcpy(l->editore, e);
	l->prezzo = p;
	l->anno = a;
	return l;
}

char* titolo(libro l)
{
	return l->titolo;
}

char* editore(libro l)
{
	return l->editore;
}

int anno(libro l)
{
	return l->anno;
}

float prezzo(libro l)
{
	return l->prezzo;
}

float sconto(libro *l, float percentuale)
{
	if((*l) != NULL && percentuale > 0){
		(*l)->prezzo = (*l)->prezzo - ((*l)->prezzo * percentuale/100);
		return 0;
	} else {
		return 1;
	}
}
