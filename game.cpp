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
  keypad(stdscr, TRUE);
  window = stdscr;
  map.build(file);
  player.build(file);
  
  cursor_x = ((COLS-26)/2);
  cursor_y = (LINES/2);
}

Game::Game(){}

Game::~Game(){}

/*
Player Game::get_player() {
  return player;
}
*/

int Game::draw() {
  x = COLS;
  y = LINES;

  
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
    clear();
    map.reveal(player.get_x(), player.get_y(), false);
    menu.draw(menu_start, window);
    player.draw(menu_start, window);
    Entity* temp = map.draw(window, cursor_x, cursor_y, player.get_x(), player.get_y());

    if(temp)
    {

        //check for diamond
        char RD[14] = "Royal Diamond";
        if(strcmp(temp->get_name().data(), RD) == 0)
        {
            //win funcion
            //exit
        }

        //if clue
        Clue* cptr = dynamic_cast <Clue*> (temp);
        if(cptr != NULL)
        {
            //cptr->display_clue();
            string a_clue = cptr->get_clue();
            mvwprintw(window, 6, menu_start+1, "%s", a_clue.data());

        }

        Obstacle* optr = dynamic_cast <Obstacle*> (temp);
        if(optr)
        {
            menu.prompt_interaction(menu_start, window, temp);
            int pointer_fate = player.clear_obstacle(menu_start, window, optr);
            map.clear(player.get_x(), player.get_y(), pointer_fate);
        }

        else
        {
            Item* iptr = dynamic_cast <Item*> (temp);
            menu.prompt_interaction(menu_start, window, temp);
            int pointer_fate = player.pickup_item(menu_start, window, iptr);
            map.clear(player.get_x(), player.get_y(), pointer_fate);
        }
    }
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
      if(move_player(player.get_x(), player.get_y() - 1, player.has_binocs(), player.has_boat()))
        cursor_y++;
    }
    break;

  //Move player left
  case 'a':
    if (player.get_x() != 0) { //If player is not at left of map
      if(move_player(player.get_x() - 1, player.get_y(), player.has_binocs(), player.has_boat()))
        cursor_x++;
    }
    break;

  //Move player down
  case 's':
    if (player.get_y() != 127) { //If player is not at bottom of map
      if(move_player(player.get_x(), player.get_y() + 1, player.has_binocs(), player.has_boat()))
        cursor_y--;
    }
    break;

  //Move player right
  case 'd':
    if (player.get_x() != 127) { //If player is not at right of map
      if(move_player(player.get_x() + 1, player.get_y(), player.has_binocs(), player.has_boat()))
        cursor_x--;
    }
    break;

  //Move cursor up
  case KEY_UP:
    if (cursor_y != 0) { //If cursor is not at the top of the screen
      cursor_y--;
    }
    break;

  //Move cursor left
  case KEY_LEFT:
    if (cursor_x != 0) { //If cursor is not at left of screen
      cursor_x--;
    }
    break;

  //Move cursor down
  case KEY_DOWN:
    if (cursor_y != (y-1)) { //If cursor is not at bottom of screen
      cursor_y++;
    }
    break;

  //Move cursor right
  case KEY_RIGHT:
    if (cursor_x != (x-26)) { //If cursor is not at right of screen
      cursor_x++;
    }
    break;  

    }
}


bool Game::move_player(int to_x, int to_y, bool binocs, bool ship) {
  switch (map.info(to_x, to_y)) {
  case MEADOW_VIS:
    player.add_energy(-1);
    player.set_loc(to_x, to_y);
    map.reveal(player.get_x(), player.get_y(), binocs);
    return true;

  case SWAMP_VIS:
    player.add_energy(-2);
    player.set_loc(to_x, to_y);
    map.reveal(player.get_x(), player.get_y(), binocs);
    return true;

  case WATER_VIS:
    if(ship)
    {
      player.set_loc(to_x, to_y);
      map.reveal(player.get_x(), player.get_y(), binocs);
      return true;
    }
    player.add_energy(-1);
    return false;

  case WALL_VIS:
    player.add_energy(-1);
    return false;

  default:
    break;
  }
  return false;
}

int Game::get_energy()
{
  return player.get_energy();
}
