#if !defined(__queue_h__)
#define __queue_h__

#include "boolean.h"

typedef struct {
    int* arr;
    int max, head, tail;
} Queue;

#define ArrQueue(Q) (Q).arr
#define Max(Q) (Q).max
#define Head(Q) (Q).head
#define Tail(Q) (Q).tail
#define InfoHead(Q) (Q).arr[(Q).head]
#define InfoTail(Q) (Q).arr[(Q).tail]


void NewQueue (Queue * Q, int max);
boolean IsEmpty (Queue Q);
boolean Queue_isEmpty(Queue* Q);
int Queue_getLength(Queue Q);
void Queue_add(Queue* p, int v);
int Queue_remove(Queue* p);


#endif // __queue_h__

