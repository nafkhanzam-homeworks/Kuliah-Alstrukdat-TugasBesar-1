#include "point.h"

Point new_Point(int x, int y) {
    Point res;
    x(&res) = x;
    y(&res) = y;
    return res;
}