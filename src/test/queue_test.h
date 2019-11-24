#if !defined(__queue_test_h__)
#define __queue_test_h__

#include "test.h"
#include "list_test.h"

void QueueTest_do() {
    Queue q = new_Queue();
    char res[512];
    List_toString(&list(&q), res);
    asserts("Init queue equals", "[]", res);

    Queue_add(&q, 17);
    Queue_add(&q, 25);
    Queue_add(&q, -1);
    List_toString(&list(&q), res);
    asserts("Added values", "[17,25,-1]", res);

    int removedValue = Queue_remove(&q);
    assert("Removed Value is 17", removedValue == 17);
    List_toString(&list(&q), res);
    asserts("Removed values equals", "[25,-1]", res);
}

#endif // __queue_test_h__
