#ifndef _PLANK_H_
#define _PLANK_H_

#include "Weapon.h"

// The wooden plank is a basic piece of wood used to bash enemies.
// It's special attack bashes and does between 1 and m_damage (twice)
// For example, if m_damage is 4 then it would could do 2 and 4 for a total of 6

class Plank: public Weapon {
 public:
  Plank(int);
  int SpecialAttack();
  string GetName();
};
#endif
