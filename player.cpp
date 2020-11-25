// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

//constructor
player::player():my_whiffles(1000),my_energy(100),my_items(NULL){}

//destructor
player::~player(){

  my_whiffles = 0;
  my_energy = 0;

  while(my_items->next != NULL)
  {
    items * temp = my_items;
    my_items = my_items->next;
    delete temp;
  }

}

int player::get_energy() {
  return my_energy();
}

void player::add_energy(int energy) {
  my_energy += energy;
}
void player::draw(int menu_start, WINDOW* &game_win)
{
    //init if needed
    if(game_win = NULL)
        win = game_win;

    mvprint(win, 5, menu_start+1, "Energy: ");
    mvprint(win, 5, menu_start+10, my_energy);

    mvprint(win, 6, menu_start+1, "Whiffles: ");
    mvprint(win, 6, menu_start+12, my_whiffles);


    wrefresh(win);
}

//give negative ints to reduce energy
//positive to inc energy
void player::change_energy(int change)
{
    my_energy += loss;

}
