#include "graph.h"

Graph new_Graph(int length) {
    Graph res;
    res.arr = new_List();
    res.length = length;
    return res;
}

void Graph_add1(Graph* p, int i, int j) {
    List_add(&p->arr[i], j);
}

void Graph_add2(Graph* p, int i, int j) {
    Graph_add1(p, i, j);
    Graph_add1(p, j, i);
}
