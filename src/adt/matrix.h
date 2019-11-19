#if !defined(__matrix_h__)
#define __matrix_h__

typedef struct {
    int* arr;
    int r, c;
} Matrix;

// Selektor Matrix(M)
#define Value(M, i,j) (M).arr[i][j]
#define Arr(M) (M).arr
#define Baris(M) (M).r
#define Kolom(M) (M).c

Matrix new_Matrix(int r, int c);

#endif // __matrix_h__
