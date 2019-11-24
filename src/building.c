#include "building.h"

Building new_Building(char c, int x, int y, int owner) {
    /* KAMUS LOKAL */
    Building res;
    
    /* ALGORITMA */

    // Alokasi array of point sebagai posisi
    position(&res) = (Point*) malloc(sizeof(Point));
    *position(&res) = new_Point(x, y);

    // Set jumlah pasukan awal sesuai dengan tipe bangunan
    armyCount(&res) = Building_getStartingArmy(c);
    
    // Set level awal bangunan menjadi lv. 1
    level(&res) = 1;

    // Set status kepemilikan bangunan (player 1, player 2, bebas milik)
    owner(&res) = owner;

    // Set tipe bangunan pada tipen bentukan bangunan
    type(&res) = c;

    // Set status riwayat penyerangan
    hasAttacked(&res) = false;

    return res;
}

void Building_printList(Game* p, List list, char* title) {
    /* KAMUS LOKAL */
    int i = 0;

    /* ALGORITMA */
    printf("%s\n", title);

    // Iterasi print lisrt sampai list kosong
    while (list != NULL) {
        Building b = ListOfBuilding_getAt(&buildingList(p), info(list));
        Building_printStatus(&b, ++i);
        list = next(list);
    }
}

void Building_printStatus(Building* p, int number) {
    /* ALGORITMA */

    // Cetak status bangunan
    printf("%d. %s (%d,%d) %d lv. %d\n", number, Building_getName(type(p)), x(position(p)), y(position(p)), armyCount(p), level(p));
}

int Building_getMaxArmy(char type, int level) {
    switch (type) {
        case 'C': return 20*(level+1);
        case 'T': return 10*(level+1);
        case 'F': return 20*level;
        case 'V': return 10*(level+1);
    }
    return -1;
}

int Building_getArmyAddition(char type, int level) {
    /* ALGORITMA */
    switch (type) {
        case 'C': return 5*(level+1);
        case 'T': return 10*(level-1) + (level == 1 ? 5 : 0);
        case 'F': return 10*level;
        case 'V': return 5*level;
    }
    return -1;
}

char* Building_getName(char type) {
    /* ALGORITMA */
    switch (type) {
        case 'C': return "Castle";
        case 'T': return "Tower";
        case 'F': return "Fort";
        case 'V': return "Village";
    }
    return NULL;
}

boolean Building_isShielded(char type, int level) {
    /* ALGORITMA */
    return type != 'C' && type != 'V' && (type == 'T' || level >= 3);
}

int Building_getStartingArmy(char type) {
    /* ALGORITMA */
    switch (type) {
        case 'C': return 40;
        case 'T': return 30;
        case 'F': return 80;
        case 'V': return 20;
    }
    return -1;
}

Building Building_getBuilding(Game* p, int id) {
    /* ALGORITMA */
    return ListOfBuilding_getAt(&buildingList(p), id);
}
