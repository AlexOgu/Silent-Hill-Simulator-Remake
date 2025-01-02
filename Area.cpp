#include "Area.h" 
#include <iostream>

const int rev = -1;

Area::Area(int id, string name, string desc, int north, int east, int south, int west)
    : m_ID(id), m_name(name), m_desc(desc) {m_direction[n] = north;  m_direction[e] = east;   
    m_direction[s] = south; m_direction[w] = west;}

string Area::GetName() {
    return m_name;
}

int Area::GetID() {
    return m_ID;
}

string Area::GetDesc() {
    return m_desc;
}

int Area::CheckDirection(char myDirection) {
    int maindirection;
    while (true) {
        switch (myDirection) {
            case 'n': 
            case 'N':
                maindirection = n;
                break;
            case 'e': 
            case 'E':
                maindirection = e;
                break;
            case 's': 
            case 'S':
                maindirection = s;
                break;
            case 'w': 
            case 'W':
                maindirection = w;
                break;
            default:
                std::cout << "Which direction? (N E S W) " << std::endl;
                std::cin >> myDirection;
                continue;
        }

        // This will check if the exit is possible
        if (m_direction[maindirection] != rev) {
            return m_direction[maindirection];
        } else {
            std::cout << "Which direction? (N E S W) " << std::endl;
            std::cin >> myDirection;
        }
    }
}

void Area::PrintArea() {
    std::cout << "\n" 
              << m_name << "\n"
              << m_desc << "\n"
              << "Possible Exits: ";

    if (m_direction[n] != rev) {
        std::cout << "N" << std::endl;
    }
    if (m_direction[e] != rev) {
        std::cout << "E" << std::endl;
    }
    if (m_direction[s] != rev) {
        std::cout << "S" << std::endl;
    }
    if (m_direction[w] != rev) {
        std::cout << "W" << std::endl;
    }
    
    std::cout << std::endl;  
}
