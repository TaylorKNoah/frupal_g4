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

void Game::update(int key) {
  switch (key) {
  //Move player up
  case 'w':
    if (player.entity_y != 0) { //If player is not at the top of the map
      
    }
    break;

  //Move player left
  case 'a':
    if (player.entity_x != 0) { //If player is not at left of map
      
    }
    break;

  //Move player down
  case 's':
    if (player.entity_y != 127) { //If player is not at bottom of map
      
    }
    break;

  //Move player right
  case 'd':
    if (player.entity_x != 127) { //If player is not at right of map
      
    }
    break;
  }
}

Game::Game(){

}
Game::~Game(){
  
}
