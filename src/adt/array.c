#include "array.h"

Array new_Array(int length) {
    Array res;
    length(&res) = length;
    tab(&res) = (int*) malloc((length+1)*sizeof(int));
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
