#if !defined(__list_h__)
#define __list_h__

#include "../headers.h"

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
int List_remove(List* p, int i);
int List_getAt(List* p, int i);
boolean List_contains(List* p, int i);

typedef struct _ListOfList {
    List info;
    ListOfList next;
} ElementOfListOfList;

ListOfList new_ListOfList(List v);
boolean ListOfList_isEmpty(ListOfList* p);
ListOfList ListOfList_getLast(ListOfList* p);
void ListOfList_addFirst(ListOfList* p, List v);
void ListOfList_addLast(ListOfList* p, List v);
int ListOfList_getLength(ListOfList* p);
ListOfList ListOfList_getSecondLast(ListOfList* p);
List ListOfList_removeFirst(ListOfList* p);
List ListOfList_removeLast(ListOfList* p);
List* ListOfList_getAt(ListOfList* p, int i);

typedef struct _ListOfOps {
    Ops* info;
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

typedef struct _ListOfAct {
    Act* info;
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

typedef struct _ListOfBuilding {
    Building* info;
    ListOfBuilding next;
} ElementOfListOfBuilding;

ListOfBuilding new_ListOfBuilding(Building v);
boolean ListOfBuilding_isEmpty(ListOfBuilding* p);
ListOfBuilding ListOfBuilding_getLast(ListOfBuilding* p);
void ListOfBuilding_addFirst(ListOfBuilding* p, Building v);
void ListOfBuilding_addLast(ListOfBuilding* p, Building v);
int ListOfBuilding_getLength(ListOfBuilding* p);
ListOfBuilding ListOfBuilding_getSecondLast(ListOfBuilding* p);
Building ListOfBuilding_removeFirst(ListOfBuilding* p);
Building ListOfBuilding_removeLast(ListOfBuilding* p);
Building* ListOfBuilding_getAt(ListOfBuilding* p, int i);

#endif // __list_h__
