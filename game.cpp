// Lawrence Scroggs -- 11/17/2020 -- CS300:Frupal:Group 4

// This file will hold the games functions/constructors
// /destructors.  
// Designed to create the game functionality that we will
// use in main?

#include "game.h"


Game::Game(string file)
{
  filename = file;
  //window = newwin(128, 128+25, 0, 0);
  initscr();
  window = stdscr;
  map.build(file);
  player.build(file);
}

Game::Game(){}

Game::~Game(){}

Player Game::get_player() {
  return player;
}

int Game::draw() {
  x = COLS;
  y = LINES;

  map.reveal(player.get_x(), player.get_y(), false);
  map.draw(window, cursor_x, cursor_y, player.get_x(), player.get_y());

  menu_start = (x - 25);

  if(COLS < 80 || LINES < 24) {
    printf("\nTerminal too small please enlarge");
    printf("\nmenu start = %i, x = %i", menu_start, x);
    clear();
    endwin();
    exit(-1);
    //return -1;
  }
  else
  {
    menu.draw(menu_start, window);
    player.draw(menu_start, window);
  }

  //wrefresh(window);
  refresh();

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


void Game::move_player(int to_x, int to_y) {
  switch (map.info(to_x, to_y)) {
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
