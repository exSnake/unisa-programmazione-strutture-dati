#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automobile.h"

/* Esercizio 10 – Concessionaria */
#define BUFFER_SIZE 1024

FILE *Fopen(const char *path, const char *mode);
int countFileLine(FILE *fp);

automobile scanfAuto();
int printMenu();
void salvaAuto(automobile a);
automobile* caricaDati(int *size);
void inserisciAuto(automobile *dest,int *size, automobile auto1);
int contaAuto(automobile *automobili, int size, char *param, float value);
void printAutomobili(automobile *automobili, int size);

int main()
{
    int size = 0;
    int choice = 0;
    automobile *concessionaria;
    concessionaria = caricaDati(&size);
    do
    {
        choice = printMenu();
        if (choice == 1)
        {
            automobile a = scanfAuto();
            inserisciAuto(concessionaria, &size, a);
        } else if ( choice == 2) {
            printAutomobili(concessionaria,size);
            getchar();
        }
        
    } while (choice != 0);
    free(concessionaria);
    return 0;
}

int printMenu(){
    int input = 0;
    char *buffer = (char *) malloc(BUFFER_SIZE);
    do
    {
        //system("clear");
        printf("Fai una scelta:\n\t1.Aggiungi Auto\n\t2.Visualizza Auto\n\t3.Conta Auto\n\t0.Exit\n");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0'; 
        input = atoi(buffer);
    } while (input < 0 || input > 3);
    free(buffer);
    return input;
}

automobile scanfAuto(){
    char *buffer;
    char* mod;
    char* prod;
    char* tip;
    statoAutomobile st;
    float cc, km, prz;

    printf("Creazione nuova auto da std input\n");

    buffer = (char *) malloc (BUFFER_SIZE);
    printf("Inserisci Modello: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    mod = (char *) calloc (strlen(buffer) + 1, sizeof(char));
    strcpy(mod,buffer);

    printf("\nProduttore: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    prod = (char *)calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(prod, buffer);

    printf("\nTipo: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    tip = (char *)calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(tip, buffer);

    printf("\nSeleziona 0:Nuova, 1:UsataKm0, 2:Usata\nStato: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    st = atoi(buffer);

    printf("\nCilindrata: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    cc = atof(buffer);

    printf("\nPrezzo: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    prz = atof(buffer);

    printf("\nKm Attuali: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    km = atof(buffer);

    return creaAutomobile(mod,prod,tip,st,cc,km,prz);
}

void inserisciAuto(automobile *dest,int *size, automobile auto1){
    (*size)++;
    dest = (automobile *)realloc(dest, sizeof(automobile *) * (*size));
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
    n = countFileLine(fp) - 1; //last newline;
    printf("n:%d", n);
    fclose(fp);
    if(n == 0){
        printf("Niente da caricare");
        return NULL;
    }
    
    fp = Fopen("automobili.txt", "r");
    tmp = (automobile *) malloc(sizeof(tmp) * (n));
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
