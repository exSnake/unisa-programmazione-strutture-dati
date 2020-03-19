#include <stdio.h>
#include "vettore.h"
#define MAXELEM 100

void main()
{
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