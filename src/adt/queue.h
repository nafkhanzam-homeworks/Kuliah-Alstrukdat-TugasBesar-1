#if !defined(__queue_h__)
#define __queue_h__

#include "../headers.h"

typedef struct _Queue {
    List list;
} Queue;

Queue new_Queue();
/*I.S queue tidak terdefinisi
F.S queue baru terdefinisi*/
boolean Queue_isEmpty(Queue* p);
/*I.S queue terdefinisi
F.S kondisi boolean ketika queue kosong*/
int Queue_getLength(Queue* p);
/*I.S queue terdefinisi
F.s mendapatkan panjang queue*/
void Queue_add(Queue* p, int v);
/*I.S queue terdefinisi dan v terdefinisi
 F.S menambahkan elemen v ke queue */
int Queue_remove(Queue* p);
/*I.S queue terdefinisi
F.S menghapus queue atau dealokasi queue*/
int Queue_peek(Queue* p);
/*I.S queue terdefinisi
F.S melihat info queue*/
void Queue_clear(Queue* p);
/*I.S queue terdefinisi
F.S mengosongkan queue tp tidak di dealokasi*/
#endif // __queue_h__

