#include "Hero.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>  

Hero::Hero(string name, int health) : m_name(name), 
    m_health(health), 
    m_experience(0), 
    m_weapon(nullptr) {srand(time(0)); RandomWeapon();}

Hero::~Hero() {
    if (m_weapon != nullptr) {
        delete m_weapon;
        m_weapon = nullptr;
    }
}

int Hero::Attack() {
    if (m_weapon != nullptr) {

        // Makes the damage 3 if its not of the weapons
        string name_of_weapon = m_weapon->GetName();
        if (name_of_weapon != "Plank" && name_of_weapon != "Chainsaw" && name_of_weapon != "Shotgun") {
            return WEAPON_BASE;
        }
        return m_weapon->Attack();
    }
    return 0;
}

string Hero::GetName() {
    return m_name;
}

void Hero::SetName(string name) {
    m_name = name;
}

int Hero::GetHealth() {
    return m_health;
}

void Hero::SetHealth(int health) {
    m_health = health;
}

int Hero::GetExperience() {
    return m_experience;
}

void Hero::SetExperience(int experience) {
    m_experience = experience;
}

void Hero::RandomWeapon() {

    //Random number generator
    int randomChoice = rand() % 3; 
    if (m_weapon != nullptr) {
        delete m_weapon; 
    }
    switch (randomChoice) {
        case 0:
            m_weapon = new Plank(WEAPON_BASE);
            std::cout << "You start with a Plank!" << std::endl;
            break;
        case 1:
            m_weapon = new Chainsaw(WEAPON_BASE);
            std::cout << "You start with a Chainsaw!" << std::endl;
            break;
        case 2:
            m_weapon = new Shotgun(WEAPON_BASE);
            std::cout << "You start with a Shotgun!" << std::endl;
            break;
    }
}

void Hero::ImproveWeapon(int experience_points) {
    if (m_weapon == nullptr) {
        return;
    }
    if (m_experience < experience_points) {
        return;
    }

    // Checks to see if weapon can be upgraded
    int upgrades = m_experience / experience_points;
    if (upgrades > 0) {
        m_weapon->ImproveWeapon(upgrades);

        //Removes experience as weapon is upgraded
        m_experience -= upgrades * experience_points;
    }
}


int Hero::SpecialAttack() {
    if (m_weapon != nullptr) {
        return m_weapon->SpecialAttack();
    }
    return 0;
}

string Hero::GetWeaponName() {
    if (m_weapon != nullptr) {
        return m_weapon->GetName();
    }
    return "none";
}

ostream& operator<<(ostream& os, Hero& hero) {
    os << "Name: " << hero.m_name <<endl;
    os << "HP: " << hero.m_health <<endl;
    os << "Experience points: " << hero.m_experience << std::endl;
    return os;
}
