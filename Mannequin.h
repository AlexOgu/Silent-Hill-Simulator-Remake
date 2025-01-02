#ifndef _MANNEQUIN_H_
#define _MANNEQUIN_H_

#include "Enemy.h"

// The Mannequin is a monster that looks like two fashion dummies stitched together, consisting of two pairs of legs.

const int MANNEQUIN_SPECIAL = 2; //Base addition for Mannequin special attack

class Mannequin: public Enemy {
 public:
  Mannequin(string, int, int, string);
  int SpecialAttack();
};
#endif
