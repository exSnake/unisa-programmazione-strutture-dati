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
 *          Pre: l != NULL
 *			Post: Se l->size == 0, b = TRUE altrimenti FALSE 
 */
int empty_list(list l);

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
 *	consList: Accetta in ingresso un valore e restituisce un nuovo nodo con quel valore in testa
 *       - quindi al nuovo nodo->next assegna il vecchio firstnode
 *	Sintattica:
 *		consList(list, item) -> struct node
 *	Semantica:
 *		consList(l, val) -> boolean
 *			Pre: val != null
 *			Post: Se l = <a1,a2,...,an> allora l1 = <val,a1,a2,...,an>
 */
struct node *cons_list(struct node *l, item val);

/**
 *	tailList: Accetta in ingresso una lista e sposta il puntatore in avanti di un nodo
 *	Sintattica:
 *		tailList(list)
 *	Semantica:
 *		tailList(l)
 *			Pre: Accetta in ingresso una lista l non vuota
 *			Post: Se l = <a1,a2,a3,...,an> dopo l = <a2,a3,...,an>
 */
struct node *tail_list(struct node *l);

/**
 * insert_list: Prende in ingresso una lista l, la posizione e l'elemento da inserire 
 * Sintattica:
 *      insert_list(list,int,item) -> boolean
 * Semantica:
 *      insert_list(l,pos,elem) -> b
 *      Pre: l != NULL o empty_list(l) != -1 && 0 < pos <= size_list(l) && elem != NULL
 *      Post: l = <a1,a_pos-1,a_pos,...,an> dopo l = <a1,a2,a_pos-1,elem,a_pos,...,an>
 */
int insert_list(list l, int pos, item elem);

/**
 * insert_item: Prende in ingresso una lista l, la posizione e l'elemento da inserire e ne restituisce la testa
 * Sintattica:
 *      insert_item(list,int,item) -> node
 * Semantica:
 *      Pre:
 *      Post:
 */
static struct node *insert_item(list l, int pos,item elem);

#endif /* LIST_H_ */