#include "Enemy.h"

Enemy::Enemy(string name, int hp, int damage, string desc)
    : m_name(name),
      m_health(hp),
      m_damage(damage),
      m_desc(desc) {}

Enemy::~Enemy() {}
ostream& operator<<(ostream& os, Enemy& enemy) {
  os << "Enemy Name: " << enemy.m_name << endl;
  os << "Health: " << enemy.m_health << endl;
  os << "Damage: " << enemy.m_damage << endl;
  os << "Description: " << enemy.m_desc << endl;
  return os;
}

int Enemy::Attack() {
  cout << m_name << " attacks! " << endl;
  return m_damage;
}

string Enemy::GetName() {
  return m_name;
}

int Enemy::GetHealth() {
  return m_health;
}

void Enemy::SetHealth(int health) {
  m_health = health;
}

int Enemy::GetDamage() {
  return m_damage;
}

string Enemy::GetDesc() {
  return m_desc;
}


