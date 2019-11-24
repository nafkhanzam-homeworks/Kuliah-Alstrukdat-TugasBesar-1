#if !defined(__list_h__)
#define __list_h__

#include "../headers.h"

typedef struct _List {
    int info;
    List next;
} ElementOfList;

List new_List(int v);
/*I.S list tidak terdefinisi
F.S  membuat list baru dengan elemen v */
boolean List_isEmpty(List* p);
/*I.S list terdefinisi
F.S  return boolean dengan cek apakah list kosong */
List* List_getLast(List* p);
/*I.S list terdefinisi
F.S  return list dengan node terakhir */
void List_addFirst(List* p, int v);
/*I.S list terdefinisi dan v integer terdefinsii
F.S  menambahlan node pertama list dengan elemen info v */
void List_addLast(List* p, int v);
/*I.S list terdefinisi
F.S  menambahkan node terakhir list dengan elemen info v */
int List_getLength(List* p);
/*I.S list terdefinisi
F.S  return nilai integer panjang dari list */
int List_removeFirst(List* p);
/*I.S list terdefinisi
F.S  list baru dengan node pertama di hapus */
int List_removeLast(List* p);
/*I.S list terdefinisi
F.S  list baru dengan node terakhir di hapus */
int List_remove(List* p, int i);
/*I.S list terdefinisi dan integer i terdefinisi
F.S  list baru dengan node list ber elemen info integer i di hapus dari list */
int List_getAt(List* p, int i);
/*I.S list terdefinisi dan i terdefinisi integer
F.S  return elemen info dari list sebagai yang berindeks i */
boolean List_contains(List* p, int i);
/*I.S list, dan nilai elemen yang akan di cari terdefinsi
F.S  return boolean apakah nilai i ada dalam list p */

typedef struct _ListOfList {
    List info;
    ListOfList next;
} ElementOfListOfList;


// listoflist adalah list dengan elemen list

ListOfList new_ListOfList(List v);
/*I.S listoflist tidak terdefinisi
F.s  listoflist terdefinisi dan elemen listoflist tersebut adalah list v */
boolean ListOfList_isEmpty(ListOfList* p);
/*I.S listoflist terdefinsi
F.s return boolean apakah listoflist kosong*/
ListOfList ListOfList_getLast(ListOfList* p);
/*I.S listoflist terdefinisi
F.s  mendapatkan listoflist (untaian list) pada node terakhir*/
void ListOfList_addFirst(ListOfList* p, List v);
/*I.S listoflist terdefinisi, dan list v terdefinisi
F.s  listoflist baru dengan elemen pertama list v */
void ListOfList_addLast(ListOfList* p, List v);
/*I.S  listoflist terdefinsi, dan list v terdefinisi
F.s  listoflist baru dengan elemen terakhir adalah list v */
int ListOfList_getLength(ListOfList* p);
/*I.S listoflist terdefinisi
F.s mendapatkan atau return integer dari panjang listoflist */
ListOfList ListOfList_getSecondLast(ListOfList* p);
/*I.S listoflist terdefinisi
F.s  mendapatkan elemen sebelum terakhir dari listoflist */
List ListOfList_removeFirst(ListOfList* p);
/*I.S listoflist terdefinisi
F.s listoflist baru dengan elemen pertama yang di hilangkan */
List ListOfList_removeLast(ListOfList* p);
/*I.S listoflist terdefinisi
F.s  listoflist baru dengan elemen terakir di hilangkan*/
List* ListOfList_getAt(ListOfList* p, int i);
/*I.S listoflist terdefinisi
F.s  mendapatkan elemen listoflist (list) di indeks ke i*/

typedef struct _ListOfOps {
    Ops* info;
    ListOfOps next;
} ElementOfListOfOps;

ListOfOps new_ListOfOps(Ops v);
boolean ListOfOps_isEmpty(ListOfOps* p);
ListOfOps ListOfOps_getLast(ListOfOps* p);
void ListOfOps_addFirst(ListOfOps* p, Ops v);
void ListOfOps_addLast(ListOfOps* p, Ops v);
int ListOfOps_getLength(ListOfOps* p);
ListOfOps ListOfOps_getSecondLast(ListOfOps* p);
Ops ListOfOps_removeFirst(ListOfOps* p);
Ops ListOfOps_removeLast(ListOfOps* p);

typedef struct _ListOfAct {
    Act* info;
    ListOfAct next;
} ElementOfListOfAct;

ListOfAct new_ListOfAct(Act v);
boolean ListOfAct_isEmpty(ListOfAct* p);
ListOfAct ListOfAct_getLast(ListOfAct* p);
void ListOfAct_addFirst(ListOfAct* p, Act v);
void ListOfAct_addLast(ListOfAct* p, Act v);
int ListOfAct_getLength(ListOfAct* p);
ListOfAct ListOfAct_getSecondLast(ListOfAct* p);
Act ListOfAct_removeFirst(ListOfAct* p);
Act ListOfAct_removeLast(ListOfAct* p);

typedef struct _ListOfBuilding {
    Building* info;
    ListOfBuilding next;
} ElementOfListOfBuilding;

ListOfBuilding new_ListOfBuilding(Building v);
boolean ListOfBuilding_isEmpty(ListOfBuilding* p);
ListOfBuilding ListOfBuilding_getLast(ListOfBuilding* p);
void ListOfBuilding_addFirst(ListOfBuilding* p, Building v);
void ListOfBuilding_addLast(ListOfBuilding* p, Building v);
int ListOfBuilding_getLength(ListOfBuilding* p);
ListOfBuilding ListOfBuilding_getSecondLast(ListOfBuilding* p);
Building ListOfBuilding_removeFirst(ListOfBuilding* p);
Building ListOfBuilding_removeLast(ListOfBuilding* p);
Building* ListOfBuilding_getAt(ListOfBuilding* p, int i);

#endif // __list_h__
