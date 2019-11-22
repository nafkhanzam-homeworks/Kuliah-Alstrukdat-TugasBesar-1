#if !defined(__stack_h__)
#define __stack_h__

#include "../headers.h"

typedef struct _StackOfAct {
    ListOfAct list;
} StackOfAct;

StackOfAct new_StackOfAct();
boolean StackOfAct_isEmpty(StackOfAct* p);
void StackOfAct_clear(StackOfAct* p);
void StackOfAct_push(StackOfAct* p, Act v);
Act StackOfAct_pop(StackOfAct* p);

#endif // __stack_h__
