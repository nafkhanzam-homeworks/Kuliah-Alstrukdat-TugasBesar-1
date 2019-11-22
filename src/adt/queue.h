#if !defined(__queue_h__)
#define __queue_h__

#include "../headers.h"

typedef struct _Queue {
    List list;
} Queue;

Queue new_Queue();
boolean Queue_isEmpty(Queue* p);
int Queue_getLength(Queue* p);
void Queue_add(Queue* p, int v);
int Queue_remove(Queue* p);
int Queue_peek(Queue* p);

#endif // __queue_h__

