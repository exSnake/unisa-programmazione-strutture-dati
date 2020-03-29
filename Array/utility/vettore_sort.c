#include "vettore_sort.h"
#include <stdio.h>

void insertion_sort(int a[], int n) 
{ 
    int i, p, next;           

    for (i = 1; i < n; i++) {
        next = a[i];

        p = cerca_posizione(a, i, next);
        shift_destra(a, p, i-1);

        a[p] = next;  
    }
}

int cerca_posizione(int a[], int n, int elem)
{
    int p; // posizione da restituire
    int i = n - 1;

    while (i > 0 && a[i] > elem)
        i--;

    if (a[i] <= elem)
        p = i + 1;
    else
        p = i; //  usciti dal ciclo con i = 0 - elem è l’elemento minore

    return p;
}

void shift_destra(int a[], int h, int k)
{
    for (int i = k; i >= h; i--)
        a[i + 1] = a[i];
}


void bubble_sort(int a[], int n)
{
    int swapped = 1;
    while (swapped == 1)
    {
        swapped = 0;
        for (int i = 0; i < (n - 1); i++)
        {
            if (a[i] > a[i + 1])
            {
                scambia(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }
    }
}

void scambia(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}