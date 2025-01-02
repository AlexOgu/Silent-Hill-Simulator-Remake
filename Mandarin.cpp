#include "Mandarin.h"
#include <iostream>

Mandarin::Mandarin(string name, int health, int damage, string desc)
  : Enemy(name, health, damage, desc) {}

int Mandarin::SpecialAttack() {
  std::cout << "A " << GetName() << " hammers you with their large arms!\n";
  std::cout << "You take " << MANDARIN_SPECIAL << " points of damage" << std::endl;
  return MANDARIN_SPECIAL;
}
