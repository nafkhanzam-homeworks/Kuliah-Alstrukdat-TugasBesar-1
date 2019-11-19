#if !defined(__stack_h__)
#define __stack_h__

#include "boolean.h"
#include "../act.h"

typedef struct {
    Act* arr;
    int top;
} StackOfAct;

#define Stack_arr(S) (S).arr
#define Stack_top(S) (S).top
#define Stack_getTop(S) (S).arr[(S).top]

StackOfAct new_StackOfAct();
boolean StackOfAct_isEmpty(StackOfAct* S);
void StackOfAct_clear(StackOfAct* S);
void StackOfAct_push(StackOfAct* S, Act v);
Act StackOfAct_pop(StackOfAct* S, Act* X);

#endif // __stack_h__
