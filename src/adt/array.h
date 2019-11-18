#if !defined(__array_h__)
#define __array_h__

#include "../building.h"

typedef struct {
    int length;
    int *arr;
} Array;

Array new_Array(int len);

typedef struct {
    int length;
    Building* arr;
} ArrayOfBuilding;

ArrayOfBuilding new_ArrayOfBuilding(int length);

#endif // __array_h__
