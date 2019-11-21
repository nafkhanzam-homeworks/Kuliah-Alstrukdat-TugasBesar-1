#include "matrix.h"

#include <stdlib.h>

Matrix new_Matrix(int r, int c) {
    Matrix res;
    res.row = r;
    res.col = c;
    res.arr = new_Array(r*c+1);
    return res;
}
