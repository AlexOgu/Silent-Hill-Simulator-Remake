#include "Mannequin.h"
#include <iostream>

Mannequin::Mannequin(string name, int health, int damage, string desc)
  : Enemy(name, health, damage, desc) {}

int Mannequin::SpecialAttack() {
  std::cout << "A " << GetName() << " smashes with their kick!\n";
  std::cout << "You take " << MANNEQUIN_SPECIAL << " points of damage" << std::endl;
  return MANNEQUIN_SPECIAL;
}

