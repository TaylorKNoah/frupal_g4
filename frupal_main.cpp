// CS300:Frupal:Group 4
// This .cpp file will contain main

#include "game.h"

int main(int argc, char* argv[]) 
{
  if(argc != 2)
  {
      cout<<"\nTo run: ./frupal <map.txt> where map is the name of your map file"<<endl;
      exit(-1);
  }

  FILE* the_map = fopen(argv[1], "r");

  if(the_map == NULL)
  {
      cout<<"\nFATAL ERROR: Could not find map file named "<<argv[1]<<".txt"<<endl;
      exit(-1);
  }

  fclose(the_map);


  //initscr();
  clear();
  //keypad(stdscr, true);
  cbreak();

  Game game(argv[1]);
  int win = 0;

  do
  {
    win = game.draw();
    int key = getch();
    
    if(key != ERR) 
    {
      game.update(key);
      
      if (game.get_energy() <= 0)
        win = 2;
    }
  }while(win == 0);

  if(win == 1)
      game.win();
  else
     game.lose();


  clear();
  endwin();

  return 0;
}
