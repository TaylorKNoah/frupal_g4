// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// This .h file will hold the entity class 


#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;


class entity{

  string name;
  int * location;
  char type;

};
class player:public entity{

  int my_whiffles;
  int my_energy;
  item * my_items;

}
class object:public entity{

  int energy_needed;

};
class royal_diamonds:public entity{

  string something;
  bool game_end;

};
class item:public entity{

  int whiffles;
  int owned;

}
class clue:public entity{

  String sentence;

};
