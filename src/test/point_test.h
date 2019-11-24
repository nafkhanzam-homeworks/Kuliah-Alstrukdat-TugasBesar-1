#if !defined(__point_test_h__)
#define __point_test_h__

#include "test.h"
void Point_toString(Point* p, char* res){
    char str[128];
    res[0] = 0;
    append(res, "(");
    sprintf(str, "%d,", x(p));
    append(res, str);
    sprintf(str, "%d", y(p));// karena anu.. p itu pointer, trs selectornya itu pake panah, gw selectornya panah smua..
    append(res, str);
    append(res, ")");
}
void PointTest_do(){
    Point p = new_Point(0,0);
    char res[512];
    Point_toString(&p, res);
    asserts("Init point x=0 y=0", "(0,0)", res);
    p.x=1;
    p.y=1;
    Point_toString(&p, res);
    asserts("Changed equals to", "(1,1)", res);
}

#endif // __point_test_h__
