// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// this will hold the player.h file to better fit the 
// agreed upon file structure

#include "item.h"

class Player: public Entity
{

  public: 
    Player();
    ~Player();
    int get_energy();
    void add_energy(int energy);

    void draw(int menu_start, WINDOW*& win);

  protected:
    int my_whiffles;
    int my_energy;
    Item ** my_items;
    WINDOW* win;
    int ms; //menu_start.

};
