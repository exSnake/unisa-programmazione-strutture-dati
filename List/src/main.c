#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"

FILE *Fopen(const char *path, const char *mode);
unsigned char print_menu();
list load_file(char *fn);
void distance_greater_than(list l, float d);
void max_distance(list l);
void del_far_from_origin(list l);
void sum_specular_items(list l);
list ordina(list l, float (*compare)(item p));

int main(int argc, char *argv[])
{
	float d;
	unsigned char choice;
	if (argc < 2)
		printf("Passare come argomento il nome del file in ingresso contenente i punti e la distanza massima\n");
	d = atof(argv[2]);
	list l = load_file(argv[1]);
	while ( (choice = print_menu()) != 0)
	{
		printf("Choice: %hhu\n", choice);
		switch (choice)
		{
		case 1:
			distance_greater_than(l,d);
			getchar(); getchar();
			break;
		case 2:
			max_distance(l);
			getchar(); getchar();
			break;
		case 3:
			del_far_from_origin(l);
			getchar(); getchar();
			break;
		case 4:
			sum_specular_items(l);
			getchar(); getchar();
			break;
		case 5:
			ordina(l,ascissa);
			getchar(); getchar();
			break;
		case 6:
			ordina(l, ordinata);
			getchar(); getchar();
			break;
		case 7:
			output_list(l);
			getchar(); getchar();
			break;
		default:
			printf("Scelta errata\n");
			getchar(); getchar();
			break;
		}
	}
	puts("Esecuzione terminata\n");
	exit(EXIT_SUCCESS);
}

FILE *Fopen(const char *path, const char *mode)
{
	FILE *f = fopen(path, mode);
	if (f == NULL)
	{
		perror(path);
		printf("Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	return f;
}

unsigned char print_menu(){
	unsigned char choice;
	system("clear");
	printf("Esercizio Punti in Lista v0.15\n\t"
		   "1.Distanza maggiore di D\n\t"
		   "2.Distanza Massima\n\t"
		   "3.Elimina il punto piu lontano dall'origine\n\t"
		   "4.Somma speculari\n\t"
		   "5.Ordina Lista per ascisse\n\t"
		   "6.Ordina Lista per ordinate\n\t"
		   "7.Stampa Lista\n\t"
		   "\n\t"
		   "0.Esci\n\t");
	scanf(" %hhu", &choice);
	return choice;
}

list load_file(char *fn){
	float x, y;
	//Apertura file
	FILE *fp = Fopen(fn, "r");
	//Creazione lista
	list l = new_list();
	while (!feof(fp))
	{
		fscanf(fp, "%f%f", &x, &y);
		item p = new_item(x, y);
		cons_list(p, l);
	}
	//Fine creazione lista e chiusura file
	fclose(fp);
	return l;
}

void distance_greater_than(list l, float d){
	list tmp = clone_list(l);
	int m = 0;
	for (int i = 0; i < size_list(l); i++){
		for (int j = i + 1; j < size_list(l); j++){
			float tmpdst = distanza(get_item(l, i), get_item(l, j));
			if (tmpdst < d)
				m++; //numero coppie punti a distanza minore di d
		}
	}
	printf("Le coppie di punti a distanza minore di %.2f sono %d\n", d, m);
}

void max_distance(list l){
	list tmp = clone_list(l);
	int m = 0;
	int p1_pos = 0, p2_pos = 0;
	float dist = 0;
	for (int i = 0; i < size_list(l); i++)
		for (int j = i + 1; j < size_list(l); j++)
		{
			float tmpdst = distanza(get_item(l, i), get_item(l, j));
			if (tmpdst > dist)
			{
				p1_pos = i;
				p2_pos = j;
				dist = tmpdst;
			}
		}

	printf("La coppia di punti con piu distanza tra di loro (%.2f) e' la seguente:\n", dist);
	output_item(get_item(l, p1_pos));
	output_item(get_item(l, p2_pos));
}

void del_far_from_origin(list l){
	item p0 = crea_punto(0,0);
	int d = 0;
	int tmpdst = 0, dist = 0;
	int pos;
	for (int i = 0; i < size_list(l); i++){
		float tmpdst = distanza(p0, get_item(l, i));
		if (tmpdst > dist)
		{
			pos = i;
			dist = tmpdst;
		}
	}
	//output_list(l);
	delete_item(l,pos);
	output_list(l);
}

void sum_specular_items(list l){
	item itm_1, itm_2;
	list sumList = new_list();
	int p = 0;
	if(size_list(l) % 2 != 0){
		printf("Lista non pari\n");
		return;
	}
	for (int i = 0; i < ( size_list(l)/2 ); i++)
	{
		list tmp = clone_list(l);
		int pos = 0;
		while (!empty_list(tmp))
		{
			if (pos == p){
				itm_1 = get_first(tmp);
			}
			if (pos == (size_list(l) - p - 1)){
				itm_2 = get_first(tmp);
			}
			tail_list(tmp);
			pos++;
		}
		item sum = somma(itm_1,itm_2);
		cons_list(sum,sumList);
		p++;
	}
	list tmp = clone_list(sumList);
	while (!empty_list(tmp))
	{
		cons_list(get_first(tmp),sumList);
		tail_list(tmp);
	}
	output_list(sumList);
}

list ordina(list l, float (*compare)(punto p)){
	list orderedList = new_list();
	list tmplist = clone_list(l);
	int size = size_list(l);
	punto min;
	for(int i = 0; i < size; i++){
		int tmp = 0, pos = 0, todel = 0;
		list clone = clone_list(tmplist);
		while (!empty_list(clone)){
			if ((*compare)(get_first(clone)) > tmp){
				min = get_first(clone);
				tmp = (*compare)(get_first(clone));
				todel = pos;
			}
			tail_list(clone);
			pos++;
		}
		cons_list(crea_punto(ascissa(min), ordinata(min)), orderedList);
		delete_item(tmplist, todel);
	}
	output_list(orderedList);
	free(orderedList);
	free(tmplist);
	return orderedList;
}
