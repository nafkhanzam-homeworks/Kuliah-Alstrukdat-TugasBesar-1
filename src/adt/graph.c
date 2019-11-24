#include "graph.h"

Graph new_Graph() {
    /* KAMUS LOKAL */
    Graph res;

    /* ALGORITMA */
    list(&res) = NULL; // list of list
    return res;
}

void Graph_add1(Graph* p, int i, int j) {
    /* KAMUS LOKAL */
    int k = ListOfList_getLength(&list(p));

    /* ALGORITMA */
    while (k < i) {
        ListOfList_addLast(&list(p), NULL);
        ++k;
    }
    List_addFirst(ListOfList_getAt(&list(p), i), j);
}

void Graph_add2(Graph* p, int i, int j) {
    /* ALGORITMA */
    Graph_add1(p, i, j);
    Graph_add1(p, j, i);
}

