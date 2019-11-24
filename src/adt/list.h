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


// listofact adalah list dengan elemen aksi (di gunakan untuk implementasi aksi)
ListOfAct new_ListOfAct(Act v);
/*I.S listofact tidak terdefinisi
F.s  membuat listofact baru dengan elemen aksi v*/
boolean ListOfAct_isEmpty(ListOfAct* p);
/*I.S listofact terdefinisi
F.s  return boolean apakah listofact kosong*/
ListOfAct ListOfAct_getLast(ListOfAct* p);
/*I.S listofact terdefinisi
F.s  mendapatkan/return elemen terakhir listofact*/
void ListOfAct_addFirst(ListOfAct* p, Act v);
/*I.S listofact terdefinisi dan aksi v terdefinisi
F.s  listofact baru dengan aksi v sebagai elemen pertama*/
void ListOfAct_addLast(ListOfAct* p, Act v);
/*I.S listofact terdefinisi dan aksi v terdefinisi
F.s  listofact baru dengan aksi v sebagai elemen terakhir*/
int ListOfAct_getLength(ListOfAct* p);
/*I.S listofact terdefinisi 
F.s  mendapatkan atau return nilai dari panjang(jumlah elemen) listofact*/
ListOfAct ListOfAct_getSecondLast(ListOfAct* p);
/*I.S listofact terdefinisi
F.s  mendapatkan elemen listofact sebelum terakhir (tepat)*/
Act ListOfAct_removeFirst(ListOfAct* p);
/*I.S listofact terdefinisi
F.s  elemen aksi awal yang di hapus dari listofact*/
Act ListOfAct_removeLast(ListOfAct* p);
/*I.S listoafact terdefinisi
F.s  elemen aksi akhir yang dihapus dari listofact*/


typedef struct _ListOfBuilding {
    Building* info;
    ListOfBuilding next;
} ElementOfListOfBuilding;

ListOfBuilding new_ListOfBuilding(Building v);
/*I.S listofbuilding tidak terdefinisi
F.s listofbuilding terdefinisi */
boolean ListOfBuilding_isEmpty(ListOfBuilding* p);
/*I.S listofbuilding terdefinisi
F.s  return boolean apakah listofbuiling berelemen kosong*/
ListOfBuilding ListOfBuilding_getLast(ListOfBuilding* p);
/*I.S listofbuilding terdefinisi
F.s  mendapakatkan elemen listofbuilding node terakhir*/
void ListOfBuilding_addFirst(ListOfBuilding* p, Building v);
/*I.S listofbuilding dan building terdefinisi
F.s  menambahkan building sebagai elemen pertama dari listofbuiding*/
void ListOfBuilding_addLast(ListOfBuilding* p, Building v);
/*I.S listofbuilding dan building terdefinisi
F.s  menambahkan building v sebagai elemen terakhir dari listofbuilding*/
int ListOfBuilding_getLength(ListOfBuilding* p);
/*I.S listofbuilding terdefinisi
F.s  return integer dari panjang(jumlah elemen) dari listofbuilding*/
ListOfBuilding ListOfBuilding_getSecondLast(ListOfBuilding* p);
/*I.S listofbuilding terdefinisi
F.s  mendapatkan listofbuilding dengan node sebelum terakhir*/
Building ListOfBuilding_removeFirst(ListOfBuilding* p);
/*I.S listofbuilding terdefinisi
F.s  mendapatkan/return building node pertama dan listofbuilding baru dengan node pertama di hilangkan*/
Building ListOfBuilding_removeLast(ListOfBuilding* p);
/*I.S listofbuilding terdefinisi
F.s  listofbuilding baru dengan elemen atau node last di hilangkan dan mengembalikan/return building yang terakhir*/
Building* ListOfBuilding_getAt(ListOfBuilding* p, int i);
/*I.S listofbuilding terdefinisi dan integer i terdefinisi
F.s  mendapatkan building pada listofbuilding indeks ke i*/

#endif // __list_h__
