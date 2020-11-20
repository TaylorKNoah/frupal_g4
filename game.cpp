// Lawrence Scroggs -- 11/17/2020 -- CS300:Frupal:Group 4

// This file will hold the games functions/constructors
// /destructors.  
// Designed to create the game functionality that we will
// use in main?

#include "game.h"

game::game():map(),menu(),player(){

  initscr();
  x = 128;
  y = 128;

  cells = new int* [x];
  for(int i = 0; i < x; ++i)
    cells[i] = new int[y];


}
game::~game(){

  //delete array
  for(int i = 0; i < x; ++i)
    delete [] cells[i];

  delete [] cells;

  
}
