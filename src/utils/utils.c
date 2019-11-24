#include "utils.h"

boolean compareString(char* a, char* b) {
    /* KAMUS LOKAL */
    int i = 0;

    /* ALGORITMA */
    while (a[i] != 0 && b != 0 && a[i] == b[i]) {
        ++i;
    }
    return a[i] == b[i];
}

char* toLowerCase(char* p) {
    /* KAMUS LOKAL */
    int i = 0;

    /* ALGORITMA */
    while (p[i] != 0) {
        if ('A' <= p[i] && p[i] <= 'Z') { // Konversi setiap char yang kapital
            p[i] += 'a'-'A';
        }
        ++i;
    }
}

int max(int a, int b) {
    /* ALGORITMA */
    return a > b ? a : b;
}

int min(int a, int b) {
    /* ALGORITMA */
    return a < b ? a : b;
}