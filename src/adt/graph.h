#if !defined(__graph_h__)
#define __graph_h__

#include "list.h"

typedef struct {
	int length;
	List* arr;
} Graph;

#define Graph_length(P) (P)->length
#define Graph_arr(P) (P)->arr
#define Graph_getAdjencyList(P, i) (P)->arr[i]

Graph new_Graph(int length);
void Graph_add1(Graph* p, int i, int j);
void Graph_add2(Graph* p, int i, int j);

#endif // __graph_h__
