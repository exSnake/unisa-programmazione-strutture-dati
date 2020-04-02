/*
 * libro.h
 *
 *  Created on: 27 mar 2020
 *      Author: exSna
 */

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct miolibro *libro;

/**
 * creaLibro: Restituisce il libro creato dopo aver ricevuto in ingresso i parametri necessari
 * Sintattica:
 *    creaLibro(char*,char*,float,in) -> libro
 * Semantica:
 *    creaLibro(titolo,editore,prezzo,anno) -> l
 *       Post: Restituisce un libro creato; 
 */
libro creaLibro(char *titolo, char* editore, float prezzo, int anno);

/**
 * titolo: Restituisce il titolo del libro passato
 * Sintattica:
 *    titolo(libro) -> char*
 * Semantica:
 *    titolo(l) -> tit
 *       Post: restituisce il titolo del libro l
 */  
char* titolo(libro l);

/**
 * titolo: Restituisce l'editore del libro passato
 * Sintattica:
 *    editore(libro) -> char*
 * Semantica:
 *    editore(l) -> ed
 *       Post: restituisce l'editore del libro l
 */
char* editore(libro l);

/**
 * titolo: Restituisce l'anno del libro passato
 * Sintattica:
 *    anno(libro) -> char*
 * Semantica:
 *    anno(l) -> an
 *       Post: restituisce l'anno del libro l
 */
int anno(libro l);

/**
 * prezzo: ritorna il prezzo di un libro
 * Sintattica:
 *    prezzo(libro) -> float;
 * Semantica:
 *    prezzo(l) -> p;
 *       Post: Ritorna il prezzo p
 */
float prezzo(libro l);
/**
 * sconto: Sconta il prezzo di un libro del X%
 * Sintattica:
 *    sconto(libro,float) -> float;
 * Semantica:
 *    sconto(l,percentuale) -> sconto;
 *
 */
float sconto(libro *l, float percentuale);


#endif /* LIBRO_H_ */
