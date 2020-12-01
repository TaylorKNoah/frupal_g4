// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

Player::Player() {}


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
