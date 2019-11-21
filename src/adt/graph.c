#include "graph.h"

#include <stdlib.h>

Graph new_Graph(int length) {
    Graph res;
    res.length = length;
    res.arr = new_ArrayOfList(length);
    return res;
}

void Graph_add1(Graph* p, int i, int j) {
    List_addLast(&p->arr.tab[i], j);
}

void Graph_add2(Graph* p, int i, int j) {
    Graph_add1(p, i, j);
    Graph_add1(p, j, i);
}

