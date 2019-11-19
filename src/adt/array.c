#include "array.h"

#include <stdlib.h>

Array new_Array(int length) {
    Array res;
    Length(&res) = length;
    Arr(&res) = (int*) malloc(length*sizeof(int));
    return res;
}

ArrayOfBuilding new_ArrayOfBuilding(int length) {
    ArrayOfBuilding res;
    Length(&res) = length;
    Arr(&res) = (Building*) malloc(length*sizeof(Building));
    return res;
}
