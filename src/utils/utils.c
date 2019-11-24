#include "utils.h"

boolean compareString(char* a, char* b) {
    /* KAMUS LOKAL */
    int i = 0;

    /* ALGORITMA */
    while (a[i] && b[i] && a[i] == b[i]) {
        ++i;
    }
    return a[i] == b[i];
}

void append(char* a, char* b) {
    /* KAMUS LOKAL */
    int i = 0;

    /* ALGORITMA */
    while (a[i]) ++i;
    int j = i;
    while (b[i-j]) {
        a[i] = b[i-j];
        ++i;
    }
    a[i] = 0;
}

void copyString(char* a, char* b) {
    /* KAMUS LOKAL */
    int i = 0;

    /* ALGORITMA */
    while (a[i]) {
        b[i] = a[i];
        ++i;
    }
    b[i] = 0;
}

void toLowerCase(char* p, char* res) {
    /* KAMUS LOKAL */
    int i = 0;

    /* ALGORITMA */
    copyString(p, res);
    while (res[i]) {
        if ('A' <= res[i] && res[i] <= 'Z') {
            res[i] += 'a'-'A';
        }
        ++i;
    }
}

int enemyIndex(int a) {
    return (a%2) + 1;
}

int max(int a, int b) {
    /* ALGORITMA */
    return a > b ? a : b;
}

int min(int a, int b) {
    /* ALGORITMA */
    return a < b ? a : b;
}