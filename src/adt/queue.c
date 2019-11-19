#include "queue.h"

#include <stdlib.h>

void NewQueue (Queue * Q, int Max){
	ArrQueue(*Q) = (int *) malloc ((Max+1) * sizeof(int));
    Max(*Q) = Max;
	if(ArrQueue(*Q) != NULL) {
		Head(*Q) = 0;
		Tail(*Q) = 0;
	}
}

boolean IsEmpty (Queue Q) {
	return (Head(Q) == 0 && Tail(Q) == 0);
}

void MakeEmptyQueue(Queue* Q) {
    Head(*Q) = 0;
    Tail(*Q) = 0;
}

int Queue_getLength(Queue Q) {
    if (IsEmpty(Q)){
        return 0;
    }else if (Head(Q) > Tail(Q))
    {
        return (Max(Q) - Head(Q) + Tail(Q) + 1);
    }else
    {
        return (Tail(Q) - Head(Q) + 1);
    }
}

void Queue_add(Queue* Q, int v) {
    if (IsEmpty(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = v;
    }else if (Tail(*Q) == Max(*Q)){
        Tail(*Q) = 1;
        InfoTail(*Q) = v;

    }else
    {
        Tail(*Q) += 1;
        InfoTail(*Q) = v;
    }
    
}

int Queue_remove(Queue* Q) {
    int X;
    if (Head(*Q) == Tail(*Q))
    {
        X = InfoHead(*Q);
        Head(*Q) = 0;
        Tail(*Q) = 0;
        
    }else if(Head(*Q) == Max(*Q)){
        X = InfoHead(*Q);
        Head(*Q) = 1;
    }else
    {
        X = InfoHead(*Q);
        Head(*Q) += 1;
    }
    return X;
}