#include "automobile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _automobile
{
    char* nomeModello[100];
    char *nomeProduttore[50];
    char *tipologia[50];
    float cilindrata;
    statoAutomobile stato;
    float km;
    float prezzo;
};

char *modello(automobile a){
    return a->nomeModello;
}

char *produttore(automobile a){
    return a->nomeProduttore;
}

char *tipologia(automobile a){
    return a->tipologia;
}

statoAutomobile stato(automobile a){
    return a->stato;
}

float cilindrata(automobile a){
    return a->cilindrata;
}

float kilometri(automobile a){
    return a->km;
}

float prezzo(automobile a){
    return a->prezzo;
}

automobile creaAutomobile(char *modello, char *produttore, char *tipo, statoAutomobile st, float cc, float km, float prz){
    automobile autom = malloc(sizeof(*autom));
    if (modello == NULL || produttore == NULL || tipo == NULL || st < 0 || st > 2 || cc < 0 || km < 0 || prz < 0 ){
        printf("Parametri errati, impossibile creare l'automobile");
        return NULL;
    }
    strcpy(autom->nomeModello, modello);
    strcpy(autom->nomeProduttore, produttore);
    strcpy(autom->tipologia, tipo);
    autom->stato = st;
    autom->cilindrata = cc;
    autom->km = km;
    autom->prezzo = prz;
    return autom;
}

void aggiornaPrezzo(automobile *autom, float nuovoPrezzo){
    if (nuovoPrezzo < 0 || (*autom) == NULL)
    {
        printf("Errore prezzo");
        return;
    }
    (*autom)->prezzo = nuovoPrezzo;
}

int confrontaAuto(automobile auto1, automobile auto2, char *param){
    float value1 = 0;
    float value2 = 0;
    if(auto1 == NULL || auto2 == NULL || param == NULL){
        printf("Parametri richiesti mancanti");
        return -1;
    }
    //Prendo il valore
    if (strcmp(param, "km") == 0 || strcmp(param, "kilometri") == 0)
    {
        value1 = auto1->km;
        value2 = auto2->km;
    }
    else if (strcmp(param, "cc") == 0 || strcmp(param, "cilindrata") == 0)
    {
        value1 = auto1->cilindrata;
        value2 = auto2->cilindrata;
    }
    else if (strcmp(param, "prz") == 0 || strcmp(param, "prezzo") == 0)
    {
        value1 = auto1->prezzo;
        value2 = auto2->prezzo;
    } else {
        return -1;
    }

    //Confronto
    if (value1 > value2){
        return 1;
    }
    else if(value1 < value2){
        return 2;
    }
    else if(value1 == value2){
        if (value1 > 0){
            return 0;
        }
        else { //caso km0
            if (auto1->stato == auto2->stato){
                return 10;
            }
            else if (auto1->stato == Nuova){
                return 11;
            }
            else{
                return 12;
            }
        }
    }
}

