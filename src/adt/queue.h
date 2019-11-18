#if !defined(__queue_h__)
#define __queue_h__

#include "boolean.h"

typedef struct {
    int* arr;
    int head, tail;
} Queue;

Queue new_Queue();
boolean Queue_isEmpty(Queue* p);
int Queue_getLength(Queue* p);
void Queue_add(Queue* p, int v);
int Queue_remove(Queue* p);

#endif // __queue_h__
