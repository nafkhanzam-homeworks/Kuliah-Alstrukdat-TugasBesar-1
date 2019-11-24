#if !defined(__stack_h__)
#define __stack_h__

#include "../headers.h"

typedef struct _StackOfAct {
    ListOfAct list;
} StackOfAct;

typedef struct _Stack {
    List list;
} Stack;

/*stack didefinisikan sebagai stack dari aksi (implementasi sebagai aksi) */
StackOfAct new_StackOfAct();
/*I.S stack tidak terdefinisi
F.S  stack baru terdefinisi*/
boolean StackOfAct_isEmpty(StackOfAct* p);
/*I.S stack terdefinisi
F.S  return boolean apakah isi stack kosong*/
void StackOfAct_clear(StackOfAct* p);
/*I.S stack terdefinisni
F.S  stack kosong */
void StackOfAct_push(StackOfAct* p, Act v);
/*I.S stack terdefinisi dan juga v
F.S  menambahkan aksi v ke stack*/
Act StackOfAct_pop(StackOfAct* p);
/*I.S stack terdefinisi
F.S elemen top aksi di hapus dari stack*/

Stack new_Stack();
/*I.S stack biasa tidak terdefinisi
F.S  stack biasa terdefinisi*/
boolean Stack_isEmpty(Stack* p);
/*I.S stack biasa terdefinisi
F.S  return boolean apakah stack kosong*/
void Stack_clear(Stack* p);
/*I.S stack biasa terdefinisi
F.S  stack biasa akhir kosong*/
void Stack_push(Stack* p, int v);
/*I.S stack biasa terdefinisi dan integer v
F.S  stack biasa dengan elemen integer v di tambahkan*/
int Stack_pop(Stack* p);
/*I.S stack biasa terdefinisi
F.S  stack baru dengan elemen top yang lama di hapus*/

#endif // __stack_h__
