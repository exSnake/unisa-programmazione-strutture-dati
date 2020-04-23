#include "item.h"

typedef struct c_stack *stack;

/**
 * new_stack: restituisce un'istanza di un nuovo stack
 * Sintattica
 *    new_stack() -> stack
 * Semantica: 
 *    new_stack() -> s
 *      Post: s = nil;
 */
stack new_stack();

/**
 * empty_stack: Dato uno stack controlla se e' vuoto
 * Sintattica
 *    empty_stack(stack) -> boolean
 * Semantica
 *    empty_stack(s) -> b
 *       Post: Se s == nil -> b = true altrimenti b = false
 */
int empty_stack(stack s);

/**
 * Sintattica
 *    push(stack, item) -> boolean
 * Semantica
 *    push(s, itm) -> b
 *       Pre: s->size < MAXSTACK
 *       Post: Se s = <a1,a2,...,an> -> s' = <itm,a1,a2,...,an> 
 */
int push(stack s, item itm);

/**
 * Sintattica
 *    pop(stack) -> boolean
 * Semantica
 *    pop(s) -> i
 *      Post: Se s = <a1,a2,...,an>, i = true, s' = <a2,...,an>
 *          Se s = nil, i = false
 */
int pop(stack s);

/**
 * Sintattica
 *    top(stack) -> item
 * Semantica
 *    top(s) -> itm
 *       Pre: !emptystack(s)
 *       Post: Se s = <a1,a2,...,an>, allora itm = a1
 */
item top(stack s);

/**
 * Sintattica:
 *    clone_stack(stack) -> stack
 * Semantica:
 *    clone_stack(s) -> clone
 *       Post: s = <a1,a2,...,an> -> clone = <a1,a2,...,an>
 */
stack clone_stack(stack s);

/**
 * Sintattica:
 *    reverse_stack(stack) -> stack
 * Semantica:
 *    reverse_stack(s) -> reverse
 *       Post: s = <a1,a2,...,an> -> reverse = <an,...,a2,a1>
 */
stack reverse_stack(stack s);

/**
 * 
 */
stack merge_stack(stack s1, stack s2);

void output_stack(stack s);
