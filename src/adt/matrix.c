#include "matrix.h"

Matrix new_Matrix(int r, int c) {
    Matrix res;
    row(&res) = r;
    col(&res) = c;
    array(&res) = (Array*) malloc(sizeof(Array));
    *array(&res) = new_Array(r*c+1);
    for (int i = 0; i <= r*c; ++i) {
        tabi(array(&res), i) = 0;
    }
    return res;
}
