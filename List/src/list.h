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
typedef struct c_list *list;

/**
 *	newList: Costruisce una nuova lista e ne restituisce il puntatore o NULL se
        - l'allocamento e' fallito
 *	Sintattica:
 *		- newList() -> list
 *	Semantica:
 *		- newList() -> l
 *			- - Post: Restituisce NULL se l'allocamento e' fallito altrimenti restituisce
            - - il puntatore alla lista vuota
 */
list new_list(void);

/**
 *	emptyList: Controlla se la lista in ingresso e' vuota o meno.
 *	Sintattica:
 *		emptyList(list) -> boolean
 *	Semantica:
 *		emptyList(l) -> b
 *			Post: Se l->size == 0, b = TRUE altrimenti FALSE
 */
int empty_list(list l);

/**
 *	consList: Accetta in ingresso un valore e restituisce una nuova lista con quel valore in testa
 *       - quindi al nuovo nodo->next assegna il vecchio firstnode
 *	Sintattica:
 *		consList(item,list) -> list
 *	Semantica:
 *		consList(val,l) -> boolean
 *			Pre: val != null
 *			Post: Se l = <a1,a2,...,an> allora l1 = <val,a1,a2,...,an>
 */
int cons_list(item val, list l);

/**
 *	tailList: Accetta in ingresso una lista e sposta il puntatore in avanti di un nodo
 *	Sintattica:
 *		tailList(list)
 *	Semantica:
 *		tailList(l)
 *			Pre: Accetta in ingresso una lista l non vuota
 *			Post: Se l = <a1,a2,a3,...,an> dopo l = <a2,a3,...,an>
 */
void tail_list(list l);

/**
 *	getFirst: Restituisce il primo elemento della lista
 *	Sintattica:
 *		getFirst(list) -> item
 *	Semantica:
 *		getFirst(l) -> itm
 *		Pre: l non vuota (non indefinita)
 *		Post: Se l = <a1,a2,...,an> allora itm = a1
 */
item get_first(list l);

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
int size_list(list l);

/**
 *	posItem: Fa una visita alla lista finche non trova l'item passato come parametro, se non lo trova restituisce -1
 *
 */
int pos_item(list l, item itm);

/**
 * get_item: restituisce l'item nella posizione cercata, altrimenti restuisce NULLITEM
 * 
 */
item get_item(list l, int pos);

/**
 * reverse_list: Inverte gli elementi di una lista l restituendo una lista l1
 * Sintattica:
 *    reverse_list(list) -> list
 * Semantica:
 *     reverse_list(l) -> l1
 *     Post: se l = <a1,a2,...,an> l1 = <an,...,a2,a1>
 */
list reverse_list(list l);

/**
 * output_list: stampa in console una lista l
 * Sintattica:
 *     output_list(list) -> void
 * Semantica:
 *     output_list(l)
 */
void output_list(list l);

/**
 * clone_list: crea un clone della lista passata in ingresso e la restituisce
 * Sintattica:
 *     output_list(list) -> list
 * Semantica:
 *     output_list(l) -> l
 *            Post: se l = <a1,a2,...,an> l1 = <b1,b2,...,bn> dove a1 == b1, a2 == b2, ... , an == bn
 */
list clone_list(list l);

/**
 * delete_item: accetta in ingresso una lista e la posizione dell'item da eliminare e lo elimina
 * Sintattica:
 *     delete_item(list,int) -> boolean
 * Semantica:
 *     delete_item(l, pos) -> found
 *            Pre: pos < size_list e pos >= 0
 *            Post: Se l = <a1,a2,a3...,an> e pos = 1 allora l = <a1,a3...,an> e found = 1 (true)
 *                   se 0 > pos > n found = 0 (false) 
 */
int delete_item(list l, int pos);

int insert_item(list l, int pos, item val);

#endif /* LIST_H_ */
