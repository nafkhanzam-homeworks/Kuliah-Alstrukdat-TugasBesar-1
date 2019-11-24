#include "mesinkata.h"

MesinKata new_MesinKata() {
    /* KAMUS LOKAL */
    MesinKata res;

    /* ALGORITMA */
    stream(&res) = stdin; // Menyiapkan proses membaca dari standart i/o terminal
    readChar(&res) = 0;
    return res;
}

MesinKata new_FileMesinKata(char* fileName) {
    /* KAMUS LOKAL */
    MesinKata res;

    /* ALGORITMA */
    MesinKata_startFile(&res, fileName);
    return res;
}

void MesinKata_startFile(MesinKata* p, char* fileName) {
    /* ALGORITMA */
    stream(p) = fopen(fileName, "r"); // Menyiapkan pembacaan dari file
    readChar(p) = 0;
}

void MesinKata_ignoreBlank(MesinKata* p) {
    /* ALGORITMA */
    while (MesinKata_isNonReadableCharacter(p)) {
        MesinKata_adv(p);
    }
}

void MesinKata_adv(MesinKata* p) {
    /* ALGORITMA */
    if (!feof(stream(p))) { // Jika input file belum berakhir, mengembalikan char input
        fscanf(stream(p), "%c", &readChar(p));
    } else { // Jika input berakhir, set menjadi NULL
        readChar(p) = 0;
    }
}

char* MesinKata_readString(MesinKata* p) {
    /* KAMUS LOKAL */
    char* res = (char*) malloc(MAX_LENGTH*sizeof(char));
    int i = 0;

    /* ALGORITMA */
    MesinKata_ignoreBlank(p);

    /* Membaca string masukan */
    while (!MesinKata_isNonReadableCharacter(p)) {
        res[i++] = readChar(p);
        MesinKata_adv(p);
    }
    res[i] = 0; // Set akhir dari pembacaan menjadi NULL
    return res;
}

int MesinKata_readInt(MesinKata* p) {
    /* KAMUS LOKAL */
    int res = 0;

    /* ALGORITMA */
    MesinKata_ignoreBlank(p);

    /* Melakukan konversi string angka ke integer */
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
    /* ALGORITMA */
    return!('0' <= readChar(p) && readChar(p) <= '9' ||
            'a' <= readChar(p) && readChar(p) <= 'z' ||
            'A' <= readChar(p) && readChar(p) <= 'Z' ||
            readChar(p) == '_');
}
