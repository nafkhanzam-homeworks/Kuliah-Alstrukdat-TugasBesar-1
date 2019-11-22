#include "queue.h"

#include <stdlib.h>

Queue new_Queue() {
    Queue res;
    list(&res) = NULL;
    return res;
}

boolean Queue_isEmpty(Queue* p) {
    return List_isEmpty(&list(p));
}

int Queue_getLength(Queue* p) {
    return List_getLength(&list(p));
}

void Queue_add(Queue* p, int v) {
    List_addLast(&list(p), v);
}

int Queue_remove(Queue* p) {
    return List_removeFirst(&list(p));
}

int Queue_peek(Queue* p) {
    return info(list(p));
}
