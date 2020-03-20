#ifndef VETTORE
#define VETTORE

void input_array(int a[], int n);
void finput_array(char *file_name, int a[], int n);
void foutput_array(char *file_name, int a[], int n);
int confronta_array(int a[], int b[], int n);
void stampa_array(int a[], int n);
void inserisci(int a[], int *n, int el, int pos);
void elimina(int a[], int *n, int pos);
int minimo(int a[], int n);
int ricerca(int a[], int n, int el);
int ricercaord(int a[], int n, int el);
int ricercabin(int a[], int n, int el);
void somma_array(int a[], int b[], int c[], int n);

#endif