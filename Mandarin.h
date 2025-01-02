#ifndef _MANDARIN_H_
#define _MANDARIN_H_

#include "Enemy.h"

/* Mandarins are monsters with a female-like figure bound in a garment that resembles a straightjacket and has grotesquely large arms.
*/

const int MANDARIN_SPECIAL = 3; //Base for Mandarin special attack

class Mandarin: public Enemy {
 public:
  Mandarin(string, int, int, string);
  int SpecialAttack();
};
#endif
