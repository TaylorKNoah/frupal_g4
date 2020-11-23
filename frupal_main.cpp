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

    switch (key) {
    case 'w':
      
      break;

    case 'a':

      break;

    case 's':

      break;

    case 'd':

      break;
  }

  return 0;
}
