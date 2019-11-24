#include "mesinkata.h"

MesinKata new_MesinKata() {
    MesinKata res;
    stream(&res) = stdin;
    readChar(&res) = 0;
    return res;
}

MesinKata new_FileMesinKata(char* fileName) {
    MesinKata res;
    MesinKata_startFile(&res, fileName);
    return res;
}

void MesinKata_startFile(MesinKata* p, char* fileName) {
    stream(p) = fopen(fileName, "r");
    readChar(p) = 0;
}

void MesinKata_ignoreBlank(MesinKata* p) {
    while (MesinKata_isNonReadableCharacter(p)) {
        MesinKata_adv(p);
    }
}

void MesinKata_adv(MesinKata* p) {
    if (!feof(stream(p))) {
        fscanf(stream(p), "%c", &readChar(p));
    } else {
        readChar(p) = 0;
    }
}

char* MesinKata_readString(MesinKata* p) {
    MesinKata_ignoreBlank(p);
    char* res = (char*) malloc(MAX_LENGTH*sizeof(char));
    int i = 0;
    while (!MesinKata_isNonReadableCharacter(p)) {
        res[i++] = readChar(p);
        MesinKata_adv(p);
    }
    while (readChar(p) != ' ' && readChar(p) != '\n') {
        MesinKata_adv(p);
    }
    res[i] = 0;
    return res;
}

int MesinKata_readInt(MesinKata* p) {
    MesinKata_ignoreBlank(p);
    int res = 0;
    while (readChar(p) >= '0' && readChar(p) <= '9') {
        res = res*10 + readChar(p) - '0';
        MesinKata_adv(p);
    }
    while (!MesinKata_isNonReadableCharacter(p)) {
        MesinKata_adv(p);
    }
    return res;
}

boolean MesinKata_isNonReadableCharacter(MesinKata* p) {
    return!('0' <= readChar(p) && readChar(p) <= '9' ||
            'a' <= readChar(p) && readChar(p) <= 'z' ||
            'A' <= readChar(p) && readChar(p) <= 'Z' ||
            readChar(p) == '_');
}
