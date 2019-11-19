#include "stack.h"

#include <stdlib.h>

StackOfAct new_StackOfAct(){
    StackOfAct res;
    Stack_arr(res) = (Act*) malloc(512*sizeof(Act));
    Stack_top(res) = 0;
    return res;
}

boolean StackOfAct_isEmpty(StackOfAct* S){
    return(Stack_top(*S) == 0);
}

void StackOfAct_clear(StackOfAct* S) {
    Stack_top(*S) = 0;
}

void StackOfAct_push(StackOfAct* S, Act v){
    Stack_top(*S)++;
	Stack_getTop(*S) = v;
}

Act StackOfAct_pop(StackOfAct* S, Act* X){

    *X = Stack_getTop(*S);
	Stack_top(*S)--;
    
    return *X;
}

