// Carl Knori -- 11/23/2020 -- CS300:Frupal:Group 4
// This .cpp file will contain main

#include "game.h"

int main(int argc, char* argv[]) 
{
  if(argc != 2)
  {
      cout<<"\nTo run: ./frupal <MAP.txt> where MAP is the name of your map file"<<endl;
      exit(-1);
  }

  FILE* the_map = fopen(argv[1], "r");

  if(the_map == NULL)
  {
      cout<<"\nFATAL ERROR: Could not find map file named "<<argv[1]<<".txt"<<endl;
      exit(-1);
  }

  fclose(the_map);

  Game game;
  bool running = true;

  initscr();
  Game game;
  clear();
  noecho();
  keypad(stdscr, true);
  nodelay(stdscr, true);
  cbreak();

  while (running) 
  {
    int key = getch();
    
    if (key != ERR) 
    {
      game.update(key);
      
      if (game.get_player().get_energy() <= 0)
        running = false;
    }
  }

  return 0;
}
