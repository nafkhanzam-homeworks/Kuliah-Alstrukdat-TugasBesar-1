#if !defined(__array_test_h__)
#define __array_test_h__

#include "test.h"

void Array_toString(Array* p, char* res) {
    char str[128];
    res[0] = 0;
    append(res, "[");
    if (length(p) > 0) {
        sprintf(str, "%d", tabi(p, 1));
        append(res, str);
        for (int i = 2; i <= length(p); ++i) {
            sprintf(str, ",%d", tabi(p, i));
            append(res, str);
        }
    }
    append(res, "]");
}

void ArrayTest_do() {
    Array tab = new_Array(5);
    char res[512];
    Array_toString(&tab, res);
    asserts("Init 5 equals to", "[0,0,0,0,0]", res);

    tab.tab[1] = 128;
    tab.tab[3] = -11;
    tab.tab[5] = 99999;
    Array_toString(&tab, res);
    asserts("Changed equals to", "[128,0,-11,0,99999]", res);

    assert("Length is 5", tab.length == 5);

    tab = new_Array(0);
    tab.tab[0] = 129; // fake assign
    Array_toString(&tab, res);
    asserts("Empty array is", "[]", res);

    assert("Length is 0", tab.length == 0);
}

#endif // __array_test_h__
