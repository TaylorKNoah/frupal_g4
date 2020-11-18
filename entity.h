// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// This .h file will hold the entity class 


#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;


class entity{

  public:
    entity();
    ~entity();

  private:
    string name;
    int entity_x;
    int entity_y;
   // int * location;
    char type;

};
class obstacle:public entity{

  private:
    int energy_needed;

};
class royal_diamonds:public entity{

  private:
    string something;
    bool game_end;

};
class clue:public entity{

  private:
    String sentence;

};
