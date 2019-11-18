#if !defined(__array_test_h__)
#define __array_test_h__

#include "test.h"
#include "../adt/array.h"

void Array_toString(Array* p, char* res) {
    char str[128];
    res[0] = 0;
    strcat(res, "[");
    if (p->length > 0) {
        sprintf(str, "%d", p->arr[0]);
        strcat(res, str);
        for (int i = 1; i < p->length; ++i) {
            sprintf(str, ",%d", p->arr[i]);
            strcat(res, str);
        }
    }
    strcat(res, "]");
}

void ArrayTest_do() {
    Array arr = new_Array(5);
    char res[512];
    Array_toString(&arr, res);
    asserts("Init 5 equals to", "[0,0,0,0,0]", res);

    arr.arr[0] = 128;
    arr.arr[2] = -11;
    arr.arr[4] = 99999;
    Array_toString(&arr, res);
    asserts("Changed equals to", "[128,0,-11,0,99999]", res);

    assert("Length is 5", arr.length == 5);

    arr = new_Array(0);
    arr.arr[0] = 129;
    Array_toString(&arr, res);
    asserts("Empty array is", "[]", res);

    assert("Length is 0", arr.length == 0);
}

#endif // __array_test_h__
