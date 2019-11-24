#include "array.h"

Array new_Array(int length) {
    /* KAMUS LOKAL */
    Array res;

    /* ALGORITMA */
    length(&res) = length;
    tab(&res) = (int*) malloc((length+1)*sizeof(int)); // alokasi array
    return res;
}

ArrayOfBuilding new_ArrayOfBuilding(int length) {
    /* KAMUS LOKAL */
    ArrayOfBuilding res;

    /* ALGORITMA */
    length(&res) = length;
    tab(&res) = (Building*) malloc((length+1)*sizeof(Building)); // alokasi array of bangunan
    return res;
}

ArrayOfPlayer new_ArrayOfPlayer(int length) {
    /* KAMUS LOKAL */
    ArrayOfPlayer res;

    /* ALGORITMA */
    length(&res) = length;
    tab(&res) = (Player*) malloc((length+1)*sizeof(Player)); // alokasi array of pemain
    return res;
}
