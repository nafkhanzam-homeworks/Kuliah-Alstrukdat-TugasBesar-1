#include "graph.h"

Graph new_Graph() {
    Graph res;
    list(&res) = NULL;
    return res;
}

void Graph_add1(Graph* p, int i, int j) {
    if (ListOfList_getLength(&list(p)) < i) {
        ListOfList_addLast(&list(p), new_List(j));
        return;
    }
    List* list = ListOfList_getAt(&list(p), i);
    List_addFirst(list, j);
}

void Graph_add2(Graph* p, int i, int j) {
    Graph_add1(p, i, j);
    Graph_add1(p, j, i);
}

