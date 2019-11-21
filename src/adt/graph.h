#if !defined(__graph_h__)
#define __graph_h__

#include "array.h"

typedef struct {
	int length;
	ArrayOfList arr;
} Graph;

Graph new_Graph(int length);
void Graph_add1(Graph* p, int i, int j);
void Graph_add2(Graph* p, int i, int j);

#endif // __graph_h__
