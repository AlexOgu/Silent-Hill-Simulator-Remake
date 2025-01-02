#include "Weapon.h"

Weapon::Weapon(int damage) : m_damage(damage) {}
Weapon::~Weapon() {}

int Weapon::Attack() {
    return m_damage;
}

int Weapon::GetDamage() {
    return m_damage;
}

void Weapon::ImproveWeapon(int weapon_improved) {m_damage += weapon_improved;}
