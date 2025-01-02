#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <iostream>
#include <string>
using namespace std;

class Weapon {
 public:
  Weapon(int);
  virtual ~Weapon();
  int Attack();
  int GetDamage();
  void ImproveWeapon(int);
  virtual int SpecialAttack() = 0;
  virtual string GetName() = 0;
private:
  int m_damage; //Damage that the base attack does
};
#endif
