#include "list.h"

List new_List(int v) {
    /* KAMUS LOKAL */
    List res;

    /* ALGORITMA */
    res = (List) malloc(sizeof(ElementOfList));
    info(res) = v;
    next(res) = NULL;
    return res;
}

boolean List_isEmpty(List* p) {
    /* ALGORITMA */
    return *p == NULL;
}

List List_getLast(List* p) {
    /* ALGORITMA */
    if (List_isEmpty(p)) { // basis list kosong
        return NULL;
    } else if (List_isEmpty(&next(*p))) { // basis list satu elemen
        return *p;
    }
    return List_getLast(&next(*p)); // rekursi
}

void List_addFirst(List* p, int v) {
    /* KAMUS LOKAL */
    List res;

    /* ALGORITMA */
    if (List_isEmpty(p)) { // kondisi list kosong
        *p = new_List(v);
        return;
    }
    res = new_List(v);
    next(res) = *p;
    *p = res;
}

void List_addLast(List* p, int v) {
    /* KAMUS LOKAL */
    List list;

    /* ALGORITMA */
    if (List_isEmpty(p)) { // kondisi list kosong
        *p = new_List(v);
        return;
    } else if (List_isEmpty(&next(*p))) { // basis list satu elemen
        list = new_List(v);
        next(*p) = list;
        return;
    }
    List_addLast(&next(*p), v); //rekursi
}

int List_getLength(List* p) {
    /* ALGORITMA */
    if (List_isEmpty(p)) { // basis list kosong
        return 0;
    }
    return 1 + List_getLength(&next(*p)); // rekursi
}

List List_getSecondLast(List* p) {
    /* ALGORITMA */
    if (List_isEmpty(p) || List_isEmpty(&next(*p))) { // kondisi list kosong
        return NULL;
    } else if (List_isEmpty(&next(next(*p)))) { // basis one elemen
        return *p;
    }
    return List_getLast(&next(*p)); // rekursi
}

int List_removeFirst(List* p) {
    /* KAMUS LOKAL */
    int res;

    /* ALGORITMA */
    if (List_isEmpty(p)) { // kosndisi list kosong
        return *(int*)NULL;
    }
    res = info(*p);
    *p = next(*p); // Mengganti First List
    return res;
}

int List_removeLast(List* p) {
    /* KAMUS LOKAL */
    int res;

    /* ALGORITMA */
    if (List_isEmpty(p)) {
        return *(int*)NULL;
    }
    List secondLast = List_getSecondLast(p);
    if (List_isEmpty(&secondLast)) {
        res = info(*p);
        *p = NULL;
        return res;
    }
    res = info(next(*p));
    next(*p) = NULL;
    return res;
}

int List_remove(List* p, int i) {
    /* ALGORITMA */
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
    /* ALGORITMA */
    if (i != 1) {
        return List_getAt(&next(*p), i-1);
    }
    return info(*p);
}

boolean List_contains(List* p, int i) {
    /* ALGORITMA */
    if (List_isEmpty(p)) {
        return false;
    }
    if (info(*p) == i) {
        return true;
    }
    return List_contains(&next(*p), i);
}

