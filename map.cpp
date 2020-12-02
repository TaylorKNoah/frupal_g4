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

Entity* Grovnik::get_entity()
{
  return entity;
}

Grovnik::~Grovnik()
{
	if(entity)
	{
		delete entity;
	}
}

void Grovnik::toggle_vis(bool vis)
{
    int temp = (int) type;

    if(vis && type > 3)
    {
      temp -= 4; 
      type = static_cast <Type> (temp);
    }

    else if(!vis && type < 4)
    {
        temp +=4;
        type = static_cast <Type> (temp);
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
  char tempg[4];
  char tempt[2];
  ifstream in;

  in.open(file_name);

  
  if(!in)   //Check if file exists, exit if not
  {
    mvprintw(0,0,"NO MAP FILE FOUND");
    exit(-1);
  } 

  else
  {
    map = new Grovnik**[128];

    in.get(tempg,4,',');
    in.ignore(100,'\n');       //Ignore player spawn
    
    while(in && !in.eof() && y < 128)
    {
      map[y] = new Grovnik*[128];
      while(x < 128)
      {
        in.get(tempg,4,',');
        in.ignore(4,',');
        in.get(tempt,4,':');
        in.ignore(4,':');
        
        grov_count = stoi(tempg);
        new_type = stoi(tempt);
        // new_type-=4; //THIS MAKES THE WHOLE MAP VISIBLE
                
        int current_x = x;
        while(x < (current_x + grov_count))
        {
          if(x > 127)   //Bounds check
          {
            break;
          } 

          Type to_add = static_cast<Type>(new_type);
          map[y][x] = new Grovnik(to_add);
          x++;
        }
      }
      x = 0;
      in.ignore(100,'\n'); 
      ++y;
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
  mvwaddch(game_win,(size_y / 2),(size_x / 2), PLAYER);
  attroff(COLOR_PAIR(HERO));

   
  grov = map[cur_y][cur_x]->get_type();
  mvwprintw(game_win,8,(size_x + 3),"Type: %s",name_type[(int)grov].c_str());
  //TODO add print entity in grov info to menu

  //Move cursor back to where the user left it
  wmove(game_win, (cur_y - offset_y), (cur_x - offset_x));
}

//This update function will take the players location and binocular status
//and turn any grovniks around them visible
void Map::reveal(int play_x, int play_y, bool binocs)
{
  int check = 1;
  if(binocs)
    check = 2;

  for(int y = (play_y - check); y <= (play_y + check); y++)
  {
    if(0 > y || y > 127)
      continue;
    for(int x = (play_x - check); x <= (play_x + check); x++)
    {
      if(0 > x || x > 127)
        continue;

      map[y][x]->toggle_vis(true);
      cout<<"";
    }
  }
}

//Returns grovnik type for provided coordinates
Type Map::info(int x, int y)
{
  return map[y][x]->get_type();
}

//Returns entity for provided coordinates
Entity* Map::entity_info(int x, int y)
{
  return map[y][x]->get_entity();
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


