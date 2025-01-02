#ifndef AREA_H 
#define AREA_H 
#include <iostream>
#include <string>
using namespace std;

//Enum defining the directions in array n/N = 0, e/E = 1, s/S = 2, w/W = 3
enum direction{n=0,N=0,e=1,E=1,s=2,S=2,w=3,W=3};

class Area {
 public:
  Area(int, string, string, int, int, int, int);
  string GetName();
  int GetID();
  string GetDesc();
  int CheckDirection(char myDirection);
  void PrintArea();
 private:
  int m_ID; //Unique int for area number
  string m_name; //Name of area
  string m_desc; //Description of area
  int m_direction[4]; //Array holding area to north, east, south, west (-1 if no exit)
};
#endif 
