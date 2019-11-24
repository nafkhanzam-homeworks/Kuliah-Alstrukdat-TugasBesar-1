#include "stack.h"

StackOfAct new_StackOfAct() {
	/* KAMUS LOKAL */
    StackOfAct res;

    /* ALGORITMA */
    list(&res) = NULL; // Membuat stack kosong (elemen pertama NULL)
    return res;
}

boolean StackOfAct_isEmpty(StackOfAct* p) {
    /* ALGORITMA */
    return ListOfAct_isEmpty(&list(p)); // Cek list kosong (Stack dibangun menggunakan list)
}

void StackOfAct_clear(StackOfAct* p) {
	/* ALGORITMA */
    list(p) = NULL;
}

void StackOfAct_push(StackOfAct* p, Act v) {
    /* ALGORITMA */
    ListOfAct_addFirst(&list(p), v);
}

Act StackOfAct_pop(StackOfAct* p) {
    /* ALGORITMA */
    return ListOfAct_removeFirst(&list(p));
}

Stack new_Stack() {
	/* KAMUS LOKAL */
    Stack res;

    /* ALGORITMA */
    list(&res) = NULL; // Membuat stack kosong (elemen pertama NULL)
    return res;
}

boolean Stack_isEmpty(Stack* p) {
    /* ALGORITMA */
    return List_isEmpty(&list(p)); 
}

void Stack_clear(Stack* p) {
	/* ALGORITMA */
    list(p) = NULL;
}

void Stack_push(Stack* p, int v) {
    /* ALGORITMA */
    List_addFirst(&list(p), v);
}

int Stack_pop(Stack* p) {
    /* ALGORITMA */
    return List_removeFirst(&list(p));
}