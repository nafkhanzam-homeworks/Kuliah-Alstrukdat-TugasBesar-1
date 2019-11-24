#include "point.h"

Point new_Point(int x, int y) {
	/* KAMUS LOKAL */
    Point res;

    /* ALGORITMA */
    x(&res) = x; // Koordinat sumbu X
    y(&res) = y; // Koordinat sumbu Y
    return res;
}