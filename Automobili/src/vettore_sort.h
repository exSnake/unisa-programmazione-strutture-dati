#include "automobile.h"

#ifndef VETTORE_SORT
#define VETTORE_SORT

int cerca_posizione(int a[], int n, int elem);
void shift_destra(int a[], int h, int k);
void insertion_sort(int a[], int n);

void scambia(automobile *a, automobile *b);
void bubble_sort(automobile *a, int n, int desc);

#endif