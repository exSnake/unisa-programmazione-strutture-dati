#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"


#define BUFFSIZE 100

FILE *Fopen(const char *path, const char *mode);
int countFileLine(FILE *fp);

/**
 * libropiuvecchio: accetta in ingresso una biblioteca di libri e ne restituisce il piu vecchio
 * Sintattica:
 *    libropiuvecchio(libro*, int) -> libro
 * Semantica:
 *    libropiuvecchio(libro*, n) -> l
 *       Pre: Accetta in ingresso il puntatore al primo di una lista di libri e la dimensione n
 *       Post: Restituisce l il libro piu vecchio della biblioteca
 */
libro libropiuvecchio(libro *biblioteca, int n);

/*
 * libromenocostoso: accetta in ingresso una biblioteca di libri e ne restituisce il meno costoso
 * Sintattica:
 *    libromenocostoso(libro*, int) -> libro
 * Semantica:
 *    libromenocostoso(libro*, n) -> l
 *       Pre: Accetta in ingresso il puntatore al primo di una lista di libri e la dimensione n
 *       Post: Restituisce l il libro meno costoso della biblioteca
 */
libro libromenocostoso(libro* biblioteca, int n);

/*
 * ricercaeditore: accetta in ingresso un editore e ne restituisce i suoi libri
 * Sintattica:
 *    ricercaeditore(char*, libro*, int, integer*) -> libro*
 * Semantica:
 *    ricercaeditore(*ed, *libro, n, *trovati) -> *l
 *       Pre: Accetta in ingresso il nome dell'editore non vuoto la biblioteca in cui cercare e la sua dimensione e il numero dove andranno inseriti i libri trovati per riferimento
 *       Post: Restituisce il numero di libri trovati e la biblioteca <l1,l2,...,ln> dove l->editore = ed
 */
libro* ricercaeditore(char* ed, libro* biblioteca, int n, int *trovati);

/*
 * sconto: Accetta in ingresso una biblioteca di libri, un anno come intero e una percentuale di sconto
 *    e ne sconta tutti i libri di quella biblioteca
 * Sintattica:
 *    sconto(libro*, int, int, float) -> int
 * Semantica:
 *    sconto(biblioteca, n, anno, percentuale) -> numLibriScontati
 *       Pre: biblioteca non vuota, anno > 0, percentuale > 0
 *       Post: biblioteca = <l1,l2,...,ln> dove l->anno == anno AND l->prezzo = l->prezzo - (l->prezzo * percentuale)
 *          ritorna il numero di libri scontati
 */
int scontaPerAnno(libro* biblioteca, int n, int an, float percentuale);

/**
 * trovalibriprezzosimile: Trova i primi due libri il cui prezzo e' simile con uno scarto di 10
 *     confrontando tutti i libri partendo dal primo, se il primo non ha libri simili passa al secondo
 *     ritorna null se non ce ne sono
 * Sintattica:
 *    trovalibriprezzosimile(libro*, int) -> *libro
 * Semantica:
 *    trovalibriprezzosimile(biblioteca, n) -> *libri
 *       Pre: biblioteca non vuota
 *       Post: libri dove ly->prezzo >= lx->prezzo - scarto AND ly->prezzo <= lx->prezzo + scarto
 *          0 se tutto e' andato correttamente 1 se c'e' qualche errore
 */
libro* trovalibriprezzosimile(libro* biblioteca, int n);

/**
 * costototale: Calcola il costo totale di tutti i libri di un rispettivo anno dato in ingresso
 * Sintattica:
 *    costototale(libro*, integer, integer) -> float
 * Semantica:
 *    costototale(biblioteca, n, anno) -> costo
 *       Pre: biblioteca non vuota, anno > 0
 *       Post: costo = <l1->prezzo + l2->prezzo,..., + ln->prezzo> dove ln->anno == anno
 */
float costototale(libro* biblioteca, int n, int an);

void printLista(libro* biblioteca, int n);

