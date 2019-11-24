#if !defined(__stack_h__)
#define __stack_h__

#include "../headers.h"

typedef struct _StackOfAct {
    ListOfAct list;
} StackOfAct;

typedef struct _Stack {
    List list;
} Stack;

StackOfAct new_StackOfAct();
boolean StackOfAct_isEmpty(StackOfAct* p);
void StackOfAct_clear(StackOfAct* p);
void StackOfAct_push(StackOfAct* p, Act v);
Act StackOfAct_pop(StackOfAct* p);

Stack new_Stack();
boolean Stack_isEmpty(Stack* p);
void Stack_clear(Stack* p);
void Stack_push(Stack* p, int v);
int Stack_pop(Stack* p);

#endif // __stack_h__
