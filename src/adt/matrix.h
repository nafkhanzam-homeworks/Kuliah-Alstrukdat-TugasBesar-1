#if !defined(__matrix_h__)
#define __matrix_h__

typedef struct {
    int* arr;
    int r, c;
} Matrix;

Matrix new_Matrix(int r, int c);
void Matrix_set(Matrix* p, int r, int c, int v);
int Matrix_get(Matrix* p, int r, int c);

#endif // __matrix_h__
