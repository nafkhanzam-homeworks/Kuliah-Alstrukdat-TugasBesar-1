#include <stdio.h>
#include "../adt/array.h"
#include "../utils/pcolor.h"

#include "test.h"
#include "array_test.h"

void out(char* msg) {
    printf("%s", msg);
}

void outc(char c) {
    printf("%c", c);
}

void outi(int i) {
    printf("%d", i);
}

void enter() {
    printf("\n");
}

void outln(char* msg) {
    out(msg);
    enter();
}

void outlni(int i) {
    outi(i);
    enter();
}

void doTheTests() {
    outln("Array Tests:");
    ArrayTest_do();
}

void main() {
    out(YELLOW);out("========[ UNIT TESTS ]========");outln(NORMAL);
    doTheTests();
    out(YELLOW);out("==============================");outln(NORMAL);
    out(GREEN);out("Tests passed: ");out(NORMAL);outi(correct);enter();
    out(RED);out("Tests failed: ");out(NORMAL);outi(total-correct);enter();
}