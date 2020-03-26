#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cerca_posizione(char a[], int n, int elem){
    int p;  // posizione da restituire
    int i = n-1; 

    while(i > 0 && a[i] > elem) 
        i--;

    if(a[i] <= elem)
            p = i+1; 
    else p = i;  //  usciti dal ciclo con i = 0 - elem è l’elemento minore

    return p; 
}

void shift_destra(char a[], int h, int k) 
{ 
    for (int i = k; i >= h; i--) 
        a[i+1] = a[i];  
}

void insertion_sort(char a[], int n) 
{ 
    int i, p, next;           

    for (i = 1; i < n; i++) {
            next = a[i];

            p = cerca_posizione(a, i, next);
            shift_destra(a, p, i-1);

            a[p] = next;  
    }
}

char* get_surname()
{
    char buffer[64];
    printf("Inserisci il tuo cognome \n");
    fgets(buffer, sizeof buffer, stdin);
    int strLength = strlen(buffer);
    if(strLength == 0) {
        printf("\"Cognome\" non inserito.\n");
        exit(1);
    } else {
        char *strInHeap = (char *)malloc((strLength + 1) * sizeof(char));
        strcpy(strInHeap, buffer);
        return strInHeap;
    }
}


int main (void){
    char* cognome; 
    cognome = get_surname();
    int dim = (unsigned)strlen(cognome);

    for (int i=0; i<dim; i++){
        printf("%c ", cognome[i]);
    }    

    insertion_sort(&cognome[0], dim);
    
    for (int i=0; i<dim; i++){
        printf("%c ", cognome[i]);
    }                      
        
    printf("\n");
}
