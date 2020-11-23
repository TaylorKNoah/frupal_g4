// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

//constructor
Player::Player():my_whiffles(1000),my_energy(100),my_items(NULL){}

//destructor
Player::~Player(){

  my_whiffles = 0;
  my_energy = 0;

  while(my_items->next != NULL)
  {
    items * temp = my_items;
    my_items = my_items->next;
    delete temp;
  }

}

int Player::get_energy() {
  return my_energy();
}
