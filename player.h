// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// this will hold the player.h file to better fit the 
// agreed upon file structure

#include "item.h"

class Player:public entity{

  public: 
    Player();
    ~Player();
    int get_energy();

  private:
    int my_whiffles;
    int my_energy;
    item * my_items;

};
