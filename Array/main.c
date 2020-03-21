#include <stdio.h>
#include <stdlib.h>
#include "utility/vettore.h"
#include "utility/vettore_sort.h"
#define MAXELEM 100

int main()
{
    int *a, n, pos, el;

    printf("Inserisci il numero di elementi dell'array: ");
    scanf("%d",&n);
    a = calloc(n, sizeof(int));
    if(a == NULL) {
        printf("Memoria insufficiente \n");
        return -1;
    } 

    input_array(a, n);
    stampa_array(a, n);

    // printf("Inserisci un nuovo elemento nella posizione: ");
    // scanf("%d", &pos);
    // printf("Numero da inserire: ");
    // scanf("%d", &el);

    // inserisci(a, &n, el, pos);
    // stampa_array(a, n);

    // printf("\nElimina l'elemento nella posizione: ");
    // scanf("%d", &pos);

    // elimina(a, &n, pos);
    // stampa_array(a, n);

    // printf("\nIl minimo dell'array e': %d", minimo(a, n));

    // printf("\nRicerca l'elemento: ");
    // scanf("%d", &el);

    // pos = ricerca(a, n, el);
    // if (pos >= 0)
    // {
    //     printf("\nL'elemento e' nella posizione: %d", pos);
    // }
    // else
    // {
    //     printf("\nL'elemento non e' presente nell'array");
    // }
    printf("\n Ordinamento dell'array con Bubble Sort");
    bubble_sort(a, n);
    stampa_array(a, n);
}

void static_implementation(){
    int a[MAXELEM], n, pos, el;
    printf("Inserisci il numero di elementi dell'array: ");
    scanf("%d", &n);

    input_array(a, n);
    stampa_array(a, n);

    printf("Inserisci un nuovo elemento nella posizione: ");
    scanf("%d", &pos);
    printf("Numero da inserire: ");
    scanf("%d", &el);

    inserisci(a, &n, el, pos);
    stampa_array(a, n);

    printf("\nElimina l'elemento nella posizione: ");
    scanf("%d", &pos);

    elimina(a, &n, pos);
    stampa_array(a, n);

    printf("\nIl minimo dell'array e': %d", minimo(a, n));

    printf("\nRicerca l'elemento: ");
    scanf("%d", &el);

    pos = ricerca(a, n, el);
    if (pos >= 0)
    {
        printf("\nL'elemento e' nella posizione: %d", pos);
    }
    else
    {
        printf("\nL'elemento non e' presente nell'array");
    }
}