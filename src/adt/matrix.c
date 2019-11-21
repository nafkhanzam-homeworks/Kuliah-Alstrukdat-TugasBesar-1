#include "matrix.h"

#include <stdlib.h>

Matrix new_Matrix(int r, int c) {
    Matrix res;
    row(&res) = r;
    col(&res) = c;
    array(&res) = new_Array(r*c+1);
    return res;
}
