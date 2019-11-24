#if !defined(__stack_test_h__)
#define __stack_test_h__

#include "test.h"
#include "list_test.h"

void StackTest_do() { 
    Stack st = new_Stack();
    char res[512];
    List_toString(&list(&st), res);
    asserts("Init stack equals", "[]", res);

    Stack_push(&st, 17);
    Stack_push(&st, 25);
    Stack_push(&st, -1);
    List_toString(&list(&st), res);
    asserts("Added values", "[-1,25,17]", res);

    int removedValue = Stack_pop(&st);
    assert("Removed Value is -1", removedValue == -1);
    List_toString(&list(&st), res);
    asserts("Removed values equals", "[25,17]", res);
}

#endif // __stack_test_h__