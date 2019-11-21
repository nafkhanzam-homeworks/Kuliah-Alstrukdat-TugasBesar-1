#include "utils.h"

boolean strcmp(char* a, char* b) {
    int i = 0;
    while (a[i] != 0 && b != 0 && a[i] == b[i]) {
        ++i;
    }
    return a[i] == b[i];
}
