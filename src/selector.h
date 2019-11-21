#if !defined(__selector_h__)
#define __selector_h__

#define target(P) (P)->target
#define value(P) (P)->value
#define type(P) (P)->type
#define position(P) (P)->position
#define armyCount(P) (P)->armyCount
#define level(P) (P)->level
#define shieldCount(P) (P)->shieldCount
#define owner(P) (P)->owner
#define actStack(P) (P)->actStack
#define map(P) (P)->map
#define buildingList(P) (P)->buildingList
#define buildingGraph(P) (P)->buildingGraph
#define players(P) (P)->players
#define playersi(P, i) (P)->players[i]
#define turn(P) (P)->turn
#define isExiting(P) (P)->isExiting
#define extraTurn(P) (P)->extraTurn
#define attackUp(P) (P)->attackUp
#define criticalHit(P) (P)->criticalHit
#define shieldTurn(P) (P)->shieldTurn

#endif // __selector_h__
