#include "array.h"

#include <stdlib.h>

Array new_Array(int length) {
    Array res;
    res.length = length;
    res.tab = (int*) malloc((length+1)*sizeof(int));
    return res;
}

ArrayOfList new_ArrayOfList(int length) {
    ArrayOfList res;
    res.length = length;
    res.tab = (List*) malloc((length+1)*sizeof(List));
    return res;
}

ArrayOfBuilding new_ArrayOfBuilding(int length) {
    ArrayOfBuilding res;
    res.length = length;
    res.tab = (Building*) malloc((length+1)*sizeof(Building));
    return res;
}
