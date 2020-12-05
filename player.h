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
    void build(string file);
    void draw(int menu_start, WINDOW* win);
    void display_inventory(int menu_start, WINDOW* &win);
    bool clear_obstacle(int menu_start, WINDOW* &win, Obstacle* optr);
    bool has_item(char* to_cmp);

  protected:
    int my_whiffles;
    int my_energy;
    Item ** my_items;
    WINDOW* win;
    int ms; //menu_start.

};
