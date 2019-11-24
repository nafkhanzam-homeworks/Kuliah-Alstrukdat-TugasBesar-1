#if !defined(__TEST__)
#define __TEST__

#include <stdio.h>
#include "test.h"
#include "array_test.h"
#include "utils_test.h"
#include "matrix_test.h"
#include "point_test.h"
#include "list_test.h"
#include "queue_test.h"
#include "stack_test.h"
#include "graph_test.h"
#include "mesinkata_test.h"

void doTheTests() {
    printf(YELLOW);printf("Utils Tests:\n");printf(NORMAL);
    UtilsTest_do();
    printf(YELLOW);printf("Array Tests:\n");printf(NORMAL);
    ArrayTest_do();
    printf(YELLOW);printf("Matrix Tests:\n");printf(NORMAL);
    MatrixTest_do();
    printf(YELLOW);printf("Point Tests:\n");printf(NORMAL);
    PointTest_do();
    printf(YELLOW);printf("List Tests:\n");printf(NORMAL);
    ListTest_do();
    printf(YELLOW);printf("Queue Tests:\n");printf(NORMAL);
    QueueTest_do();
    printf(YELLOW);printf("Stack Tests:\n");printf(NORMAL);
    StackTest_do();
    printf(YELLOW);printf("Graph Tests:\n");printf(NORMAL);
    GraphTest_do();
    printf(YELLOW);printf("MesinKata Tests:\n");printf(NORMAL);
    MesinKataTest_do();
}

void main() {
    printf(YELLOW);printf("========[ UNIT TESTS ]========");printf(NORMAL);printf("\n");
    doTheTests();
    printf(YELLOW);printf("==============================");printf(NORMAL);printf("\n");
    printf(GREEN);printf("Tests passed: ");printf(NORMAL);printf("%d", correct);printf("\n");
    printf(RED);printf("Tests failed: ");printf(NORMAL);printf("%d", total-correct);printf("\n");
}

#endif // __TEST__
