#if !defined(__arraydin_h__)
#define __arraydin_h__

typedef struct {
    int length;
    int* arr;
} Arraydin;

Arraydin new_Arraydin();
void Arraydin_addLast(Arraydin* p, int v);
int Arraydin_removeLast(Arraydin* p);

#endif // __arraydin_h__
