#if !defined(__matrix_h__)
#define __matrix_h__

#include "selector_adt.h"

#include "array.h"

typedef struct {
    Array array;
    int row, col;
} Matrix;

Matrix new_Matrix(int r, int c);

#endif // __matrix_h__
