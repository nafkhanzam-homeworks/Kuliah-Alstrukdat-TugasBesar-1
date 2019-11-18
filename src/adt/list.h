#if !defined(__list_h__)
#define __list_h__

#include "boolean.h"

typedef struct {
    int info;
    List* next;
} List;

List new_List();
boolean List_isEmpty(List* p);
List List_getLast(List* p);
void List_add(List* p, int v);

#endif // __list_h__
