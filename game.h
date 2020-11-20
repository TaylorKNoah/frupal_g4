// Carl Knori -- 11/16/2020 -- CS300:Frupal:Group 4
// This .h file will hold the game class

#include "menu.h"

class Game{

public:
  Game();
  // I don't foresee the Game class ever being dynamically allocated but just in
  // case?
  ~Game();

private:

  String filename;
  int x;
  int y;
  int menu_start;
  Map map;
  Menu menu;
  Player player;

};
