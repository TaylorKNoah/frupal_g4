// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// This .h file will hold the entity class 


#include <iostream>
//#include <cstring>
#include <string>
#include <cstdlib>
#include <ncurses.h> 

using namespace std;


class Entity{

  public:
    Entity();
    ~Entity();

  private:
    string name;
    int entity_x;
    int entity_y;
   // int * location;
    char type;

};
class Obstacle:public Entity{

  private:
    int energy_needed;

};
class Royal_diamonds:public Entity{

  private:
    string something;
    bool game_end;

};
class Clue:public Entity{

  private:
    string sentence;

};
