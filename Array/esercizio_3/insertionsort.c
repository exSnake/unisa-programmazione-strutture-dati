#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cerca_posizione(int a[], int n, int elem)
{ 
//    TODO
    return 1;
}

void shift_destra(int a[], int h, int k) 
{ 
    while (h >= 0 && a[h] > k) 
    {  
        a[h + 1] = a[h];  
        h = h - 1;  
    }  
    a[h + 1] = k; 
}

void insertion_sort(int a[], int n) 
{ 
    int i;
    for (i = 1; i < n; i++) 
    {  
        /* Move elements of a[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        shift_destra(a, i-1, a[i]);
    }  
}


int main (void){
    char* cognome; 
    int dim = 0;
    char buffer[64];
    
    printf("Inserisci il tuo cognome \n");
    fgets(buffer, sizeof buffer, stdin);
    
    dim = (unsigned)strlen(buffer);
    for (int i=0; i<dim; i++){
        printf("%c ", buffer[i]);
    }    
    //c'e' un problema qui come passare
    insertion_sort((int *)buffer, dim);
    
    for (int i=0; i<dim; i++){
        printf("%c ", buffer[i]);
    }                      
        
    printf("\n");
}
