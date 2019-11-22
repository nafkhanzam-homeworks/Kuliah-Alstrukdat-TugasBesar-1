#if !defined(__graph_h__)
#define __graph_h__

#include "../headers.h"

typedef struct _Graph {
	ListOfList list;
} Graph;

Graph new_Graph();
void Graph_add1(Graph* p, int i, int j);
void Graph_add2(Graph* p, int i, int j);

#endif // __graph_h__
