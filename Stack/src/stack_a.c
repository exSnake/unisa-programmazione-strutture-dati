#include <stdio.h>
#include <stdlib.h>
#include "stack_a.h"

#define MAXSTACK 50
#define ADDSIZE 20

struct c_stack {
     item *vet;
     int size;
     int top;
};


stack new_stack(){
    stack s = malloc(sizeof(struct c_stack));
    if (s == NULL)
        return NULL;
    s->vet = malloc(MAXSTACK * sizeof(item));
    if (s->vet == NULL)
        return NULL;
    s->size = MAXSTACK;
    s->top = 0;
    return s;
}

int empty_stack(stack s){
    return s->top == 0;
}

int push(stack s, item itm){
    if (s->top == s->size){  // necessario il resizing dello stack
        item *tmp = realloc(s->vet, (s->size + ADDSIZE) * sizeof(item));
        if (tmp == NULL)
            return 0;
        s->vet = tmp;
        (s->size) += ADDSIZE;
    }
    s->vet[s->top] = itm; 
    (s->top)++; 
    return 1;
}

int pop(stack s){
    if (s->top == 0)
        return 0;
    (s->top)--;
    return 1;
}

item top(stack s){
    return s->top > 0 ? s->vet[s->top - 1] : NULLITEM;
}

stack clone_stack(stack s){
    stack clone = new_stack();
    if(clone == NULL)
        return NULL;
    for (int i = 0; i < s->top; i++)
        push(clone, s->vet[i]);
    return clone;
}

stack reverse_stack(stack s){
    stack tmp = clone_stack(s);
    stack reverse = new_stack();
    while (!empty_stack(tmp)){
        push(reverse, top(tmp));
        pop(tmp);
    }
    return reverse;
}

stack merge_stack(stack s1, stack s2){
    stack tmp_s1 = reverse_stack(s1);
    stack tmp_s2 = reverse_stack(s2);
    stack merged = new_stack();
    while (!empty_stack(tmp_s2))
    {
        push(merged, top(tmp_s2));
        pop(tmp_s2);
    }
    while (!empty_stack(tmp_s1))
    {
        push(merged, top(tmp_s1));
        pop(tmp_s1);
    }
    return merged;    
}

void append_stack(stack dest, stack add)
{
    while (!empty_stack(add))
    {
        push(dest, top(add));
        pop(add);
    }
}

void output_stack(stack s){
    printf("Stampo stack:\n");
    stack tmp = clone_stack(s);
    while (!empty_stack(tmp)){
        output_item(top(tmp));
        pop(tmp);
    }
}
