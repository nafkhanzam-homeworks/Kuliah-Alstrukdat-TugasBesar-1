#if !defined(__list_test_h__)
#define __list_test_h__

#include "test.h"

void List_toString(List* p, char* res) {
    char str[128];
    res[0] = 0;
    append(res, "[");
    if (List_getLength(p) > 0) {
        sprintf(str, "%d", List_getAt(p, 1));
        append(res, str);
        for (int i = 2; i <= List_getLength(p); ++i) {
            sprintf(str, ",%d", List_getAt(p, i));
            append(res, str);
        }
    }
    append(res, "]");
}

void ListTest_do() {
    List list = NULL;
    char res[512];
    List_toString(&list, res);
    asserts("Init list equals to", "[]", res);

    List_addLast(&list, 1);
    List_addFirst(&list, 0);
    List_addLast(&list, 2);
    List_addFirst(&list, -1);
    List_addLast(&list, 3);

    List_toString(&list, res);
    asserts("Changed equals to", "[-1,0,1,2,3]", res);

    assert("Length is 5", List_getLength(&list) == 5);

    int firstValue = List_removeFirst(&list);
    int lastValue = List_removeLast(&list);
    assert("First value is -1", firstValue == -1);
    assert("Last value is 3", lastValue == 3);
    List_toString(&list, res);
    asserts("After removed first and last", "[0,1,2]", res);

    assert("Length is 3", List_getLength(&list) == 3);

    List_remove(&list, 1);
    List_toString(&list, res);
    asserts("After removed 1", "[0,2]", res);
}

#endif // __list_test_h__
