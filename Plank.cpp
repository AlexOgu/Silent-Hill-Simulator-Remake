#include "Plank.h"
#include <cstdlib> 

Plank::Plank(int damage) : Weapon(damage) {}

int Plank::SpecialAttack() {
    int main_attack = GetDamage();
    int takeattack = (rand() % main_attack) + 1;
    
    // Total damage of the attacks
    int damage_total = takeattack;
    int attackadd = (rand() % main_attack) + 1;
    damage_total += attackadd;

    std::cout << "You bash twice with your plank!\n";
    std::cout << "You do " << damage_total << " points of damage!" << std::endl;
    return damage_total;
}

string Plank::GetName() {
    return "Plank";
}

