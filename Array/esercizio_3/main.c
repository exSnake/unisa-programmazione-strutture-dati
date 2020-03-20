#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cerca_posizione(int a[], int n, int elem);
void shift_destra(int a[], int h, int k);
void insertion_sort(int a[], int n);

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Specificare il cognome e la lunghezza del cognome come parametro\n");
        exit(1);
    }
    int dim = *argv[2];

    char cognome = calloc(dim, sizeof(char));
    strcpy(argv[2],cognome);

    insertion_sort(cognome, dim);
    
    for (int i=0; i<dim; i++){
        printf("%c ", argv[2][i]);
    }                      
        
    printf("\n");
    
    system("pause");

}

int cerca_posizione(int a[], int n, int elem)
{ 

   //return p; 
}

void shift_destra(int a[], int h, int k) 
{ 
            
}

void insertion_sort(int a[], int n) 
{ 
   for(int i = 0; i < n; i++){
       printf("%d", a[i]);
   }
}