ListOfList new_ListOfList(List v) {
    /* KAMUS LOKAL */
    ListOfList res;

    /* ALGORITMA */
    res = (ListOfList) malloc(sizeof(ElementOfListOfList));
    info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfList_isEmpty(ListOfList* p) {
    /* ALGORITMA */
    return *p == NULL;
}

ListOfList ListOfList_getLast(ListOfList* p) {
    /* ALGORITMA */
    if (ListOfList_isEmpty(p)) {
        return NULL;
    } else if (ListOfList_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfList_getLast(&next(*p));
}

void ListOfList_addFirst(ListOfList* p, List v) {
    /* KAMUS LOKAL */
    ListOfList res;

    /* ALGORITMA */
    if (ListOfList_isEmpty(p)) {
        *p = new_ListOfList(v);
        return;
    }
    res = new_ListOfList(v);
    next(res) = *p;
    *p = res;
}

void ListOfList_addLast(ListOfList* p, List v) {
    /* KAMUS LOKAL */
    ListOfList ListOfList;

    /* ALGORITMA */
    if (ListOfList_isEmpty(p)) {
        *p = new_ListOfList(v);
        return;
    } else if (ListOfList_isEmpty(&next(*p))) {
        ListOfList = new_ListOfList(v);
        next(*p) = ListOfList;
        return;
    }
    ListOfList_addLast(&next(*p), v);
}

int ListOfList_getLength(ListOfList* p) {
    /* ALGORITMA */
    if (ListOfList_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfList_getLength(&next(*p));
}

ListOfList ListOfList_getSecondLast(ListOfList* p) {
    /* ALGORITMA */
    if (ListOfList_isEmpty(p) || ListOfList_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfList_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfList_getLast(&next(*p));
}

List ListOfList_removeFirst(ListOfList* p) {
    /* KAMUS LOKAL */
    List res;

    /* ALGORITMA */
    if (ListOfList_isEmpty(p)) {
        return NULL;
    }
    res = info(*p);
    *p = next(*p);
    return res;
}

List ListOfList_removeLast(ListOfList* p) {
    /* KAMUS LOKAL */
    List res;

    /* ALGORITMA */
    if (ListOfList_isEmpty(p)) {
        return NULL;
    }
    ListOfList secondLast = ListOfList_getSecondLast(p);
    if (ListOfList_isEmpty(&secondLast)) {
        res = info(*p);
        *p = NULL;
        return res;
    }
    res = info(next(*p));
    next(*p) = NULL;
    return res;
}

List* ListOfList_getAt(ListOfList* p, int i) {
    /* ALGORITMA */
    if (p == NULL) {
        return NULL;
    }
    if (i != 1) {
        return ListOfList_getAt(&next(*p), i-1);
    }
    return &info(*p);
}

ListOfOps new_ListOfOps(Ops v) {
    /* KAMUS LOKAL */
    ListOfOps res;

    /* ALGORITMA */
    res = (ListOfOps) malloc(sizeof(ElementOfListOfOps));
    info(res) = (Ops*) malloc(sizeof(Ops));
    *info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfOps_isEmpty(ListOfOps* p) {
    /* ALGORITMA */
    return *p == NULL;
}

ListOfOps ListOfOps_getLast(ListOfOps* p) {
    /* ALGORITMA */
    if (ListOfOps_isEmpty(p)) {
        return NULL;
    } else if (ListOfOps_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfOps_getLast(&next(*p));
}

void ListOfOps_addFirst(ListOfOps* p, Ops v) {
    /* KAMUS LOKAL */
    ListOfOps res;

    /* ALGORITMA */
    if (ListOfOps_isEmpty(p)) {
        *p = new_ListOfOps(v);
        return;
    }
    res = new_ListOfOps(v);
    next(res) = *p;
    *p = res;
}

void ListOfOps_addLast(ListOfOps* p, Ops v) {
    /* KAMUS LOKAL */
    ListOfOps ListOfOps;

    /* ALGORITMA */
    if (ListOfOps_isEmpty(p)) {
        *p = new_ListOfOps(v);
        return;
    } else if (ListOfOps_isEmpty(&next(*p))) {
        ListOfOps = new_ListOfOps(v);
        next(*p) = ListOfOps;
        return;
    }
    ListOfOps_addLast(&next(*p), v);
}

int ListOfOps_getLength(ListOfOps* p) {
    /* ALGORITMA */
    if (ListOfOps_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfOps_getLength(&next(*p));
}

ListOfOps ListOfOps_getSecondLast(ListOfOps* p) {
    /* ALGORITMA */
    if (ListOfOps_isEmpty(p) || ListOfOps_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfOps_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfOps_getLast(&next(*p));
}

Ops ListOfOps_removeFirst(ListOfOps* p) {
    /* ALGORITMA */
    if (ListOfOps_isEmpty(p)) {
        return *(Ops*)NULL;
    }
    Ops* res = info(*p);
    *p = next(*p);
    return *res;
}

Ops ListOfOps_removeLast(ListOfOps* p) {
    /* ALGORITMA */
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
    /* KAMUS LOKAL */
    ListOfAct res;

    /* ALGORITMA */
    res = (ListOfAct) malloc(sizeof(ElementOfListOfAct));
    info(res) = (Act*) malloc(sizeof(Act));
    *info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfAct_isEmpty(ListOfAct* p) {
    /* ALGORITMA */
    return *p == NULL;
}

ListOfAct ListOfAct_getLast(ListOfAct* p) {
    /* ALGORITMA */
    if (ListOfAct_isEmpty(p)) {
        return NULL;
    } else if (ListOfAct_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfAct_getLast(&next(*p));
}

void ListOfAct_addFirst(ListOfAct* p, Act v) {
    /* KAMUS LOKAL */
    ListOfAct res;

    /* ALGORITMA */
    if (ListOfAct_isEmpty(p)) {
        *p = new_ListOfAct(v);
        return;
    }
    res = new_ListOfAct(v);
    next(res) = *p;
    *p = res;
}

void ListOfAct_addLast(ListOfAct* p, Act v) {
    /* KAMUS LOKAL */
    ListOfAct ListOfAct;

    /* ALGORITMA */
    if (ListOfAct_isEmpty(p)) {
        *p = new_ListOfAct(v);
        return;
    } else if (ListOfAct_isEmpty(&next(*p))) {
        ListOfAct = new_ListOfAct(v);
        next(*p) = ListOfAct;
        return;
    }
    ListOfAct_addLast(&next(*p), v);
}

int ListOfAct_getLength(ListOfAct* p) {
    /* ALGORITMA */
    if (ListOfAct_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfAct_getLength(&next(*p));
}

ListOfAct ListOfAct_getSecondLast(ListOfAct* p) {
    /* ALGORITMA */
    if (ListOfAct_isEmpty(p) || ListOfAct_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfAct_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfAct_getLast(&next(*p));
}

Act ListOfAct_removeFirst(ListOfAct* p) {
    /* ALGORITMA */
    if (ListOfAct_isEmpty(p)) {
        return *(Act*)NULL;
    }
    Act* res = info(*p);
    *p = next(*p);
    return *res;
}

Act ListOfAct_removeLast(ListOfAct* p) {
    /* ALGORITMA */
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
    /* KAMUS LOKAL */
    ListOfBuilding res;

    /* ALGORITMA */
    res = (ListOfBuilding) malloc(sizeof(ElementOfListOfBuilding));
    info(res) = (Building*) malloc(sizeof(Building));
    *info(res) = v;
    next(res) = NULL;
    return res;
}

boolean ListOfBuilding_isEmpty(ListOfBuilding* p) {
    /* ALGORITMA */
    return *p == NULL;
}

ListOfBuilding ListOfBuilding_getLast(ListOfBuilding* p) {
    /* ALGORITMA */
    if (ListOfBuilding_isEmpty(p)) {
        return NULL;
    } else if (ListOfBuilding_isEmpty(&next(*p))) {
        return *p;
    }
    return ListOfBuilding_getLast(&next(*p));
}

void ListOfBuilding_addFirst(ListOfBuilding* p, Building v) {
    /* KAMUS LOKAL */
    ListOfBuilding res;

    /* ALGORITMA */
    if (ListOfBuilding_isEmpty(p)) {
        *p = new_ListOfBuilding(v);
        return;
    }
    res = new_ListOfBuilding(v);
    next(res) = *p;
    *p = res;
}

void ListOfBuilding_addLast(ListOfBuilding* p, Building v) {
    /* KAMUS LOKAL */
    ListOfBuilding ListOfBuilding;

    /* ALGORITMA */
    if (ListOfBuilding_isEmpty(p)) {
        *p = new_ListOfBuilding(v);
        return;
    } else if (ListOfBuilding_isEmpty(&next(*p))) {
        ListOfBuilding = new_ListOfBuilding(v);
        next(*p) = ListOfBuilding;
        return;
    }
    ListOfBuilding_addLast(&next(*p), v);
}

int ListOfBuilding_getLength(ListOfBuilding* p) {
    /* ALGORITMA */
    if (ListOfBuilding_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfBuilding_getLength(&next(*p));
}

ListOfBuilding ListOfBuilding_getSecondLast(ListOfBuilding* p) {
    /* ALGORITMA */
    if (ListOfBuilding_isEmpty(p) || ListOfBuilding_isEmpty(&next(*p))) {
        return NULL;
    } else if (ListOfBuilding_isEmpty(&next(next(*p)))) {
        return *p;
    }
    return ListOfBuilding_getLast(&next(*p));
}

Building ListOfBuilding_removeFirst(ListOfBuilding* p) {
    /* ALGORITMA */
    if (ListOfBuilding_isEmpty(p)) {
        return *(Building*)NULL;
    }
    Building* res = info(*p);
    *p = next(*p);
    return *res;
}

Building ListOfBuilding_removeLast(ListOfBuilding* p) {
    /* KAMUS LOKAL */
    ListOfBuilding secondLast;

    /* ALGORITMA */
    if (ListOfBuilding_isEmpty(p)) {
        return *(Building*)NULL;
    }
    secondLast = ListOfBuilding_getSecondLast(p);
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
    /* ALGORITMA */
    if (i != 1) {
        return ListOfBuilding_getAt(&next(*p), i-1);
    }
    return info(*p);
}