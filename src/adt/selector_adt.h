#if !defined(__selector_adt_h__)
#define __selector_adt_h__

#define length(P) (P)->length
#define array(P) (P)->array
#define tab(P) (P)->tab
#define tabi(P, i) (P)->tab[(i)]
#define tabij(P, i, j) (P)->array.tab[i*((P)->col) + j]
#define row(P) (P)->row
#define col(P) (P)->col
#define info(P) (P)->info
#define next(P) (P)->next
#define x(P) (P)->x
#define y(P) (P)->y
#define list(P) (P)->list
#define stream(P) (P)->stream
#define readChar(P) (P)->readChar

#endif // __selector_adt_h__
