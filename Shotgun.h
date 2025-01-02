#ifndef _SHOTGUN_H_ 
#define _SHOTGUN_H_ 

#include "Weapon.h"

// The Shotgun is double barrelled gun.
// Chooses a random number between 1 and m_damage once then returns result*2
// If m_damage is 6, it would do two times between 1 and 6 so maybe 4 * 2

class Shotgun: public Weapon {
 public:
  Shotgun(int);
  int SpecialAttack();
  string GetName();
};
#endif
