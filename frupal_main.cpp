// Carl Knori -- 11/23/2020 -- CS300:Frupal:Group 4
// This .cpp file will contain main

#include "game.h"

int main() {
  Game game;
  bool running = true;

  initscr();
  clear();
  noecho();
  keypad(stdscr, true);
  nodelay(stdscr, true);
  cbreak();

  while (running) {
    int key = getch();
    
    if (key != ERR) {
      game.update(key);
      
      if (game.get_player().get_energy() <= 0)
        running = false;
    }
  }

  return 0;
}
