#include "graph.h"

#include <stdlib.h>

Graph new_Graph(int length) {
    Graph res;
    res.length = length;
    res.arr = (List*) malloc(length*sizeof(List));
    return res;
}

void Graph_add1(Graph* p, int i, int j) {
    List_add(&Graph_getAdjencyList(p, i), j);
}

void Graph_add2(Graph* p, int i, int j) {
    Graph_add1(p, i, j);
    Graph_add1(p, j, i);
}

