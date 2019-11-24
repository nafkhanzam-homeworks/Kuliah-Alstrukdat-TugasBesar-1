#include "queue.h"

Queue new_Queue() {
	/* KAMUS LOKAL */
    Queue res;

    /* ALGORITMA */
    list(&res) = NULL;
    return res;
}

boolean Queue_isEmpty(Queue* p) {
    /* ALGORITMA */
    return List_isEmpty(&list(p));
}

int Queue_getLength(Queue* p) {
    /* ALGORITMA */
    return List_getLength(&list(p));
}

void Queue_add(Queue* p, int v) {
    /* ALGORITMA */
    List_addLast(&list(p), v);
}

int Queue_remove(Queue* p) {
    /* ALGORITMA */
    return List_removeFirst(&list(p));
}

int Queue_peek(Queue* p) {
    /* ALGORITMA */
    return info(list(p));
}
