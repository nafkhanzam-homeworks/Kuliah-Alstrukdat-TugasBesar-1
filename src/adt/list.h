#if !defined(__list_h__)
#define __list_h__

#include "boolean.h"
#include "../act.h"

typedef struct _List* List;
typedef struct _List {
    int info;
    List next;
} ElementOfList;

List new_List(int v);
boolean List_isEmpty(List* p);
List List_getLast(List* p);
void List_addFirst(List* p, int v);
void List_addLast(List* p, int v);
int List_getLength(List* p);
List List_getSecondLast(List* p);
int List_removeFirst(List* p);
int List_removeLast(List* p);

typedef struct _ListOfOps* ListOfOps;
typedef struct _ListOfOps {
    Ops info;
    ListOfOps next;
} ElementOfListOfOps;

ListOfOps new_ListOfOps(Ops v);
boolean ListOfOps_isEmpty(ListOfOps* p);
ListOfOps ListOfOps_getLast(ListOfOps* p);
void ListOfOps_addFirst(ListOfOps* p, Ops v);
void ListOfOps_addLast(ListOfOps* p, Ops v);
int ListOfOps_getLength(ListOfOps* p);
ListOfOps ListOfOps_getSecondLast(ListOfOps* p);
Ops ListOfOps_removeFirst(ListOfOps* p);
Ops ListOfOps_removeLast(ListOfOps* p);

typedef struct _ListOfAct* ListOfAct;
typedef struct _ListOfAct {
    Act info;
    ListOfAct next;
} ElementOfListOfAct;

ListOfAct new_ListOfAct(Act v);
boolean ListOfAct_isEmpty(ListOfAct* p);
ListOfAct ListOfAct_getLast(ListOfAct* p);
void ListOfAct_addFirst(ListOfAct* p, Act v);
void ListOfAct_addLast(ListOfAct* p, Act v);
int ListOfAct_getLength(ListOfAct* p);
ListOfAct ListOfAct_getSecondLast(ListOfAct* p);
Act ListOfAct_removeFirst(ListOfAct* p);
Act ListOfAct_removeLast(ListOfAct* p);

#endif // __list_h__
