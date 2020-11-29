// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

//constructor
Player::Player():my_whiffles(1000),my_energy(100),my_items(NULL){

  my_whiffles = 1000;
  my_energy = 100;
  my_items = new Item* [10];
  
  for(int i = 0; i < 10; ++i)
  {
    my_items[i] = NULL;
  }

}

//destructor
Player::~Player(){

  my_whiffles = 0;
  my_energy = 0;

  delete [] my_items;

}

int Player::get_energy() {
  return my_energy;
}

void Player::add_energy(int energy) {
  my_energy += energy;
}
void Player::draw(int menu_start, WINDOW* &game_win)
{
    initscr(); 
    //init if needed
    if(game_win == NULL)
        win = game_win;

    wmvprint(win, 5, menu_start+1, "Energy: ");
    wmvprint(win, 5, menu_start+10, my_energy);

    mvprint(win, 6, menu_start+1, "Whiffles: ");
    mvprint(win, 6, menu_start+12, my_whiffles);


    wrefresh(win);
}

//give negative ints to reduce energy
//positive to inc energy
void Player::change_energy(int change)
{
    my_energy += change;

}
