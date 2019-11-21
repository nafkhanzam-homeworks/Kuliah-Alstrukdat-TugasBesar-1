#if !defined(__TEST__)
#define __TEST__

#include <stdio.h>
#include "../utils/pcolor.h"

#include "test.h"
#include "array_test.h"
#include "graph_test.h"

void doTheTests() {
    printf("Array Tests:\n");
    ArrayTest_do();
    printf("Graph Tests:\n");
    GraphTest_do();
}

void main() {
    printf(YELLOW);printf("========[ UNIT TESTS ]========");printf(NORMAL);printf("\n");
    doTheTests();
    printf(YELLOW);printf("==============================");printf(NORMAL);printf("\n");
    printf(GREEN);printf("Tests passed: ");printf(NORMAL);printf("%d", correct);printf("\n");
    printf(RED);printf("Tests failed: ");printf(NORMAL);printf("%d", total-correct);printf("\n");
}

#endif // __TEST__
