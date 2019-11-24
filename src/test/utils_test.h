#if !defined(__utils_test_h__)
#define __utils_test_h__

#include "test.h"

void UtilsTest_do() {
    assert("compareString abcd abcd is true", compareString("abcd", "abcd"));
    assert("compareString abc abcd is false", !compareString("abc", "abcd"));
    assert("compareString abcd abc is false", !compareString("abcd", "abc"));
    assert("compareString abcd abcf is false", !compareString("abcd", "abcf"));
    char res[4];
    toLowerCase("A23CD", res);
    assert("toLowerCase A23CD -> a23cd is true", compareString(res, "a23cd"));
}

#endif // __utils_test_h__
