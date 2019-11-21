#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

Reader new_Reader() {
    Reader res;
    stream(&res) = stdin;
    readChar(&res) = 0;
    return res;
}

Reader new_FileReader(char* fileName) {
    Reader res;
    stream(&res) = fopen(fileName, "r");
    readChar(&res) = 0;
    return res;
}

void Reader_ignoreBlank(Reader* p) {
    while (Reader_nonReadableCharacter(p)) {
        Reader_adv(p);
    }
}

void Reader_adv(Reader* p) {
    readChar(p) = fscanf(stream(p), "%c");
}

char* Reader_readString(Reader* p) {
    Reader_ignoreBlank(p);
    char* res = (char*) malloc(MAX_LENGTH*sizeof(char));
    int i = 0;
    while (!Reader_isNonReadableCharacter(p)) {
        res[i++] = readChar(p);
        Reader_adv(p);
    }
    res[i] = 0;
    return res;
}

int Reader_readInt(Reader* p) {
    Reader_ignoreBlank(p);
    int res = 0;
    while (readChar(p) >= '0' && readChar(p) <= '9') {
        res = res*10 + readChar(p) - '0';
        Reader_adv(p);
    }
    return res;
}

boolean Reader_isNonReadableCharacter(Reader* p) {
    return!('0' <= readChar(p) && readChar(p) <= '9' ||
            'a' <= readChar(p) && readChar(p) <= 'z' ||
            'A' <= readChar(p) && readChar(p) <= 'Z');
}
