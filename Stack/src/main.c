#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int.h"
#include "stack_a.h"

#define BUFFER_SIZE 256

int print_menu();
void scanf_stack(stack s);
void to_binary();

int main(int argc, char const *argv[])
{
    int choice;
    stack main = new_stack();
    stack s2 = new_stack();
    while((choice = print_menu()) != 0){
        switch (choice)
        {
            case 1:
                scanf_stack(main);
                break;
            case 2:
                scanf_stack(s2);
                break;
            case 3:
                main = reverse_stack(main);
                break;
            case 4:
                main = merge_stack(main,s2);
                break;
            case 5:
                to_binary();
                printf("Premi INVIO per continuare..."); getchar();
                break;
            case 6:
                output_stack(main);
                printf("Premi INVIO per continuare..."); getchar();
                break;
            case 7:
                output_stack(s2);
                printf("Premi INVIO per continuare..."); getchar();
                break;
            default:
                break;
        }
    }
    return 0;
}

int print_menu(){  
    //Menu
    system("clear");
    printf("Fai una scelta:\n\t"
           "1.Stdio Stack MAIN\n\t"
           "2.Stdio Stack S2\n\t"
           "3.Reverse\n\t"
           "4.Merge MAIN S2 -> MAIN\n\t"
           "5.Conversione Binaria\n\t"
           "6.Stampa MAIN\n\t"
           "7.Stampa S2\n\t"
           "\n"
           "0.Exit\n");
    //EndMenu
    return get_int();
}

void scanf_stack(stack s){
    item itm;
    while ((itm = create_stdio()) != -1)
        push(s,itm);
}

void to_binary(){
    printf("Inserisci un numero da convertire in binario: ");
    stack bin = new_stack();
    int i = get_int();
    while (i > 1){
        int mod = i % 2;
        push(bin, create(mod));
        i = (i-mod)/2;
    }
    push(bin,create(i));
    
    printf("Risultato binario: ");
    while (!empty_stack(bin))
    {
        printf("%d",top(bin));
        pop(bin);
    }
    printf("\n");
}
