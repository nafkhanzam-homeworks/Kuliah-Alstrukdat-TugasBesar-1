#if !defined(__graph_h__)
#define __graph_h__

#include "../headers.h"

typedef struct _Graph {
	ListOfList list;
} Graph;

Graph new_Graph();
/*I.S Defisini graph belum terdifinisi 
  F.S Graph terdefinisi
*/
void Graph_add1(Graph* p, int i, int j);
/*I.S Graph sudah ada, elemen terdefinisi
F.S graph baru dengan edge baru i dan j */
void Graph_add2(Graph* p, int i, int j);
/*I.S Graph sudah ada, elemen terdefinisi
F.S graph baru dengan edge baru dengan node i dan j dan sebalik nya dari j ke i*/

#endif // __graph_h__
