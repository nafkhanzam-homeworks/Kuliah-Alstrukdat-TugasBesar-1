#if !defined(__selector_h__)
#define __selector_h__

#define target(P) (P)->target
#define value(P) (P)->value
#define type(P) (P)->type
#define position(P) (P)->position
#define armyCount(P) (P)->armyCount
#define level(P) (P)->level
#define owner(P) (P)->owner
#define hasAttacked(P) (P)->hasAttacked
#define actStack(P) (P)->actStack
#define map(P) (P)->map
#define buildingList(P) (P)->buildingList
#define buildingGraph(P) (P)->buildingGraph
#define players(P) (P)->players
#define playersi(P, i) tabi(players((P)), (i))
#define turn(P) (P)->turn
#define isExiting(P) (P)->isExiting
#define extraTurn(P) (P)->extraTurn
#define attackUp(P) (P)->attackUp
#define criticalHit(P) (P)->criticalHit
#define shieldTurn(P) (P)->shieldTurn
#define config(P) (P)->config
#define skillQueue(P) (P)->skillQueue
#define N(P) (P)->N
#define ROW(P) (P)->ROW
#define COL(P) (P)->COL

#endif // __selector_h__
