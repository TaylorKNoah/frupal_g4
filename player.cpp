// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// Taylor Noah--11/23/2020, 11/25/2020 --
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

//constructor
Player::Player():my_whiffles(1000),my_energy(100),my_items(NULL){}

//destructor
Player::~Player()
{

  my_whiffles = 0;
  my_energy = 0;
  ploc[0] = 0;
  ploc[1] = 0;

  /*
  while(my_items->next != NULL)
  {
    items * temp = my_items;
    my_items = my_items->next;
    delete temp;
  }
  */

  int i=0;
  while(my_items[i])
  {
      delete my_items[i];
      my_items[i] = NULL;
      ++i;
  }
}

int* Player::get_loc()
{
    return ploc;
}

void Player::update_loc(int x, int y)
{
    ploc[0] = x;
    ploc[1] = y;
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
    //init if needed
    if(game_win == NULL)
        win = game_win;

    string energy;
    energy = to_string(my_energy);

    string whiffles;
    whiffles = to_string(my_whiffles);

    mvwprintw(win, 5, menu_start+1, "Energy: ");
    mvwprintw(win, 5, menu_start+10, energy.data());

    mvwprintw(win, 6, menu_start+1, "Whiffles: ");
    mvwprintw(win, 6, menu_start+12, whiffles.data());


    wrefresh(win);
}

