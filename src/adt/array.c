#include "array.h"

#include <stdlib.h>

Array new_Array(int length) {
    Array res;
    length(&res) = length;
    tab(&res) = (int*) malloc((length+1)*sizeof(int));
    return res;
}

ArrayOfList new_ArrayOfList(int length) {
    ArrayOfList res;
    length(&res) = length;
    tab(&res) = (List*) malloc((length+1)*sizeof(List));
    return res;
}

ArrayOfBuilding new_ArrayOfBuilding(int length) {
    ArrayOfBuilding res;
    length(&res) = length;
    tab(&res) = (Building*) malloc((length+1)*sizeof(Building));
    return res;
}

ArrayOfPlayer new_ArrayOfPlayer(int length) {
    ArrayOfPlayer res;
    length(&res) = length;
    tab(&res) = (Player*) malloc((length+1)*sizeof(Player));
    return res;
}
