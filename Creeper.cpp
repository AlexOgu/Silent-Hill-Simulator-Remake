#include "Creeper.h"
#include <iostream>

Creeper::Creeper(string name, int health, int damage, string desc)
  : Enemy(name, health, damage, desc) {}

int Creeper::SpecialAttack() {
  std::cout << "A " << GetName() << " takes a large bite out of you!\n"; 
  std::cout << "You take " << CREEPER_SPECIAL << " points of damage" << std::endl;
  return CREEPER_SPECIAL;
}
