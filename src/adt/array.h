#if !defined(__array_h__)
#define __array_h__

#include "../building.h"

typedef struct {
    int length;
    int *arr;
} Array;

Array new_Array(int len);
void Array_set(Array* p, int i, int v);
int Array_get(Array* p, int i);

typedef struct {
    int length;
    Building* arr;
} ArrayOfBuilding;

ArrayOfBuilding new_ArrayOfBuilding(int len);
void ArrayOfBuilding_set(ArrayOfBuilding* p, int i, int v);
int ArrayOfBuilding_get(ArrayOfBuilding* p, int i);

#endif // __array_h__
