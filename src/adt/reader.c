#include "reader.h"

#include <stdio.h>

Reader new_Reader() {
    Reader res;
    Reader_in(&res) = stdin;
    Reader_cin(&res) = 0;
    return res;
}

Reader new_FileReader(char* fileName) {
    Reader res;
    Reader_in(&res) = fopen(fileName, "r");
    Reader_cin(&res) = 0;
    return res;
}

void Reader_ignoreBlank(Reader* p) {
    while (Reader_cin(p) == BLANK) {
        Reader_adv(p);
    }
}

void Reader_adv(Reader* p) {
    Reader_cin(p) = fscanf(Reader_in(p), "%c");
}

char Reader_read(Reader* p) {
    Reader_ignoreBlank(p);
    return Reader_cin(p);
}

char* Reader_readString(Reader* p) {
    Reader_ignoreBlank(p);
    
}

int Reader_readInt(Reader* p) {
    Reader_ignoreBlank(p);
    
}
