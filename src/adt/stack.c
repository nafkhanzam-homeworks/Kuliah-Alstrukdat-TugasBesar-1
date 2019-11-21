#include "stack.h"

#include <stdlib.h>

StackOfAct new_StackOfAct(){
    StackOfAct res;
    list(&res) = NULL;
    return res;
}

boolean StackOfAct_isEmpty(StackOfAct* p) {
    return ListOfAct_isEmpty(&list(p));
}

void StackOfAct_clear(StackOfAct* p) {
    list(p) = NULL;
}

void StackOfAct_push(StackOfAct* p, Act v) {
    ListOfAct_addFirst(&list(p), v);
}

Act StackOfAct_pop(StackOfAct* p) {
    return ListOfAct_removeFirst(&list(p));
}

