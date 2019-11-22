#include "graph.h"

#include <stdlib.h>
#include "list.h"
#include "array.h"

Graph new_Graph(int length) {
    Graph res;
    length(&res) = length;
    array(&res) = new_ArrayOfList(length);
    return res;
}

void Graph_add1(Graph* p, int i, int j) {
    List_addLast(&tabi(&array(p), i), j);
}

void Graph_add2(Graph* p, int i, int j) {
    Graph_add1(p, i, j);
    Graph_add1(p, j, i);
}

