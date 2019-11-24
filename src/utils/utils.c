#include "utils.h"

boolean compareString(char* a, char* b) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i]) {
        ++i;
    }
    return a[i] == b[i];
}

void append(char* a, char* b) {
    int i = 0;
    while (a[i]) ++i;
    int j = i;
    while (b[i-j]) {
        a[i] = b[i-j];
        ++i;
    }
    a[i] = 0;
}

void copyString(char* a, char* b) {
    int i = 0;
    while (a[i]) {
        b[i] = a[i];
        ++i;
    }
    b[i] = 0;
}

void toLowerCase(char* p, char* res) {
    copyString(p, res);
    int i = 0;
    while (res[i]) {
        if ('A' <= res[i] && res[i] <= 'Z') {
            res[i] += 'a'-'A';
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