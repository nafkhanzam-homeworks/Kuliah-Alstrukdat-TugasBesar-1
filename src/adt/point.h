#if !defined(__point_h__)
#define __point_h__

typedef struct {
    int x, y;
} Point;

#define Absis(P) (P).x
#define Ordinat(P) (P).y

Point new_Point(int x, int y);

#endif // __point_h__
