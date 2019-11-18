#include "array.h"

#include <stdlib.h>

Array new_Array(int length) {
    Array res;
    res.length = length;
    res.arr = (int*) malloc(length*sizeof(int));
    return res;
}

ArrayOfBuilding new_ArrayOfBuilding(int length) {
    ArrayOfBuilding res;
    res.length = length;
    res.arr = (Building*) malloc(length*sizeof(Building));
    return res;
}
