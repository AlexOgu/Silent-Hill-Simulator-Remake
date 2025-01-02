#ifndef _CREEPER_H_
#define _CREEPER_H_

#include "Enemy.h"

//Creepers are an extremely large and aggressive cockroach.
//These critters will actively seek you out if you get close enough.

const int CREEPER_SPECIAL = 4; //Base damage for Creeper special attack

class Creeper: public Enemy {
 public:
  Creeper(string, int, int, string);
  int SpecialAttack();
};
#endif
