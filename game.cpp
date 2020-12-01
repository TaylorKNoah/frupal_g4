// Lawrence Scroggs -- 11/17/2020 -- CS300:Frupal:Group 4

// This file will hold the games functions/constructors
// /destructors.  
// Designed to create the game functionality that we will
// use in main?

#include "game.h"

int Game::draw(WINDOW *& window) {
  initscr();
  x = COLS;
  y = LINES;
<<<<<<< HEAD
  filename = "map1.txt";


  Map map(filename);
  map.draw(x,y,x,y,x,y);
=======

  map.draw(window, cursor_x, cursor_y, player.get_x(), player.get_y());
>>>>>>> 53a4dd6049b159a4032427f08715e835dea61248

  menu_start = (x - 25);

  if(menu_start < 129) {
    printf("Terminal too small please enlarge");
    return -1;
  }
  else
<<<<<<< HEAD
  {
    window = new WINDOW; 
    menu.draw(menu_start,window);
  }
=======
    menu.draw(menu_start, window);
>>>>>>> 53a4dd6049b159a4032427f08715e835dea61248

  return 0;
}

void Game::update(int key) {
  switch (key) {
  //Move player up
  case 'w':
    if (player.get_y() != 0) { //If player is not at the top of the map
      move_player(player.get_x(), player.get_y() - 1);
    }
    break;

  //Move player left
  case 'a':
    if (player.get_x() != 0) { //If player is not at left of map
      move_player(player.get_x() - 1, player.get_y()); 
    }
    break;

  //Move player down
  case 's':
    if (player.get_y() != 127) { //If player is not at bottom of map
      move_player(player.get_x(), player.get_y() + 1);
    }
    break;

  //Move player right
  case 'd':
    if (player.get_x() != 127) { //If player is not at right of map
      move_player(player.get_x() + 1, player.get_y());
    }
    break;
  }
}

<<<<<<< HEAD
Game::Game(WINDOW * window){
=======
Game::Game(string file){
  filename = file;
}

Game::Game(){
>>>>>>> 53a4dd6049b159a4032427f08715e835dea61248

}

Game::~Game(){
  
}

Player Game::get_player() {
  return player;
}

void Game::move_player(int to_x, int to_y) {
<<<<<<< HEAD
  switch (map[to_x][to_y]) { //Need access to map information
=======
  switch (map.info(to_x, to_y)) {
>>>>>>> 53a4dd6049b159a4032427f08715e835dea61248
  case MEADOW_VIS:
    player.add_energy(-1);
    player.set_loc(to_x, to_y);
    map.reveal(player.get_x(), player.get_y(), false);
    break;

  case SWAMP_VIS:
    player.add_energy(-2);
    player.set_loc(to_x, to_y);
    map.reveal(player.get_x(), player.get_y(), false);
    break;

  case WATER_VIS:
    break;

  case WALL_VIS:
    break;

  default:
    break;
  }
}
