// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// this will hold the player.h file to better fit the 
// agreed upon file structure

#include "item.h"

class Player:public Entity{

  public: 
    Player();
    ~Player();
    int get_energy();
    int* get_loc();
    void update_loc(int x, int y);
    void add_energy(int energy);
    void draw(int menu_start, WINDOW* &win);

  private:
    int my_whiffles;
    int my_energy;
    int ploc[2];
    Item ** my_items;
    WINDOW* win;

};
