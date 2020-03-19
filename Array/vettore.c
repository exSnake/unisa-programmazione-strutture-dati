#include <stdio.h>

void input_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Inserisci l'elemento in posizione %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("End\n");
}

void stampa_array(int a[], int n){
    printf("Stampo array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("elemento %d:%d\n", i, a[i]);
    }
    
}

void inserisci(int a[], int *n, int el, int pos){
    for (int i = *n; i > pos; i--)
    {
        a[i] = a[i-1];
    }

    a[pos] = el;
    (*n)++;
}

void elimina(int a[], int *n, int pos){
    if(pos < *n && pos >= 0){
        for (int i = pos; i < *n; i++){
            a[i] = a[i+1];
        }      
    }
    (*n)--;
}

int minimo(int a[], int n){
    int min = a[0];
    if(n > 0){
        for (int i = 1; i < n; i++)
        {
            if (a[i] < min)
                min = a[i];
        }
    }
    return min;
}

int ricerca(int a[], int n, int el){
    //Versione short-circuit
    int i = 0;
    int trovato = 0;
    while (i < n && a[i] != el)
        i++;
    return trovato ? i : -1;
    //Versione fatta da me
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] == el)
    //     {
    //         return i;
    //     }        
    // }
    // return 0;
}
