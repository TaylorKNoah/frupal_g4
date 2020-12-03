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
    void display_inventory(int menu_start, WINDOW* &win);
    void draw(int menu_start, WINDOW* win);
    void reset_location();
    void set_previous_location(int x, int y);

  private:
    int my_whiffles;
    int my_energy;
    bool has_binoculars;
    bool has_ship;
    
    Item ** my_items;
    WINDOW* win;

    int player_previous_x;
    int player_previous_y;

    
};
