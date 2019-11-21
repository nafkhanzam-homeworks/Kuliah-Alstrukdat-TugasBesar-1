#if !defined(__matrix_h__)
#define __matrix_h__

#include "array.h"

typedef struct {
    Array arr;
    int row, col;
} Matrix;

Matrix new_Matrix(int r, int c);

#endif // __matrix_h__
