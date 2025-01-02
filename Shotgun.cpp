#include "Shotgun.h"
#include <cstdlib> 

Shotgun::Shotgun(int damage) : Weapon(damage) {}

int Shotgun::SpecialAttack() {
    int m_attack = GetDamage();
    int multiplier = 2;

    // Total damage of the attacks
    int gun_damage = (rand() % m_attack) + 1; 
    int t_damage = gun_damage * multiplier;

    std::cout << "You fire both barrels of the shotgun!\n";
    std::cout << "You do " << t_damage << " points of damage!" << std::endl;
    return t_damage;
}

string Shotgun::GetName() {
    return "Shotgun";
}
