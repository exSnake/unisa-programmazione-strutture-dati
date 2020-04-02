
#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

typedef enum statoAutomobile{
    Nuova,
    UsataKM0,
    Usata
}statoAutomobile;

typedef struct _automobile *automobile;

/**
 * titolo: Restituisce il modello dell'automobile
 * Sintattica:
 *    modello(automobile) -> char*
 * Semantica:
 *    modello(a) -> mod
 *       Post: restituisce il modello dell'automobile a
 */
char *modello(automobile a);

/**
 * titolo: Restituisce il produttore dell'automobile
 * Sintattica:
 *    produttore(automobile) -> char*
 * Semantica:
 *    produttore(a) -> mod
 *       Post: restituisce il produttore dell'automobile a
 */
char *produttore(automobile a);

/**
 * tipologia: Restituisce la tipologia dell'automobile
 * Sintattica:
 *    tipologia(automobile) -> char*
 * Semantica:
 *    tipologia(a) -> mod
 *       Post: restituisce la tipologia dell'automobile a
 */
char *tipologia(automobile a);

/**
 * stato: Restituisce lo stato dell'automobile
 * Sintattica:
 *    stato(automobile) -> statoAutomobile
 * Semantica:
 *    stato(a) -> stato
 *       Post: restituisce lo stato dell'automobile a
 */
statoAutomobile stato(automobile a);

/**
 * cilindrata: Restituisce la cilindrata dell'automobile
 * Sintattica:
 *    cilindrata(automobile) -> float
 * Semantica:
 *    cilindrata(a) -> cc
 *       Post: restituisce la cilindrata dell'automobile a
 */
float cilindrata(automobile a);

/**
 * kilometri: Restituisce i kilometri dell'automobile
 * Sintattica:
 *    kilometri(automobile) -> float
 * Semantica:
 *    kilometri(a) -> km
 *       Post: restituisce i km dell'automobile a
 */
float kilometri(automobile a);

/**
 * prezzo: Restituisce il prezzo dell'automobile
 * Sintattica:
 *    prezzo(automobile) -> float
 * Semantica:
 *    prezzo(a) -> prz
 *       Post: restituisce il prezzo dell'automobile a
 */
float prezzo(automobile a);

/**
 * creaLibro: Restituisce l'automobile creata dopo aver ricevuto in ingresso i parametri necessari
 * Sintattica:
 *    creaAutomobile() -> automobile
 * Semantica:
 *    creaAutomobile(modello,produttore,tipologia,cilindrata,stato,km,prezzo) -> automobile
 *       Pre: modello,produttore,tipologia != NULL - cilindrata,km,prezzo,stato >= 0
 *       Post: Restituisce l'automobile creata; 
 */
automobile creaAutomobile(char *modello, char *produttore, char *tipo, statoAutomobile st, float cc, float km, float prz);

/**
 * aggiornaPrezzo(automobile, float): riceve in ingresso un'automobile e il nuovo prezzo e lo modifica per riferimento
 * 
 * Sintattica:
 *    aggiornaPrezzo(automobile,float)
 * Semantica:
 *    aggiornaPrezzo(automobile, nuovoPrezzo)
 *       Pre: nuovoPrezzo >= 0, automobile != NULL
 *       Post: se era automobile->prezzo == 100, nuovoPrezzo = 200 allora automobile->prezzo == 200
 */
void aggiornaPrezzo(automobile *automobile, float nuovoPrezzo);

/**
 * confrontaAuto: Riceve in ingresso 2 auto e un terzo parametro da confrontare
 *                ritorna 0 se sono uguali per entrambe, 1 se la prima auto e' maggiore, 2 il contrario
 * Sintattica:
 *    confrontaAuto(automobile,automobile,char*,float) -> int
 * Semantica:
 *    confrontaAuto(auto1,auto2,param,value) -> ris
 *       Pre: auto1 e auto2 != NULL, param == ['cilindrata'|'km'|'prezzo']
 *       Post: Ritorna -1 se ha fallito, 
 *                    0 se auto1->value == auto2->value, 
 *                    1 se auto1->value > auto2->value, 
 *                    2 se auto2->value > auto1->value
 *                      10 se [auto1,auto2]->value == 0 && [auto1,auto2] == Nuova
 *                      11 se [auto1,auto2]->value == 0 && auto1 == Nuova
 *                      12 se [auto1,auto2]->value == 0 && auto2 == Nuova
 */
int confrontaAuto(automobile auto1, automobile auto2, char* param);


#endif /* AUTOMOBILE_H_ */