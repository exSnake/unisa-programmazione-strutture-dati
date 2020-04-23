#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack_l.h"
#include "list.h"

struct c_stack{
    list top;
};

stack new_stack(){
    stack s = malloc(sizeof(struct c_stack));
    if(s == NULL)
        return NULL;
    s->top = new_list();
    return s;
}

int empty_stack(stack s){
    return empty_list(s->top);
}

int push(stack s, item itm){
    return insert_list(s->top,0,itm);
}

int pop(stack s){
    if(empty_stack(s))
        return 0;
    return remove_list(s->top,0);
}

item top(stack s){
    return get_first(s->top);
}

stack clone_stack(stack s){
    stack clone = new_stack();
    clone->top = clone_list(s->top);
}

stack reverse_stack(stack s){
    stack reverse = new_stack();
    while(!empty_stack(s)){
        push(reverse,top(s));
        pop(s);
    }

}

void output_stack(stack s){
    output_list(s->top);
}
