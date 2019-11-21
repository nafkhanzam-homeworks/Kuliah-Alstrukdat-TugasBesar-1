#if !defined(__array_h__)
#define __array_h__

#include "../building.h"
#include "list.h"

typedef struct {
    int length;
    int *tab;
} Array;

#define Array_length(P) (P)->length
#define Array_tab(P) (P)->tab
#define Array_get(P, i) (P)->tab[i]

Array new_Array(int length);

typedef struct {
    int length;
    List *tab;
} ArrayOfList;

ArrayOfList new_ArrayOfList(int length);

typedef struct {
    int length;
    Building* tab;
} ArrayOfBuilding;

ArrayOfBuilding new_ArrayOfBuilding(int length);

#endif // __array_h__
