#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

void input_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Inserisci l'elemento in posizione %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("End\n");
}

void finput_array(char *file_name, int a[], int n)
{
    FILE *fd;
    //apre il file
    fd = fopen(file_name, "r");
    if( fd == NULL ) {
        printf("Impossibile aprire il file %s\n", file_name);
    } else {
        for(int i = 0; i < n; i++){
            fscanf(fd, "%d", &a[i]);
        }
        fclose(fd);
    }
}

void foutput_array(char *file_name, int a[], int n)
{
    FILE *fd;

    fd = fopen(file_name, "w");
    if( fd == NULL ) {
        printf("Impossibile aprire il file %s\n", file_name);
    } else {
        for(int i = 0; i < n; i++){
            fprintf(fd, "%d\n", a[i]);
        }
        fclose(fd);
    }
}

int confronta_array(int a[], int b[], int n)
{
    int i = 0;
    while(i < n && a[i] == b[i] )
        i++;
    return i == n ? 1 : 0;
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
        
    return i < n ? i : -1;
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

void somma_array(int a[], int b[], int c[], int n){
    for(int i = 0; i < n; i++){
        c[i] = a[i] + b[i];
    }
}
