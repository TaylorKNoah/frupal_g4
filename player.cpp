// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

Player::Player() 
{
  my_items = NULL;
  has_binoculars = false;
  has_ship = false;
  win = stdscr;
}


//constructor
void Player::build(string file)
{
  ifstream in;

  in.open(file);

  char locx[4];
  char locy[4];

  in.get(locx, 4, ',');
  in.ignore(100, ',');
  in.get(locy, 4, ':');
  in.ignore(100, ':');

  in.clear();
  in.close();

  int x = stoi(locx);
  int y = stoi(locy);

  set_loc(x, y);


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

  if(my_items)
  {
    for(int i=0; i<10; ++i)
    {
      if(my_items[i])
        delete my_items[i];
    }
    delete [] my_items;
  } 
}


int Player::get_energy()
{
  return my_energy;
}


void Player::add_energy(int energy) 
{
  my_energy += energy;
}


void Player::draw(int menu_start, WINDOW* game_win)
{

    string energy = to_string(my_energy);
    string whiffles = to_string(my_whiffles);

    mvwprintw(game_win, 5, menu_start+1, " Energy: ");
    mvwprintw(game_win, 5, menu_start+12, energy.data());

    mvwprintw(game_win, 6, menu_start+1, " Whiffles: ");
    mvwprintw(game_win, 6, menu_start+12, whiffles.data());

    //wrefresh(win);
}


//Displays players inventory (axe and hammer counts)
//  First clears the menu of WASD controls
//  Then displays inventory in that area of the menu
void Player::display_inventory(int menu_start, WINDOW* &game_win)
{
    int num_axe = 0;
    int num_hammer = 0;
    char axe_cmp[4] = "Axe";
    char hammer_cmp[7] = "Hammer";

    //Get item counts
    for(int i=0; i<10; ++i)
    {
        if(my_items[i]->compare_name(axe_cmp))
            num_axe += my_items[i]->get_is_owned();

        else if(my_items[i]->compare_name(hammer_cmp))
            num_hammer += my_items[i]->get_is_owned();
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
    sprintf(hammer+j, "%d", num_hammer);

    //Display inventory
    mvwprintw(win, 12, menu_start+1, "Inventory");
    mvwprintw(win, 13, menu_start+1, axe);
    mvwprintw(win, 14, menu_start+1, hammer);
}
