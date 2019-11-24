#if !defined(__headers_h__)
#define __headers_h__

typedef struct _Player Player;
typedef struct _Game Game;
typedef struct _Building Building;
typedef struct _Ops Ops;
typedef struct _Act Act;
typedef struct _Array Array;
typedef struct _ArrayOfBuilding ArrayOfBuilding;
typedef struct _ArrayOfPlayer ArrayOfPlayer;
typedef struct _Graph Graph;
typedef struct _List* List;
typedef struct _ListOfList* ListOfList;
typedef struct _ListOfOps* ListOfOps;
typedef struct _ListOfAct* ListOfAct;
typedef struct _ListOfBuilding* ListOfBuilding;
typedef struct _Matrix Matrix;
typedef struct _MesinKata MesinKata;
typedef struct _Point Point;
typedef struct _StackOfAct StackOfAct;
typedef struct _Stack Stack;
typedef struct _Queue Queue;

MesinKata* console;

#include <stdlib.h>
#include "adt/boolean.h"
#include "utils/pcolor.h"
#include "utils/utils.h"
#include "adt/array.h"
#include "adt/graph.h"
#include "adt/list.h"
#include "adt/matrix.h"
#include "adt/mesinkata.h"
#include "adt/point.h"
#include "adt/queue.h"
#include "adt/selector_adt.h"
#include "adt/stack.h"
#include "game.h"
#include "act.h"
#include "building.h"
#include "player.h"
#include "skill.h"
#include "selector.h"

#endif // __headers_h__
