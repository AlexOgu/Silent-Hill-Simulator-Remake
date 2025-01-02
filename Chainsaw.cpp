#include "Chainsaw.h"
#include <cstdlib> 

Chainsaw::Chainsaw(int damage) : Weapon(damage) {}

int Chainsaw::SpecialAttack() {
    int main_damage = GetDamage(); 
    int min = main_damage / 2;              
    int max = (5 * main_damage) / 2;           

    // Damage done
    int all_damage = (rand() % (max - min + 1)) + min;

    std::cout << "Your chainsaw shreds the enemy!\n";
    std::cout << "You do " << all_damage << " points of damage!" << std::endl;

    return all_damage;
}

string Chainsaw::GetName() {
    return "Chainsaw";
}

