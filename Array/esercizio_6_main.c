#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility/vettore.h"
#define M 20

int run_test_inserisci(char *test_name, int n, int el, int pos);

int main(int argc, char *argv[])
{
    FILE *test_suite, *result;
    char tc_id[M];
    int n, el, pos;

    if(argc < 2) {
        printf("Nome del file di test suite mancante \n");
        exit(1);
    }

    //Apre i file test suite in lettura e result in scrittura

    test_suite = fopen(argv[1], "r");
    result = fopen("result.txt", "w");
    if( test_suite == NULL || result == NULL) {
        printf("Errore nell'apertura dei file");
        exit(1);
    }

    //ne legge il contenuto delle righe riga per riga
    //Se il contenuto letto e minore di 2 allora il file e' terminato o c'e qualche errore

    while(fscanf(test_suite, "%s %d\n", tc_id, &n) == 2)
    {
        if (run_test_inserisci(tc_id, n, el, pos))
            fprintf(result,"%s PASS\n", tc_id);
        else
            fprintf(result,"%s FAIL\n",tc_id);
    }
    fclose(test_suite);
    fclose(result);
}

int run_test_inserisci(char *test_name, int n, int el, int pos)
{
    char input1_fname[M], input2_fname[M], output_fname[M], oracle_fname[M];
    //static const char INPUT[] = "_input.txt"
    //static const char ORACLE[] = "_oracle.txt"

    sprintf(input1_fname, "%s_input1.txt", test_name);
    sprintf(input2_fname, "%s_input2.txt", test_name);
    sprintf(oracle_fname, "%s_oracle.txt", test_name);
    sprintf(output_fname, "%s_output.txt", test_name);

    int *a = (int*) calloc((n), sizeof(int));
    int *b = (int*) calloc((n), sizeof(int));
    int *c = (int*) calloc((n), sizeof(int));
    if(a == NULL || b == NULL || c == NULL) {
        printf("Memoria insufficiente");
        return -1;
    }
    finput_array(input1_fname, a, n);
    finput_array(input2_fname, b, n);
    somma_array(a,b,c,n);
    foutput_array(output_fname, c, n);

    int *oracle = (int*) calloc(n, sizeof(int));
    if(oracle == NULL) {
        printf("Memoria insufficiente");
        return -1;
    }
    finput_array(oracle_fname, oracle, n);
    
    return confronta_array(c, oracle, n);
}