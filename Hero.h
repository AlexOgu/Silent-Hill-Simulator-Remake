#ifndef _HERO_H_
#define _HERO_H_
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Plank.h"
#include "Shotgun.h"
#include "Chainsaw.h"
using namespace std;

const int WEAPON_BASE = 3; //Used for all normal attacks

class Hero {
 public:
  Hero(string,int);
  ~Hero();
  int Attack();
  string GetName();
  void SetName(string);
  int GetHealth();
  void SetHealth(int);
  int GetExperience();
  void SetExperience(int);
  void RandomWeapon();
  void ImproveWeapon(int);
  int SpecialAttack();
  string GetWeaponName();
  friend ostream& operator<<(ostream&, Hero&);
private:
  string m_name; //Name of the hero
  int m_health; //Total health for this hero
  int m_experience; //Experience points held by the hero
  Weapon* m_weapon; //Weapon that the hero is wielding (used for damage)
};
#endif
