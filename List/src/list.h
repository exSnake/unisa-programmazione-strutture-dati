#include "item.h"

/*
 * list.h
 *
 *  Created on: 26 mar 2020
 *      Author: exSna
 */

#ifndef LIST_H_
#define LIST_H_

/**
 * Un nodo che verra poi definito nell'implementazione come una lista
 * Che contiene l'oggetto e il riferimento al suo successivo (LinkedList)
 * E' ovviamente un puntatore all'inizio della struttura che sara' definita nel file C
 */
typedef struct node *list;

/**
 *	newList: Costruisce una nuova lista e la restituisce come nil
 *	Sintattica:
 *		newList() -> list
 *	Semantica:
 *		newList() -> nil
 *			Post: Restituisce nil
 */
list newList(void);

/**
 *	emptyList: Controlla se la lista in ingresso e' vuota o meno.
 *	Sintattica:
 *		emptyList(list) -> boolean
 *	Semantica:
 *		emptyList(l) -> b
 *			Post: Se l == NULL, b = TRUE altrimenti FALSE
 */
int emptyList(list l);

/**
 *	tailList: Accetta in ingresso una lista e restituisce una nuova lista a partire dalla coda della prima
 *	Sintattica:
 *		tailList(list) -> list
 *	Semantica:
 *		tailList(l) -> l1
 *			Pre: Accetta in ingresso una lista l non nulla e con piu di 1 elemento
 *			Post: Se l = <a1,a2,a3,...,an> restituisce l1 = <a2,a3,...,an>
 */
list tailList(list l);

/**
 *	consList: Accetta in ingresso un valore e restituisce una nuova lista con quel valore in testa
 *	Sintattica:
 *		consList(item,list) -> list
 *	Semantica:
 *		consList(val,l) -> l1
 *			Pre: val != null, l != null
 *			Post: Se l = <a1,a2,...,an> allora l1 = <val,a1,a2,...,an>
 */
list consList(item val, list l);

/**
 *	getFirst: Restituisce il primo elemento della lista
 *	Sintattica:
 *		getFirst(list) -> item
 *	Semantica:
 *		getFirst(l) -> itm
 *		Pre: l non vuota (non indefinita)
 *		Post: Se l = <a1,a2,...,an> allora itm = a1
 */
item getFirst(list l);

/**
 *	output_list: Stampa a video la lista ricevuta in input
 *	Sintattica:
 *		output_list(list)
 *	Semantica:
 *		output_list(l) -> void
 *			Pre: l non nulla (non indefinita)
 */
void output_list(list l);

/**
 *	sizeList: Fa una visita totale della lista restituendo la dimensione della stessa
 *	Sintattica:
 *		sizeList(list) -> integer
 *	Semantica:
 *		sizeList(l) -> dim
 *			Post: dim = numero di elementi della lista
 */
int sizeList(list l);

/**
 *	posItem: Fa una visita alla lista finche non trova l'item passato come parametro, se non lo trova restituisce -1
 *	Sintattica:
 *
 */
int posItem(list l, item itm);
int searchItem(list l, item itm);
list reverseList(list l);
list removeItem(list l, item itm);
item getItem(list l, int i);
list insertList(list l, int i, item itm);
list removeList(list, int i);

#endif /* LIST_H_ */
