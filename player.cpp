// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

//constructor
Player::Player()
{

  my_whiffles = 1000;
  my_energy = 100;
  my_items = new Item* [10];
  
  for(int i = 0; i < 10; ++i)
  {
    my_items[i] = NULL;
  }

}

//destructor
Player::~Player()
{

  my_whiffles = 0;
  my_energy = 0;

  for(int i=0; i<10; ++i)
  {
    if(my_items[i])
      delete my_items[i];
  }
  delete [] my_items;

}

int Player::get_energy()
{
  return my_energy;
}

void Player::add_energy(int energy) 
{
  my_energy += energy;
}

void Player::draw(int menu_start, WINDOW* &game_win)
{
    initscr(); 
    //init if needed
    if(game_win == NULL)
        win = game_win;

    string energy = to_string(my_energy);
    string whiffles = to_string(my_whiffles);

    mvwprintw(win, 5, menu_start+1, "Energy: ");
    mvwprintw(win, 5, menu_start+10, energy.data());

    mvwprintw(win, 6, menu_start+1, "Whiffles: ");
    mvwprintw(win, 6, menu_start+12, whiffles.data());

    wrefresh(win);
}


//Displays players inventory (axe and hammer counts)
//  First clears the menu of WASD controls
//  Then displays inventory in that area of the menu
void Player::display_inventory(int menu_start, WINDOW* &game_win)
{
    int num_axe = 0;
    int num_ham = 0;

    //Get item counts
    for(int i=0; i<10; ++i)
    {
        if(my_items[i]->get_name() == "Axe")
            num_axe += my_items[i]->get_isowned();

        else if(my_items[i]->get_name() == "Hammer")
            num_hammer += my_items[i]->get_isowned();
    }

    //clear WASD
    mvwprintw(win, 12, menu_start+1, "          ");
    mvwprintw(win, 13, menu_start+1, "          ");
    mvwprintw(win, 14, menu_start+1, "          ");
    mvwprintw(win, 15, menu_start+1, "          ");
    mvwprintw(win, 16, menu_start+1, "          ");

    //construct char* for prints
    char axe[16];
    int j = sprintf(axe, "%s", "Axes: ");
    sprintf(axe+j, "%d", num_axe);

    char hammer[16];
    j = sprintf(hammer, "%s", "Hammers: ");
    sprintf(hammer+j, "%d", num_ham);

    //Display inventory
    mvwprintw(win, 12, menu_start+1, "Inventory");
    mvwprintw(win, 13, menu_start+1, axe);
    mvwprintw(win, 14, menu_start+1, hammer);
}
