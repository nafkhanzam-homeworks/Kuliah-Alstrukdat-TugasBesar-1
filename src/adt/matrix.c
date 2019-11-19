#include "matrix.h"
#include <stdlib.h>

Matrix new_Matrix(int r, int c){
    Matrix M;
    Baris(M)=r;
    Kolom(M)=c;
    Arr(M)=(int*)malloc((r*c+1)*sizeof(int));
    return M;
}
