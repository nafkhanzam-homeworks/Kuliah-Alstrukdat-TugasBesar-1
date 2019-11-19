#include "list.h"

#include <stdlib.h>

List new_List() {
    return NULL;
}

boolean List_isEmpty(List* p) {
    return *p == NULL;
}

List List_getLast(List* p) {
    if (List_isEmpty(p)) {
        return *p;
    }
    List list = *p;
    while (!List_isEmpty(&List_getNext(&list))) {
        list = List_getNext(&list);
    }
    return list;
}

void List_add(List* p, int v) {
    if (List_isEmpty(p)) {
        *p = new_List();
        List_add(p, v);
    }
}
