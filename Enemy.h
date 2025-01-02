#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <string>
using namespace std;

//The parent class for all of the scary enemies
class Enemy {
 public:
  Enemy(string, int, int, string);
  virtual ~Enemy();
  int Attack();
  virtual int SpecialAttack() = 0;
  string GetName();
  int GetHealth();
  void SetHealth(int);
  int GetDamage();
  string GetDesc();
  friend ostream& operator<<(ostream&, Enemy&);
private:
  string m_name; //Name of the enemy
  int m_health; //Total health for this enemy
  int m_damage; //Max damage for this enemy
  string m_desc; //Description of the enemy
};
#endif
