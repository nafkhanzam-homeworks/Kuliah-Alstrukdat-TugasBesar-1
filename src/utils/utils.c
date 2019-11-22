#include "utils.h"

boolean compareString(char* a, char* b) {
    int i = 0;
    while (a[i] != 0 && b != 0 && a[i] == b[i]) {
        ++i;
    }
    return a[i] == b[i];
}

char* toLowerCase(char* p) {
    int i = 0;
    while (p[i] != 0) {
        if ('A' <= p[i] && p[i] <= 'Z') {
            p[i] += 'a'-'A';
        }
        ++i;
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}