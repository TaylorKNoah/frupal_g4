//CS300, Group Project: Land of Frupal
//Group 4

//This map file contains all the functons for the map
//each Gronik represents a cell on the map and can contain
//an item

#include "map.h"

Grovnik::Grovnik(Type new_type)
{
	type = new_type;
	entity = NULL;
}

Type Grovnik::get_type()
{
  return type;
}

Grovnik::~Grovnik()
{
	if(entity)
	{
		delete entity;
	}
}

Map::Map()
{
  map = NULL;
}

//Takes in the file name, opens an in file stream and populates the map
//Expects the first line to be the player spawn in x,y
//Map is lines 1-128, expected format #ofcells,Type:#ofcells,Type:etc, 128 cells per line
//Lines 129+ contain the item infromation
void Map::build(string file_name)
{
  int x = 0, y = 0, grov_count = 0, new_type = 0;
  char tempg[3];
  char tempt[1];
  ifstream in;

  in.open(file_name);

  
  if(!in)   //Check if file exists, exit if not
  {
    mvprintw(0,0,"NO MAP FILE FOUND");
  } 

  else
  {
    map = new Grovnik**[128];

    in.get(tempg,3,',');
    in.ignore(100,'\n');       //Ignore player spawn
    
    while(in && !in.eof() && y < 128)
    {
      map[y] = new Grovnik*[128];
      while(x < 128)
      {
        in.get(tempg,3,',');
        in.ignore(3,',');
        in.get(tempt,1,':');
        in.ignore(1,':');
        
        grov_count = stoi(tempg);
        new_type = atoi(tempt);
        
        while(x < (x + grov_count))
        {
          if(x > 127)   //Bounds check
          {
            break;
          } 
          map[y][x] = new Grovnik(static_cast<Type>(new_type));
          x++;
        }
      }
      in.ignore(100,'\n'); 
      y++;
    }
    //TODO ADD READING IN FOR ENTITY LOCATIONS
  }

  in.close();
  in.clear();
}

//Uses the terminal size and player location to draw the map
//so the player is always on screen
//leaves a 25 char space on the right for the menu
void Map::draw(WINDOW* &game_win, int cur_x, int cur_y, int play_x, int play_y)
{
  int size_x;
  int size_y;
  getmaxyx(game_win,size_y,size_x);
  size_x -= 26;
  int offset_x = 0, offset_y = 0;
  Type grov = MEADOW_INV;
  char ent = EMPTY;
 
  //Offets to keep the player centered in the terminal
  offset_x = play_x - (size_x / 2);
  offset_y = play_y - (size_y / 2);

  start_color();
  init_pair(MEADOW, COLOR_BLACK, COLOR_GREEN);
  init_pair(SWAMP, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(WATER, COLOR_WHITE, COLOR_BLUE);
  init_pair(WALL, COLOR_BLACK, COLOR_WHITE);
  init_pair(HERO, COLOR_WHITE, COLOR_RED);

  for(int y = 0; y < size_y; y++)
  {
    for(int x = 0; x < size_x; x++)
    {
      //Draws any out of bounds as invisible
      if(0 > (y + offset_y) || 127 < (y + offset_y) || 0 > (x + offset_x) || 127 < (x + offset_x))
      {
        grov = MEADOW_INV;
        ent = EMPTY;
      }
        
      else
      {
      grov = map[y + offset_y][x + offset_x]->get_type();
      ent = EMPTY;     //TODO add entity checker to find what character to draw
      }

      switch(grov)
      {
        case MEADOW_VIS:
          attron(COLOR_PAIR(MEADOW));
          mvwaddch(game_win,y,x, ent);
          attroff(COLOR_PAIR(MEADOW));
          break;

        case SWAMP_VIS:
          attron(COLOR_PAIR(SWAMP));
          mvwaddch(game_win,y,x, ent);
          attroff(COLOR_PAIR(SWAMP));
          break;        

        case WATER_VIS:
          attron(COLOR_PAIR(WATER));
          mvwaddch(game_win,y,x, ent);
          attroff(COLOR_PAIR(WATER));
          break;        

        case WALL_VIS:
          attron(COLOR_PAIR(WALL));
          mvwaddch(game_win,y,x, ent);
          attroff(COLOR_PAIR(WALL));
          break;        

        default:
          break;
      }
    }
  }

  //Draws the player center screen
  attron(COLOR_PAIR(HERO));
  mvwaddch(game_win,(play_y + (size_y / 2)),(play_x + (size_x / 2)), PLAYER);
  attroff(COLOR_PAIR(HERO));

  grov = map[cur_y][cur_x]->get_type();
  mvwprintw(game_win,6,(size_x + 2),"Type: %s",name_type[(int)grov]);

  //TODO add entity info to menu
}

//This update function will take the players location and binocular status
//and turn any grovniks around them visible
void Map::reveal(int play_x, int play_y, bool binocs)
{
  int check = 1;
  int grov = 0;
  if(binocs)
    check = 2;

  for(int y = (play_y - check); y <= (play_y + check); y++)
  {
    if(0 > y)
      break;
    for(int x = (play_x - check); x <= (play_x + check); x++)
    {
      if(0 > x)
        break;

      grov = (int)map[y][x]->get_type(); 
      if(3 < grov)
        grov -= 4;
    }
  }
}

//Returns grovnik type for provided coordinates
Type Map::info(int x, int y)
{
  return map[y][x]->get_type();
}

Map::~Map()
{
	for(int x=0; x<128; x++)
	{
		for(int y=0; y<128; y++)
		{
      if(map[x][y])
      {
			  delete map[x][y];			
        map[x][y] = NULL;
      }
		}
	}
}
