#include "stack.h"

#include <stdlib.h>

StackOfAct new_StackOfAct(){
    StackOfAct res;
    res.list = NULL;
    return res;
}

boolean StackOfAct_isEmpty(StackOfAct* p) {
    return ListOfAct_isEmpty(&p->list);
}

void StackOfAct_clear(StackOfAct* p) {
    p->list = NULL;
}

void StackOfAct_push(StackOfAct* p, Act v) {
    ListOfAct_addFirst(&p->list, v);
}

Act StackOfAct_pop(StackOfAct* p) {
    return ListOfAct_removeFirst(&p->list);
}

