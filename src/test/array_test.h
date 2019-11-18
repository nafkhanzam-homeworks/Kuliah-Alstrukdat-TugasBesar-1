#if !defined(__array_test_h__)
#define __array_test_h__

#include "test.h"
#include "../adt/array.h"

char* Array_toString(Array* p) {
    char* res;
    sprintf(res, "[");
    if (p->length > 0) {
        sprintf(res, "%d", p->arr[0]);
        for (int i = 1; i < p->length; ++i) {
            sprintf(res, ",%d", p->arr[i]);
        }
    }
    sprintf(res, "]");
    return res;
}

void Array_initCheck() {
    Array arr = new_Array(5);
    assert("Init 5 equals to [0,0,0,0,0]", eq("[0,0,0,0,0]", Array_toString(&arr)));
}

void ArrayTest_do() {
    Array_initCheck();
}

#endif // __array_test_h__
