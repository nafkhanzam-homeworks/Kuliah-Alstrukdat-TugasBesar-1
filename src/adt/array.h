#if !defined(__array_h__)
#define __array_h__

#include "../building.h"

typedef struct {
    int length;
    int *arr;
} Array;

#define Length(B) (B)->length
#define Arr(B) (B)->arr
#define Get(B, i) (B)->arr[i]


Array new_Array(int len);
int Array_getLength(Array* p);

typedef struct {
    int length;
    Building* arr;
} ArrayOfBuilding;

ArrayOfBuilding new_ArrayOfBuilding(int length);

int ArrayOfBuilding_getLength(ArrayOfBuilding* p);

#endif // __array_h__
