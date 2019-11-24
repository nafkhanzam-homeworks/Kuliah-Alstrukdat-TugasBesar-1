#include "list.h"

List new_List(int v) {
    List res = (List) malloc(sizeof(ElementOfList));
    info(res) = v;
    next(res) = NULL;
    return res;
}

boolean List_isEmpty(List* p) {
    return *p == NULL;
}

List List_getLast(List* p) {
    if (List_isEmpty(p)) {
        return NULL;
    } else if (List_isEmpty(&next(*p))) {
        return *p;
    }
    return List_getLast(&next(*p));
}

void List_addFirst(List* p, int v) {
    if (List_isEmpty(p)) {
        *p = new_List(v);
        return;
    }
    List res = new_List(v);
    next(res) = *p;
    *p = res;
}

void List_addLast(List* p, int v) {
    if (List_isEmpty(p)) {
        *p = new_List(v);
        return;
    } else if (List_isEmpty(&next(*p))) {
        List list = new_List(v);
        next(*p) = list;
        return;
    }
    List_addLast(&next(*p), v);
}

int List_getLength(List* p) {
    if (List_isEmpty(p)) {
        return 0;
    }
    return 1 + List_getLength(&next(*p));
}

List List_getSecondLast(List* p) {
    if (List_isEmpty(p) || List_isEmpty(&next(*p))) {
        return NULL;
    } else if (List_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return List_getLast(&next(*p));
}

int List_removeFirst(List* p) {
    if (List_isEmpty(p)) {
        return *(int*)NULL;
    }
    int res = info(*p);
    *p = next(*p);
    return res;
}

int List_removeLast(List* p) {
    if (List_isEmpty(p)) {
        return *(int*)NULL;
    }
    List secondLast = List_getSecondLast(p);
    if (List_isEmpty(&secondLast)) {
        int res = info(*p);
        *p = NULL;
        return res;
    }
    int res = info(next(*p));
    next(*p) = NULL;
    return res;
}

int List_remove(List* p, int i) {
    if (List_isEmpty(p)) {
        return i;
    }
    if (info(*p) == i) {
        *p = next(*p);
        return i;
    }
    return List_remove(&next(*p), i);
}

int List_getAt(List* p, int i) {
    if (i != 1) {
        return List_getAt(&next(*p), i-1);
    }
    return info(*p);
}

boolean List_contains(List* p, int i) {
    if (List_isEmpty(p)) {
        return false;
    }
    if (info(*p) == i) {
        return true;
    }
    return List_contains(&next(*p), i);
}

ListOfList new_ListOfList(List v) {
    ListOfList res = (ListOfList) malloc(sizeof(ElementOfListOfList));
    info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfList_isEmpty(ListOfList* p) {
    return *p == NULL;
}

ListOfList ListOfList_getLast(ListOfList* p) {
    if (ListOfList_isEmpty(p)) {
        return NULL;
    } else if (ListOfList_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfList_getLast(&next(*p));
}

void ListOfList_addFirst(ListOfList* p, List v) {
    if (ListOfList_isEmpty(p)) {
        *p = new_ListOfList(v);
        return;
    }
    ListOfList res = new_ListOfList(v);
    next(res) = *p;
    *p = res;
}

void ListOfList_addLast(ListOfList* p, List v) {
    if (ListOfList_isEmpty(p)) {
        *p = new_ListOfList(v);
        return;
    } else if (ListOfList_isEmpty(&next(*p))) {
        ListOfList ListOfList = new_ListOfList(v);
        next(*p) = ListOfList;
        return;
    }
    ListOfList_addLast(&next(*p), v);
}

int ListOfList_getLength(ListOfList* p) {
    if (ListOfList_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfList_getLength(&next(*p));
}

ListOfList ListOfList_getSecondLast(ListOfList* p) {
    if (ListOfList_isEmpty(p) || ListOfList_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfList_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfList_getLast(&next(*p));
}

List ListOfList_removeFirst(ListOfList* p) {
    if (ListOfList_isEmpty(p)) {
        return NULL;
    }
    List res = info(*p);
    *p = next(*p);
    return res;
}

List ListOfList_removeLast(ListOfList* p) {
    if (ListOfList_isEmpty(p)) {
        return NULL;
    }
    ListOfList secondLast = ListOfList_getSecondLast(p);
    if (ListOfList_isEmpty(&secondLast)) {
        List res = info(*p);
        *p = NULL;
        return res;
    }
    List res = info(next(*p));
    next(*p) = NULL;
    return res;
}

List* ListOfList_getAt(ListOfList* p, int i) {
    if (p == NULL) {
        return NULL;
    }
    if (i != 1) {
        return ListOfList_getAt(&next(*p), i-1);
    }
    return &info(*p);
}

ListOfOps new_ListOfOps(Ops v) {
    ListOfOps res = (ListOfOps) malloc(sizeof(ElementOfListOfOps));
    info(res) = (Ops*) malloc(sizeof(Ops));
    *info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfOps_isEmpty(ListOfOps* p) {
    return *p == NULL;
}

ListOfOps ListOfOps_getLast(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return NULL;
    } else if (ListOfOps_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfOps_getLast(&next(*p));
}

void ListOfOps_addFirst(ListOfOps* p, Ops v) {
    if (ListOfOps_isEmpty(p)) {
        *p = new_ListOfOps(v);
        return;
    }
    ListOfOps res = new_ListOfOps(v);
    next(res) = *p;
    *p = res;
}

void ListOfOps_addLast(ListOfOps* p, Ops v) {
    if (ListOfOps_isEmpty(p)) {
        *p = new_ListOfOps(v);
        return;
    } else if (ListOfOps_isEmpty(&next(*p))) {
        ListOfOps ListOfOps = new_ListOfOps(v);
        next(*p) = ListOfOps;
        return;
    }
    ListOfOps_addLast(&next(*p), v);
}

int ListOfOps_getLength(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfOps_getLength(&next(*p));
}

ListOfOps ListOfOps_getSecondLast(ListOfOps* p) {
    if (ListOfOps_isEmpty(p) || ListOfOps_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfOps_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfOps_getLast(&next(*p));
}

Ops ListOfOps_removeFirst(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return *(Ops*)NULL;
    }
    Ops* res = info(*p);
    *p = next(*p);
    return *res;
}

Ops ListOfOps_removeLast(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return *(Ops*)NULL;
    }
    ListOfOps secondLast = ListOfOps_getSecondLast(p);
    if (ListOfOps_isEmpty(&secondLast)) {
        Ops* res = info(*p);
        *p = NULL;
        return *res;
    }
    Ops* res = info(next(*p));
    next(*p) = NULL;
    return *res;
}

ListOfAct new_ListOfAct(Act v) {
    ListOfAct res = (ListOfAct) malloc(sizeof(ElementOfListOfAct));
    info(res) = (Act*) malloc(sizeof(Act));
    *info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfAct_isEmpty(ListOfAct* p) {
    return *p == NULL;
}

ListOfAct ListOfAct_getLast(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return NULL;
    } else if (ListOfAct_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfAct_getLast(&next(*p));
}

void ListOfAct_addFirst(ListOfAct* p, Act v) {
    if (ListOfAct_isEmpty(p)) {
        *p = new_ListOfAct(v);
        return;
    }
    ListOfAct res = new_ListOfAct(v);
    next(res) = *p;
    *p = res;
}

void ListOfAct_addLast(ListOfAct* p, Act v) {
    if (ListOfAct_isEmpty(p)) {
        *p = new_ListOfAct(v);
        return;
    } else if (ListOfAct_isEmpty(&next(*p))) {
        ListOfAct ListOfAct = new_ListOfAct(v);
        next(*p) = ListOfAct;
        return;
    }
    ListOfAct_addLast(&next(*p), v);
}

int ListOfAct_getLength(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfAct_getLength(&next(*p));
}

ListOfAct ListOfAct_getSecondLast(ListOfAct* p) {
    if (ListOfAct_isEmpty(p) || ListOfAct_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfAct_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfAct_getLast(&next(*p));
}

Act ListOfAct_removeFirst(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return *(Act*)NULL;
    }
    Act* res = info(*p);
    *p = next(*p);
    return *res;
}

Act ListOfAct_removeLast(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return *(Act*)NULL;
    }
    ListOfAct secondLast = ListOfAct_getSecondLast(p);
    if (ListOfAct_isEmpty(&secondLast)) {
        Act* res = info(*p);
        *p = NULL;
        return *res;
    }
    Act* res = info(next(*p));
    next(*p) = NULL;
    return *res;
}

ListOfBuilding new_ListOfBuilding(Building v) {
    ListOfBuilding res = (ListOfBuilding) malloc(sizeof(ElementOfListOfBuilding));
    info(res) = (Building*) malloc(sizeof(Building));
    *info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfBuilding_isEmpty(ListOfBuilding* p) {
    return *p == NULL;
}

ListOfBuilding ListOfBuilding_getLast(ListOfBuilding* p) {
    if (ListOfBuilding_isEmpty(p)) {
        return NULL;
    } else if (ListOfBuilding_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfBuilding_getLast(&next(*p));
}

void ListOfBuilding_addFirst(ListOfBuilding* p, Building v) {
    if (ListOfBuilding_isEmpty(p)) {
        *p = new_ListOfBuilding(v);
        return;
    }
    ListOfBuilding res = new_ListOfBuilding(v);
    next(res) = *p;
    *p = res;
}

void ListOfBuilding_addLast(ListOfBuilding* p, Building v) {
    if (ListOfBuilding_isEmpty(p)) {
        *p = new_ListOfBuilding(v);
        return;
    } else if (ListOfBuilding_isEmpty(&next(*p))) {
        ListOfBuilding ListOfBuilding = new_ListOfBuilding(v);
        next(*p) = ListOfBuilding;
        return;
    }
    ListOfBuilding_addLast(&next(*p), v);
}

int ListOfBuilding_getLength(ListOfBuilding* p) {
    if (ListOfBuilding_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfBuilding_getLength(&next(*p));
}

ListOfBuilding ListOfBuilding_getSecondLast(ListOfBuilding* p) {
    if (ListOfBuilding_isEmpty(p) || ListOfBuilding_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfBuilding_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfBuilding_getLast(&next(*p));
}

Building ListOfBuilding_removeFirst(ListOfBuilding* p) {
    if (ListOfBuilding_isEmpty(p)) {
        return *(Building*)NULL;
    }
    Building* res = info(*p);
    *p = next(*p);
    return *res;
}

Building ListOfBuilding_removeLast(ListOfBuilding* p) {
    if (ListOfBuilding_isEmpty(p)) {
        return *(Building*)NULL;
    }
    ListOfBuilding secondLast = ListOfBuilding_getSecondLast(p);
    if (ListOfBuilding_isEmpty(&secondLast)) {
        Building* res = info(*p);
        *p = NULL;
        return *res;
    }
    Building* res = info(next(*p));
    next(*p) = NULL;
    return *res;
}

Building* ListOfBuilding_getAt(ListOfBuilding* p, int i) {
    if (i != 1) {
        return ListOfBuilding_getAt(&next(*p), i-1);
    }
    return info(*p);
}