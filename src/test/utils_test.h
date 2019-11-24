#if !defined(__utils_test_h__)
#define __utils_test_h__

#include "test.h"

void UtilsTest_do() {
    assert("compareString abc abcd is false", !compareString("abc", "abcd"));
    assert("compareString abcd abc is false", !compareString("abcd", "abc"));
    char res[4];
    toLowerCase("ABCD", res);
    assert("toLowerCase ABCD -> abcd is true", compareString(res, "abcd"));
}

#endif // __utils_test_h__
