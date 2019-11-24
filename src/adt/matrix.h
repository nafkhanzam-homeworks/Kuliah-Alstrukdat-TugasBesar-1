#if !defined(__matrix_h__)
#define __matrix_h__

#include "../headers.h"

typedef struct _Matrix {
    Array* array;
    int row, col;
} Matrix;

Matrix new_Matrix(int r, int c);
/*I.S matriks tidak terdefinisi
F.s matriks terdefinisi dengan r dan c sebagai indeks baris dan kolom*/

#endif // __matrix_h__
