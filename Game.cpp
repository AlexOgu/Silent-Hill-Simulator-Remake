#include "Game.h"
#include <sstream>

Game::Game(string filename) : m_myMap(), 
    m_myHero(nullptr), 
    m_curArea(START_AREA), 
    m_curEnemy(nullptr), 
    m_filename(filename) {LoadMap();}

Game::~Game() {
    if (m_myHero != nullptr) {
        delete m_myHero;
    }
    if (m_curEnemy != nullptr) {
        delete m_curEnemy;
    }
    for (unsigned int i = 0; i < m_myMap.size(); i++) {
        delete m_myMap[i];
    }
}

void Game::LoadMap() {
    ifstream inputFile(m_filename);
    if (!inputFile) {
        cerr << "File can't open" << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line); // Use stringstream to parse the line
        string idStr, name, main_description, north_s, east_s, south_s, west_s;

        getline(ss, idStr, DELIMITER);
        getline(ss, name, DELIMITER);
        getline(ss, main_description, DELIMITER);
        getline(ss, north_s, DELIMITER);
        getline(ss, east_s, DELIMITER);
        getline(ss, south_s, DELIMITER);
        getline(ss, west_s, DELIMITER);

        // Convert strings to integers
        int id = stoi(idStr);
        int north = stoi(north_s);
        int east = stoi(east_s);
        int south = stoi(south_s);
        int west = stoi(west_s);

        // Create a new Area object and add it to the map
        Area* newArea = new Area(id, name, main_description, north, east, south, west);
        m_myMap.push_back(newArea);
    }
    inputFile.close();
}

void Game::HeroCreation() {
    string main_hero;
    cout << "Silent Hill 2 Remake" << endl;
    cout << "Hero Name: ";
    getline(cin, main_hero);
    m_myHero = new Hero(main_hero, HERO_HEALTH);
}

void Game::Look() {
    m_myMap[m_curArea]->PrintArea();
    if (m_curEnemy != nullptr) {
        cout << m_curEnemy->GetDesc() << endl;
    } else {
        cout << "It is peaceful here." << endl;
    }
}

void Game::StartGame() {
    LoadMap();
    HeroCreation();
    RandomEnemy();
    Look();
    Action();
}

void Game::Action() {
    int choice;
    bool playing = true;
    while (playing && m_myHero->GetHealth() > 0) {

        // This will display the main menu
        cout << "What would you like to do?" << endl;
        cout << "1. Look" << endl;
        cout << "2. Move" << endl;
        cout << "3. Attack Enemy" << endl;
        cout << "4. Improve Weapon" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                Look();
                break;
            case 2:
                Move();
                break;
            case 3:
                if (m_curEnemy != nullptr) {
                    if (!Attack()) {
                        playing = false; 
                    }
                } else {
                    cout << "There is nothing to attack here." << endl;
                }
                break;
            case 4:
                ImproveWeapon();
                break;
            case 5:
                Stats();
                break;
            case 6:
                playing = false;
                cout << "Thank you for playing Silent Hill 2 Remake" <<endl;
                break;
            default:
                cout << "" << endl;
        }
    }
}

void Game::RandomEnemy() {
    if (m_curEnemy != nullptr) {
        delete m_curEnemy;
        m_curEnemy = nullptr;
    }

    // This will generate a random number between one and three
    int random_number = rand() % 4; 
    switch (random_number) {
        case 0:
            m_curEnemy = new Creeper(CREEPER_NAME, CREEPER_HEALTH, CREEPER_DAMAGE, CREEPER_DESC);
            break;
        case 1:
            m_curEnemy = new Mandarin(MANDARIN_NAME, MANDARIN_HEALTH, MANDARIN_DAMAGE, MANDARIN_DESC);
            break;
        case 2:
            m_curEnemy = new Mannequin(MANNEQUIN_NAME, MANNEQUIN_HEALTH, MANNEQUIN_DAMAGE, MANNEQUIN_DESC);
            break;
        case 3:
            m_curEnemy = nullptr; 
            break;
    }
}

void Game::ImproveWeapon() {
    if (m_myHero->GetExperience() >= COST_IMPROVEMENT) {
        m_myHero->ImproveWeapon(COST_IMPROVEMENT);
    } else {
        cout << "You need more experience to upgrade the " << m_myHero->GetWeaponName() << endl;
    }
}

void Game::Move() {
    char direction;

    //Directs to new area
    cout << "Which direction? (N E S W) " <<endl;
    cin >> direction;
    int next_area = m_myMap[m_curArea]->CheckDirection(direction);
    if (next_area != -1) {
        m_curArea = next_area;
        RandomEnemy();
        Look();        
    } else {
        cout << "You cannot move in that direction." << endl;
    }
}

bool Game::Attack() {
    bool enemyAlive = true;
    bool heroAlive = true;
    while (enemyAlive && heroAlive) {
        int heroDamage = 0;
        int attackChoice = 0;

        // The attack menu is displayed
        while (attackChoice != 1 && attackChoice != 2) {
            cout << "1. Punch Enemy\n";
            cout << "2. Use " << m_myHero->GetWeaponName() << endl;
            cin >> attackChoice;
            if (attackChoice == 1) {

                // This will reset damage to 3
                heroDamage = WEAPON_BASE;
                cout << "You punch and do " << heroDamage << " to the enemy." << endl;
            } else if (attackChoice == 2) {
                heroDamage = m_myHero->SpecialAttack();
            } else {
                cout << "invalid" << endl;
            }
        }
        m_curEnemy->SetHealth(m_curEnemy->GetHealth() - heroDamage);
        if (m_curEnemy->GetHealth() <= 0) {
            enemyAlive = false;
            continue;
        }

        // This gives the enemy a 25% chance of a special
        int enemyDamage = 0;
        if (rand() % 4 == 0) {
            enemyDamage = m_curEnemy->SpecialAttack();
        } else {
            enemyDamage = m_curEnemy->Attack();
        }
        m_myHero->SetHealth(m_myHero->GetHealth() - enemyDamage);
        if (m_myHero->GetHealth() <= 0) {
            heroAlive = false;
            continue;
        }

        // This displays enemy and hero's data
        cout << m_myHero->GetName() << " Health: " << m_myHero->GetHealth() << endl;
        cout << m_curEnemy->GetName() << ": Health: " << m_curEnemy->GetHealth() << " Damage: " << enemyDamage << endl;
    }
    return ProcessAttack(enemyAlive, heroAlive);
}

void Game::Stats() {
    cout << *m_myHero << endl;
}

bool Game::ProcessAttack(bool enemyAlive, bool heroAlive) {
    if (!enemyAlive && heroAlive) {
        cout << "You have defeated the " << m_curEnemy->GetName() << "." << endl;
        cout << "You have earned " << EXPERIENCE_WIN <<" experience points" << endl;
        m_myHero->SetExperience(m_myHero->GetExperience() + EXPERIENCE_WIN);

        // the enemy is no longer in the area
        m_curEnemy = nullptr; 
        return true;
    } else if (!heroAlive && enemyAlive) {
        cout << "You have been defeated. Try again!" << endl;
        return false;
    } else {
        cout << "Both you and the enemy have fallen..." << endl;
        return false;
    }
}