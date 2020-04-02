#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automobile.h"

/* Esercizio 10 – Concessionaria */

FILE *Fopen(const char *path, const char *mode);
int countFileLine(FILE *fp);

void salvaAuto(automobile a);
automobile* caricaDati(int *size);
void inserisciAuto(automobile *dest,int *size, automobile auto1);
int contaAuto(automobile *automobili, int size, char *param, float value);
void printAutomobili(automobile *automobili, int size);

int main()
{
    int size = 0;
    automobile* automobili = caricaDati(&size);
    inserisciAuto(automobili, &size, creaAutomobile("BRAVO", "FIAT", "BERLINA", Nuova, 1999.00, 0, 26000.00));
    printAutomobili(automobili, size);
    free(automobili);
    return 0;
}

void inserisciAuto(automobile *dest,int *size, automobile auto1){
    dest[(*size)] = auto1;
    (*size)++;
    dest = realloc(dest, sizeof(dest) * (*size));
    salvaAuto(auto1);
    dest[(*size)] = auto1;
}  

void salvaAuto(automobile a){
    FILE* fp = Fopen("automobili.txt", "a");
    fprintf(fp,"%s-%s-%s-%d-%f-%f-%f\n",modello(a),produttore(a),tipologia(a),stato(a),cilindrata(a),kilometri(a),prezzo(a));
    fclose(fp);
}

automobile* caricaDati(int *size){
    automobile *tmp;
    char line_data[1024];
    char *modello;
    char *produttore;
    char *tipologia;
    int stato;
    float cc, km, prz;
    int n = 0;
    FILE *fp = Fopen("automobili.txt", "r");
    n = countFileLine(fp) -1; //last newline;
    fclose(fp);
    if(n == 0){
        printf("Niente da caricare");
        return NULL;
    }
    
    fp = Fopen("automobili.txt", "r");
    tmp = (automobile) malloc(sizeof(tmp) * (n+1));
    if (tmp == NULL)
    {
        printf("Memoria insufficiente");
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < n; i++){
        fgets(line_data, 1024, fp);
        modello = strtok(line_data, "-");
        produttore = strtok(NULL, "-");
        tipologia = strtok(NULL, "-");
        stato = atoi(strtok(NULL, "-"));
        cc = atof(strtok(NULL, "-"));
        km = atof(strtok(NULL, "-"));
        prz = atof(strtok(NULL, "-"));
        tmp[i] = creaAutomobile(modello,produttore,tipologia,stato,cc,km,prz);
    }
    fclose(fp);
    *size = n;
    return tmp;
}

int contaAuto(automobile *automobili, int size, char* param, float value){
    int count = 0;

    if (strcmp(param, "km") == 0 || strcmp(param, "kilometri") == 0){
        for (int i = 0; i < size; i++){
            if (kilometri(automobili[i]) == value){
                count++;
            }
        }
    } else if (strcmp(param, "cc") == 0 || strcmp(param, "cilindrata") == 0){
        for (int i = 0; i < size; i++){
            if (cilindrata(automobili[i]) == value){
                count++;
            }
        }
    } else if (strcmp(param, "prz") == 0 || strcmp(param, "prezzo") == 0) {
        for (int i = 0; i < size; i++){
            if (prezzo(automobili[i]) == value){
                count++;
            }
        }
    }
    
    return count;
}

void printAutomobili(automobile *automobili, int size){
    printf("Lista %d Automobili:\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%s-%s-%s-%d-%f-%f-%f\n", modello(automobili[i]), produttore(automobili[i]), tipologia(automobili[i]), stato(automobili[i]), cilindrata(automobili[i]), kilometri(automobili[i]), prezzo(automobili[i]));
    }
}

FILE *Fopen(const char *path, const char *mode)
{
    FILE *f = fopen(path, mode);
    if (f == NULL)
    {
        perror(path);
        printf("Impossibile aprire il file\n");
        exit(EXIT_FAILURE);
    }
    return f;
}

int countFileLine(FILE *fp)
{
    int lines = 0;
    char ch;
    while (!feof(fp) && !ferror(fp))
    {
        ch = fgetc(fp);
        if (ch == '\n')
        {
            lines++;
        }
    }
    lines++; //last line without \n
    return lines;
}
