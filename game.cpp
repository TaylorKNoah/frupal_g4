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

  map.draw(window, cursor_x, cursor_y, player.get_x(), player.get_y());

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
      move_player(player.entity_x, player.entity_y - 1);
    }
    break;

  //Move player left
  case 'a':
    if (player.entity_x != 0) { //If player is not at left of map
      move_player(player.entity_x - 1, player.entity_y); 
    }
    break;

  //Move player down
  case 's':
    if (player.entity_y != 127) { //If player is not at bottom of map
      move_player(player.entity_x, player.entity_y + 1);
    }
    break;

  //Move player right
  case 'd':
    if (player.entity_x != 127) { //If player is not at right of map
      move_player(player.entity_x + 1, player.entity_y);
    }
    break;
  }
}

Game::Game(std::string file){
  filename = file;
}
Game::~Game(){
  
}

Player Game::get_player() {
  return player();
}

void Game::move_player(int to_x, int to_y) {
  switch (map.map[to_x][to_y]) { //Need access to map information
  case MEADOW_VIS:
    player.add_energy(-1);
    player.entity_x = to_x;
    player.entity_y = to_y;
    map.reveal(player.entity_x, player.entity_y);
    break;

  case SWAMP_VIS:
    player.add_energy(-2);
    player.entity_x = to_x;
    player.entity_y = to_y;
    map.reveal(player.entity_x, player.entity_y);
    break;

  case WATER_VIS:
    break;

  case WALL_VIS:
    break;
}
