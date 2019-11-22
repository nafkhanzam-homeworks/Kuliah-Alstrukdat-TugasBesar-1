#if !defined(__matrix_h__)
#define __matrix_h__

typedef struct _Matrix Matrix;
#include "../headers.h"

typedef struct _Matrix {
    Array array;
    int row, col;
} Matrix;

Matrix new_Matrix(int r, int c);

#endif // __matrix_h__
