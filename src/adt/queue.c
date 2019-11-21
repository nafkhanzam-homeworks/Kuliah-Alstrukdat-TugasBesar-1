#include "queue.h"

#include <stdlib.h>

Queue new_Queue() {
    Queue res;
    res.list = NULL;
    return res;
}

boolean Queue_isEmpty(Queue* p) {
    return List_isEmpty(&p->list);
}

int Queue_getLength(Queue* p) {
    return List_getLength(&p->list);
}

void Queue_add(Queue* p, int v) {
    List_addLast(&p->list, v);
}

int Queue_remove(Queue* p) {
    return List_removeFirst(&p->list);
}
