#if !defined(__skill_h__)
#define __skill_h__

#include "headers.h"

#define MAX_QUEUE 10

int Skill_getType(char* v);
char* Skill_getName(int v);
char* Skill_getAcronym(int v);
void Skill_instantUpgrade(Game* p);
void Skill_shield(Game* p);
void Skill_extraTurn(Game* p);
void Skill_attackUp(Game* p);
void Skill_criticalHit(Game* p);
void Skill_instantReinforcement(Game* p);
void Skill_barrage(Game* p);
void Skill_do(Game* p, int v);

#endif // __skill_h__
