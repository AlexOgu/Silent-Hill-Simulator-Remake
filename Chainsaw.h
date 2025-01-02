#ifndef _CHAINSAW_H_ 
#define _CHAINSAW_H_ 

#include "Weapon.h"

class Chainsaw: public Weapon {
 public:
  Chainsaw(int);
  int SpecialAttack();
  string GetName();
};
#endif
