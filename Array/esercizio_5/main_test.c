#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#define M 20

int run_test_inserisci(char *test_name, int n, int el, int pos);

int main(int argc, char *argv[])
{
    FILE *test_suite, *result;
    char tc_id[M];
    int n, el, pos;

    if(argc < 3) {
        printf("Nomi dei file mancanti \n");
        exit(1);
    }

    //Apre i file test suite in lettura e result in scrittura

    test_suite = fopen(argv[1], "r");
    result = fopen(argv[2], "w");
    if( test_suite == NULL || result == NULL) {
        printf("Errore nell'apertura dei file");
        exit(1);
    }

    //ne legge il contenuto delle righe riga per riga
    //Se il contenuto letto e minore di 2 allora il file e' terminato o c'e qualche errore

    while(fscanf(test_suite, "%s %d %d %d\n", tc_id, &n, &el, &pos) == 4)
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
    char input_fname[M], output_fname[M], oracle_fname[M];
    //static const char INPUT[] = "_input.txt"
    //static const char ORACLE[] = "_oracle.txt"

    sprintf(input_fname, "%s_input.txt", test_name);
    sprintf(oracle_fname, "%s_oracle.txt", test_name);
    sprintf(output_fname, "%s_output.txt", test_name);

    int *a = (int*) calloc((n+1), sizeof(int));
    if(a == NULL) {
        printf("Memoria insufficiente");
        return -1;
    }
    finput_array(input_fname, a, n);
    printf("n:%d el:%d pos:%d",n,el,pos);
    inserisci(a, &n, el, pos);
    foutput_array(output_fname, a, n);

    int *oracle = (int*) calloc(n, sizeof(int));
    if(oracle == NULL) {
        printf("Memoria insufficiente");
        return -1;
    }
    finput_array(oracle_fname, oracle, n);
    
    return confronta_array(a, oracle, n);
}