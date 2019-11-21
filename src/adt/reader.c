#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

Reader new_Reader() {
    Reader res;
    res.in = stdin;
    res.cin = 0;
    return res;
}

Reader new_FileReader(char* fileName) {
    Reader res;
    res.in = fopen(fileName, "r");
    res.cin = 0;
    return res;
}

void Reader_ignoreBlank(Reader* p) {
    while (Reader_nonReadableCharacter(p)) {
        Reader_adv(p);
    }
}

void Reader_adv(Reader* p) {
    p->cin = fscanf(p->in, "%c");
}

char* Reader_readString(Reader* p) {
    Reader_ignoreBlank(p);
    char* res = (char*) malloc(MAX_LENGTH*sizeof(char));
    int i = 0;
    while (!Reader_isNonReadableCharacter(p)) {
        res[i++] = p->cin;
        Reader_adv(p);
    }
    res[i] = 0;
    return res;
}

int Reader_readInt(Reader* p) {
    Reader_ignoreBlank(p);
    int res = 0;
    while (p->cin >= '0' && p->cin <= '9') {
        res = res*10 + p->cin - '0';
        Reader_adv(p);
    }
    return res;
}

boolean Reader_isNonReadableCharacter(Reader* p) {
    return!('0' <= p->cin && p->cin <= '9' ||
            'a' <= p->cin && p->cin <= 'z' ||
            'A' <= p->cin && p->cin <= 'Z');
}
