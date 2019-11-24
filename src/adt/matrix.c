#include "matrix.h"

Matrix new_Matrix(int r, int c) {
	/* KAMUS LOKAL */
    Matrix res;

    /* ALGORITMA */
    row(&res) = r; // assign baris
    col(&res) = c; // assign kolom

    /* Alokasi array of array */
    array(&res) = (Array*) malloc(sizeof(Array));
    *array(&res) = new_Array(r*c+1);

    /* Set setiap elemen menjadi NULL */
    for (int i = 0; i <= r*c; ++i) {
        tabi(array(&res), i) = 0;
    }
    return res;
}
