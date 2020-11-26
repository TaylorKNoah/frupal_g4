// Lawrence Scroggs -- 11/17/2020 -- CS300:Frupal:Group 4

// This file will hold the games functions/constructors
// /destructors.  
// Designed to create the game functionality that we will
// use in main?

#include "game.h"


Game::Game()  {}
Game::~Game() {}


int Game::draw() 
{
  initscr();
  x = COLS;
  y = LINES;
  filename = "map_1";
  menu_start = (x - 25);

  map.draw(x,y, filename);


  if(menu_start < 129) 
  {
    printf("Terminal too small please enlarge");
    return -1;
  }

  else
  {
    menu.draw(menu_start, window);
    player.draw(menu_start, window);
  }

  return 0;
}



void Game::update(int key) 
{
    int* ploc = player.get_loc();

  switch (key) {
  //Move player up
  case 'w':
    if (ploc[1] != 0) { //If player is not at the top of the map
      move_player(ploc[0], (ploc[1] - 1));
    }
    break;

  //Move player left
  case 'a':
    if (ploc[0] != 0) { //If player is not at left of map
      move_player(ploc[0] - 1, ploc[1]); 
    }
    break;

  //Move player down
  case 's':
    if (ploc[1] != 127) { //If player is not at bottom of map
      move_player(ploc[0], ploc[1] + 1);
    }
    break;

  //Move player right
  case 'd':
    if (ploc[0] != 127) { //If player is not at right of map
      move_player(ploc[0] + 1, ploc[1]);
    }
    break;
  }
}



Player Game::get_player() {
  return player;
}



void Game::move_player(int to_x, int to_y) 
{

  switch(map.get_grov_type(to_x, to_y)){
          
    //Need access to map information

     case MEADOW_VIS:
         player.add_energy(-1);
         player.update_loc(to_x, to_y);
         break;

     case SWAMP_VIS:
        player.add_energy(-2);
        player.update_loc(to_x, to_y);
        break;

     case WATER_VIS:
         break;

     case WALL_VIS:
        break;

     default:
        break;
  }

 map.reveal(to_x, to_y);

}
