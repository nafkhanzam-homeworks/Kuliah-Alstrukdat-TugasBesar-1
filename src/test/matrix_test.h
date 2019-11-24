#if !defined(__matrix_test_h__)
#define __matrix_test_h__

#include "test.h"
void Matrix_toString(Matrix* p, char* res) {
    char str[128];
    res[0] = 0;
    append(res, "[");
    if (row(p)*col(p) > 0) {
        for (int i = 1; i <= row(p); i++) {
            append(res, "[");
            sprintf(str, "%d", tabij(p, i, 1));
            append(res, str);
            for (int j=2; j <= col(p); j++){
                sprintf(str, ",%d", tabij(p, i, j));
                append(res, str);
            }
            append(res, "]");
        }
    }
    append(res, "]");
}
void MatrixTest_do() {
    Matrix p = new_Matrix(2,5);
    char res[512];
    Matrix_toString(&p, res);
    asserts("Init row 2 and col 5 equals to", "[[0,0,0,0,0][0,0,0,0,0]]", res);

    tabij(&p, 1, 1) = 128;
    tabij(&p, 1, 3) = -11;
    tabij(&p, 2, 5) = 99999;
    Matrix_toString(&p, res);
    asserts("Changed equals to", "[[128,0,-11,0,0][0,0,0,0,99999]]", res);

    assert("row is 1", p.row == 2);
    assert("col is 5", p.col == 5);
}

#endif // __matrix_test_h__
