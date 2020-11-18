// Lawrence Scroggs -- 11/17/2020 -- CS300:Frupal:Group 4
// this will hold the player.h file to better fit the 
// agreed upon file structure

#include "item.h"

class player:public entity{

  public: 
    player();
    ~player();

  private:
    int my_whiffles;
    int my_energy;
    item * my_items;

};
