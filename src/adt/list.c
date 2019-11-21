#include "list.h"

#include <stdlib.h>

List new_List(int v) {
    List res = (List) malloc(sizeof(ElementOfList));
    res->info = v;
    res->next = NULL;
    return res;
}

boolean List_isEmpty(List* p) {
    return *p == NULL;
}

List List_getLast(List* p) {
    if (List_isEmpty(p)) {
        return NULL;
    } else if (List_isEmpty(&(*p)->next)) {
        return *p;
    }
    return List_getLast(&(*p)->next);
}

void List_addFirst(List* p, int v) {
    List res = new_List(v);
    res->next = *p;
    *p = res;
}

void List_addLast(List* p, int v) {
    if (List_isEmpty(p)) {
        *p = new_List(v);
        return;
    } else if (List_isEmpty(&(*p)->next)) {
        List list = new_List(v);
        (*p)->next = list;
        return;
    }
    List_addLast(&(*p)->next, v);
}

int List_getLength(List* p) {
    if (List_isEmpty(p)) {
        return 0;
    }
    return 1 + List_getLength(&(*p)->next);
}

List List_getSecondLast(List* p) {
    if (List_isEmpty(p) || List_isEmpty(&(*p)->next)) {
        return NULL;
    } else if (List_isEmpty(&(*p)->next->next)) {
        return *p;
    }
    return List_getLast(&(*p)->next);
}

int List_removeFirst(List* p) {
    if (List_isEmpty(p)) {
        return *(int*)NULL;
    }
    int res = (*p)->info;
    *p = (*p)->next;
    return res;
}

int List_removeLast(List* p) {
    if (List_isEmpty(p)) {
        return *(int*)NULL;
    }
    List secondLast = List_getSecondLast(p);
    if (List_isEmpty(&secondLast)) {
        int res = (*p)->info;
        *p = NULL;
        return res;
    }
    int res = (*p)->next->info;
    (*p)->next = NULL;
    return res;
}

ListOfOps new_ListOfOps(Ops v) {
    ListOfOps res = (ListOfOps) malloc(sizeof(ElementOfListOfOps));
    res->info = v;
    res->next = NULL;
    return res;
}

boolean ListOfOps_isEmpty(ListOfOps* p) {
    return *p == NULL;
}

ListOfOps ListOfOps_getLast(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return NULL;
    } else if (ListOfOps_isEmpty(&(*p)->next)) {
        return *p;
    }
    return ListOfOps_getLast(&(*p)->next);
}

void ListOfOps_addFirst(ListOfOps* p, Ops v) {
    ListOfOps res = new_ListOfOps(v);
    res->next = *p;
    *p = res;
}

void ListOfOps_addLast(ListOfOps* p, Ops v) {
    if (ListOfOps_isEmpty(p)) {
        *p = new_ListOfOps(v);
        return;
    } else if (ListOfOps_isEmpty(&(*p)->next)) {
        ListOfOps ListOfOps = new_ListOfOps(v);
        (*p)->next = ListOfOps;
        return;
    }
    ListOfOps_addLast(&(*p)->next, v);
}

int ListOfOps_getLength(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfOps_getLength(&(*p)->next);
}

ListOfOps ListOfOps_getSecondLast(ListOfOps* p) {
    if (ListOfOps_isEmpty(p) || ListOfOps_isEmpty(&(*p)->next)) {
        return NULL;
    } else if (ListOfOps_isEmpty(&(*p)->next->next)) {
        return *p;
    }
    return ListOfOps_getLast(&(*p)->next);
}

Ops ListOfOps_removeFirst(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return *(Ops*)NULL;
    }
    Ops res = (*p)->info;
    *p = (*p)->next;
    return res;
}

Ops ListOfOps_removeLast(ListOfOps* p) {
    if (ListOfOps_isEmpty(p)) {
        return *(Ops*)NULL;
    }
    ListOfOps secondLast = ListOfOps_getSecondLast(p);
    if (ListOfOps_isEmpty(&secondLast)) {
        Ops res = (*p)->info;
        *p = NULL;
        return res;
    }
    Ops res = (*p)->next->info;
    (*p)->next = NULL;
    return res;
}

ListOfAct new_ListOfAct(Act v) {
    ListOfAct res = (ListOfAct) malloc(sizeof(ElementOfListOfAct));
    res->info = v;
    res->next = NULL;
    return res;
}

boolean ListOfAct_isEmpty(ListOfAct* p) {
    return *p == NULL;
}

ListOfAct ListOfAct_getLast(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return NULL;
    } else if (ListOfAct_isEmpty(&(*p)->next)) {
        return *p;
    }
    return ListOfAct_getLast(&(*p)->next);
}

void ListOfAct_addFirst(ListOfAct* p, Act v) {
    ListOfAct res = new_ListOfAct(v);
    res->next = *p;
    *p = res;
}

void ListOfAct_addLast(ListOfAct* p, Act v) {
    if (ListOfAct_isEmpty(p)) {
        *p = new_ListOfAct(v);
        return;
    } else if (ListOfAct_isEmpty(&(*p)->next)) {
        ListOfAct ListOfAct = new_ListOfAct(v);
        (*p)->next = ListOfAct;
        return;
    }
    ListOfAct_addLast(&(*p)->next, v);
}

int ListOfAct_getLength(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return 0;
    }
    return 1 + ListOfAct_getLength(&(*p)->next);
}

ListOfAct ListOfAct_getSecondLast(ListOfAct* p) {
    if (ListOfAct_isEmpty(p) || ListOfAct_isEmpty(&(*p)->next)) {
        return NULL;
    } else if (ListOfAct_isEmpty(&(*p)->next->next)) {
        return *p;
    }
    return ListOfAct_getLast(&(*p)->next);
}

Act ListOfAct_removeFirst(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return *(Act*)NULL;
    }
    Act res = (*p)->info;
    *p = (*p)->next;
    return res;
}

Act ListOfAct_removeLast(ListOfAct* p) {
    if (ListOfAct_isEmpty(p)) {
        return *(Act*)NULL;
    }
    ListOfAct secondLast = ListOfAct_getSecondLast(p);
    if (ListOfAct_isEmpty(&secondLast)) {
        Act res = (*p)->info;
        *p = NULL;
        return res;
    }
    Act res = (*p)->next->info;
    (*p)->next = NULL;
    return res;
}