// Lawrence Scroggs -- 11/17/2020 -- CS300:Frupal:Group 4

// This file will hold the games functions/constructors
// /destructors.  
// Designed to create the game functionality that we will
// use in main?

#include "game.h"

int Game::draw() {
  initscr();
  x = COLS;
  y = LINES;
  filename = "map_1";

  map.draw(x,y,filename);

  menu_start = (x - 25);

  if(menu_start < 129) {
    printf("Terminal too small please enlarge");
    return -1;
  }
  else
    menu.draw(menu_start);

  return 0;
}


Game::Game(){

}
Game::~Game(){
  
}
