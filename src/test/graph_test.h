#if !defined(__graph_test_h__)
#define __graph_test_h__

#include "test.h"

void Graph_toString(Graph* p, char* res) {
    char str[128];
    ListOfList list = list(p);
    res[0] = 0;
    append(res, "[");
    int i = 1;
    while (list != NULL) {
        sprintf(str, "%d", i); append(res, str);
        List adjList = info(list);
        append(res, "(");
        while (adjList != NULL) {
            sprintf(str, "%d", info(adjList)); append(res, str);
            adjList = next(adjList);
            if (adjList != NULL) {
                append(res, ",");
            }
        }
        append(res, ")");
        list = next(list); ++i;
    }
    append(res, "]");
}

void GraphTest_do() {
    Graph graph = new_Graph();
    char res[512];

    Graph_toString(&graph, res);
    asserts("Init graph equals", "[]", res);

    Graph_add2(&graph, 4, 5);
    Graph_add1(&graph, 1, 5);
    Graph_add1(&graph, 4, 1);
    Graph_toString(&graph, res);
    asserts("Added edges to graph equals", "[1(5)2()3()4(1,5)5(4)]", res);
}

#endif // __graph_test_h__
