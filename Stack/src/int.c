#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int.h"

int create_stdio(){
    int i;
    printf("Inserisci un numero: ");
    return get_int();
}

int create(int x){
    return x;
}

int somma(int x, int y){
    return x + y;
}

int equals(int x, int y){
    return x == y;
}

void to_string(int x){
    printf("%d\n", x);
}

int get_int(){
    int input = 0;
    char *buffer = (char *)malloc(256);
    fgets(buffer, 256, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    input = atoi(buffer);
    free(buffer);
    return input;
}
