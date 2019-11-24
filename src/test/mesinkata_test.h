#if !defined(__reader_test_h__)
#define __reader_test_h__

#include "test.h"

void MesinKataTest_do() {
    // read file..
    MesinKata fileReader = new_FileMesinKata("src/test/mesinkata_test.h");
    asserts("Reading first word of this file:", "if", MesinKata_readString(&fileReader));
    asserts("Reading second word of this file:", "defined", MesinKata_readString(&fileReader));
    asserts("Reading third word of this file:", "__reader_test_h__", MesinKata_readString(&fileReader));
    asserts("Reading forth word of this file:", "define", MesinKata_readString(&fileReader));

    // read console..
    MesinKata reader = new_MesinKata();
    printf("Write \"for_testing\": ");
    char* ans = MesinKata_readString(&reader);
    asserts("Input is", "for_testing", ans);

    printf("Write number 123456: ");
    int number = MesinKata_readInt(&reader);
    assert("Input is 123456", number == 123456);
}

#endif // __reader_test_h__
