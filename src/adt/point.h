#if !defined(__point_h__)
#define __point_h__

#include "selector_adt.h"

typedef struct {
    int x, y;
} Point;

Point new_Point(int x, int y);

#endif // __point_h__
