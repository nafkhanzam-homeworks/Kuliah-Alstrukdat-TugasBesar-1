#if !defined(__point_h__)
#define __point_h__

#include "../headers.h"

typedef struct _Point {
    int x, y;
} Point;

Point new_Point(int x, int y);

#endif // __point_h__
