#if !defined(__test_h__)
#define __test_h__

#include <stdio.h>
#include "../headers.h"

int total = 0, correct = 0;

int asserts(char* msg, char* a, char* b) {
    boolean res = compareString(a, b);
    printf("%s%d. %s - %s%s%s%s\n", res ? GREEN : RED, ++total, res ? "PASSED" : "FAILED", msg, " ", a, NORMAL);
    if (res) {
        ++correct;
    } else {
        printf("EXPECTED : %s\nGOT\t : %s\n", a, b);
    }
}

int assert(char* msg, boolean res) {
    printf("%s%d. %s - %s\n%s", res ? GREEN : RED, ++total, res ? "PASSED" : "FAILED", msg, NORMAL);
    if (res) {
        ++correct;
    }
}

#endif // __test_h__
