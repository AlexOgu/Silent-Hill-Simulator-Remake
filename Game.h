#ifndef _GAME_H_ 
#define _GAME_H_ 

//Required classes
#include "Area.h" //Manages area
#include "Hero.h" //Manages hero including name, health, xp, and weapon
#include "Enemy.h" //Manages name, health, damage, and description of enemies
#include "Creeper.h" //Specific type of Enemy
#include "Mandarin.h" //Specific type of Enemy
#include "Mannequin.h" //Specific type of Enemy
#include "Weapon.h" //Manages damage of base attack of weapons
#include "Plank.h" //Specific type of Weapon
#include "Chainsaw.h" //Specific type of Weapon
#include "Shotgun.h" //Specific type of Weapon

//Required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// HERO CONSTANTS
const int HERO_HEALTH = 8; //starting health for hero

//GAME CONSTANTS
const int START_AREA = 0; //starting area number
const char DELIMITER = '|'; //delimiter for input file (map file)
const int COST_IMPROVEMENT = 3; //experience points per 1 increase in damage
const int EXPERIENCE_WIN = 2; //number of experience points earned per win

// ENEMY CONSTANTS
const string CREEPER_NAME = "Creeper"; //creeper name
const string MANDARIN_NAME = "Mandarin"; //mandarin name
const string MANNEQUIN_NAME = "Mannequin"; //mannequin name
const int CREEPER_HEALTH = 10;  //starting health for creeper
const int MANDARIN_HEALTH = 12; //starting health for mandarin
const int MANNEQUIN_HEALTH = 14; //starting health for mannequin
const int CREEPER_DAMAGE = 3; //starting damage for creeper
const int MANDARIN_DAMAGE = 2; //starting damage for mandarin
const int MANNEQUIN_DAMAGE = 1; //starting damage for mannequin
const string CREEPER_DESC = "A large grotesque cockroach is here.";
const string MANDARIN_DESC = "A monster with a female-like figure bound in a garment that resembles a straitjacket and has grotesquely large arms lies here."; //mandarin desc
const string MANNEQUIN_DESC = "A monster that looks like two fashion dummies stitched together, consisting of two pairs of legs stands here.";

class Game {
public:
  Game(string);
  ~Game();
  void LoadMap();
  void HeroCreation();
  void Look();
  void StartGame();
  void Action();
  void RandomEnemy();
  void ImproveWeapon();
  void Move();
  bool Attack();
  void Stats();
  bool ProcessAttack(bool enemyAlive, bool alive);
private:
  vector<Area*> m_myMap; // Vector for holding all areas in game
  Hero* m_myHero; // Hero pointer for Hero (Player)
  int m_curArea; // Current area that player (Hero) is in
  Enemy* m_curEnemy; // Current enemy loaded for current area
  string m_filename; //Name of the input file for the map (holds area objects)
};

#endif
