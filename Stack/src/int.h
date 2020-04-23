#include "math.h"

typedef int myint;

/**
 * crea_punto_stdio: crea un int da standard input
 * Sintattica:
 *     create_stdio() -> int
 * Semantica:
 *     create_stdio() -> i
 */
int create_stdio();

/**
 * crea_punto: accetta in ingresso due coordinate di punto e restituisce un punto
 * Sintattica:
 *     create(int) -> int
 * Semantica:
 *     create(x) -> i
 */
int create(int x);

/**
 * somma: accetta in ingresso due int e ne restituisce la somma algebrica
 * Sintattica:
 *    somma(int,int) -> int
 * Semantica:
 *    somma(x,y) -> i
 *        
 */
int somma(int x, int y);

/**
 * equals: restituisce se p1 == 2
 */
int equals(int p1, int p2);

void to_string(int p);

int get_int();