int main(int argc, char *argv[]){
	FILE *fp;
	libro *biblioteca;
	int n = 0;
	int i = 0;
	char tit[100] = "";
	char ed[50] = "";
	char buffer[100];
	float pr;
	int an;
	if (argc < 2){
		printf("Inserisci il nome del file di input e l'editore da cercare");
		exit(1);
	}

	fp = Fopen(argv[1], "r");
	n = countFileLine(fp)/4; //numero libri, ogni 4 linee 1
	fclose(fp);

	biblioteca = malloc(sizeof(libro) * (n));

	fp = Fopen(argv[1], "r");
	while (!feof(fp) && !ferror(fp))
	{
		fgets(tit, sizeof(tit), fp);
		tit[strlen(tit)-1] = '\0';

		fgets(ed, sizeof(ed), fp);
		ed[strlen(ed) - 1] = '\0';

		fgets(buffer, sizeof(buffer), fp);
		an = atoi(buffer);
		buffer[0] = '\0';

		fgets(buffer, sizeof(buffer), fp);
		pr = atof(buffer);
		buffer[0] = '\0';

		biblioteca[i] = creaLibro(tit,ed,pr,an);
		i++;
	}
	fclose(fp);
	libro tmp = malloc(sizeof(libro));
	tmp = libropiuvecchio(biblioteca, n);
	printf("Il libro piu vecchio e: %s\n", titolo(tmp));

	tmp = libromenocostoso(biblioteca, n);
	printf("Il libro menocostoso e: %s\n", titolo(tmp));

	int trovati = 0;
	libro *libriEd = ricercaeditore(argv[2], biblioteca, n, &trovati);
	if (trovati != 0){
		printf("Ho trovato %d libro/i per %s:\n",trovati,argv[2]);
		printLista(libriEd, trovati);
	}
	else
		printf("Nessun libro per questo editore\n");

	int numLibriScont = scontaPerAnno(biblioteca, n, 2000, 10);
	if (numLibriScont == 0)
	{
		printf("nessun libro scontato\n");
	}
	else
	{
		printf("Scontati %d libri\n", numLibriScont);
		printLista(biblioteca, n);
	}

	libro *prezzosimile = trovalibriprezzosimile(biblioteca, n);
	if (prezzosimile == NULL)
	{
		printf("nessun libro dal prezzo simile\n");
	}
	else
	{
		printLista(prezzosimile, 2);
	}

	printf("costo totale libri anno 2000: %f\n", costototale(biblioteca, n, 2020));
	printf("end\n");
	system("PAUSE");
	return 0;
}

int countFileLine(FILE *fp)
{
	int lines = 0;
	char ch;
	while (!feof(fp) && !ferror(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			lines++;
		}
	}
	lines++; //last line without \n
	return lines;
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

void printLista(libro* biblioteca, int n){
	printf("Lista libri:\n");
	for (int i = 0; i < n; ++i) {
		printf("Titolo: %s\nEditore: %s\nPrezzo: %f\nAnno: %d\n\n", titolo(biblioteca[i]),editore(biblioteca[i]),prezzo(biblioteca[i]),anno(biblioteca[i]));
	}
}

libro libropiuvecchio(libro* biblioteca, int n){
	int tmp = 0;
	for(int i=1; i<n; i++){
		if(anno(biblioteca[i]) < anno(biblioteca[i - 1])){
			tmp = i;
		}
	}
	return biblioteca[tmp];
}

libro libromenocostoso(libro* biblioteca, int n){
	int tmp = 0;
	for(int i=1; i<n; i++){
		if(prezzo(biblioteca[i]) < prezzo(biblioteca[i - 1])){
			tmp = i;
		}
	}
	return biblioteca[tmp];
}

libro* ricercaeditore(char* ed, libro* biblioteca, int n, int* t){
	libro *libriEditore;
	int trovati = 0;
	//Primo ciclo per trovare il numero di libri da allocare
	for(int i=0; i<n; i++)
	{
		if(strcmp(ed,editore(biblioteca[i])) == 0)
		{
			trovati++;
		}
	}
	if(trovati == 0)
		return 0;
	*t = trovati;
	libriEditore = malloc(sizeof(libro) * (trovati+1));
	trovati = 0;
	//secondo ciclo per assegnarli
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ed, editore(biblioteca[i])) == 0)
		{
			libriEditore[trovati] = biblioteca[i];
			trovati++;
		}
	}

	return libriEditore;
}

int scontaPerAnno(libro* biblioteca, int n, int an, float percentuale){
	int numLibriScontati = 0;
	for(int i=0; i<n; i++){
		if(anno(biblioteca[i]) == an){
			sconto(&biblioteca[i], percentuale);
			numLibriScontati++;
		}
	}
	return numLibriScontati;
}

libro* trovalibriprezzosimile(libro* biblioteca, int n){
	int scarto = 10;
	int found = 0;
	libro *libriPrezzoSimile;
	libriPrezzoSimile = malloc(sizeof(libro)*(2));
	if(n < 2)
		return NULL;
	for(int i=0; i<n; i++){
		if(found == 1)
			break;
		for(int j=1; i<n; i++){
			//prezzo libro2 = 50 se >= prezzo libro1 = 40 - 10 (30) e prezzo libro2 = 60 <= prezzo libro1 = 40 + 10 50
			// 50 >= 30 (si) e 50 <= 50 (si) inserisci
			if(prezzo(biblioteca[j]) >= (prezzo(biblioteca[i]) - scarto) &&
				prezzo(biblioteca[i]) <= prezzo(biblioteca[i]) + scarto)
			{
				found = 1;
				libriPrezzoSimile[0] = biblioteca[i];
				libriPrezzoSimile[1] = biblioteca[j];
				break;
			}
		}
	}
	if(found == 0){
		return NULL;
	} else {
		return libriPrezzoSimile;
	}
}

float costototale(libro* biblioteca, int n, int an){
	float sum = 0;
	for(int i=0; i<n; i++){
		if(anno(biblioteca[i]) == an){
			sum += prezzo(biblioteca[i]);
		}
	}
	return sum;
}

