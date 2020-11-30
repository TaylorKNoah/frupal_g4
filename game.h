// Carl Knori -- 11/16/2020 -- CS300:Frupal:Group 4
// This .h file will hold the game class

#include "menu.h"

class Game:public Entity{

public:
  Game();
  Game(Window * window);
  // I don't foresee the Game class ever being dynamically allocated but just in
  // case?
  ~Game();

  void update(int key);
  Player get_player();
  int draw(WINDOW * window);
  void move_player(int to_x, int to_y);

private:

  string filename;
  int x;
  int y;
  int menu_start;
  Menu menu;
  Map map(string filename);
  Player player;

};
