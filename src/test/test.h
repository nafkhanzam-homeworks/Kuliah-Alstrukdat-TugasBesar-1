#if !defined(__test_h__)
#define __test_h__

#include <stdio.h>
#include <string.h>
#include "../adt/boolean.h"
#include "../utils/pcolor.h"

int total = 0, correct = 0;

int assert(char* msg, boolean res) {
    printf("%s%d. %s - %s\n%s", res ? GREEN : RED, ++total, res ? "PASSED" : "FAILED", msg, NORMAL);
    if (res) {
        ++correct;
    }
}

int eq(char* a, char* b) {
    return !strcmp(a, b);
}

#endif // __test_h__
