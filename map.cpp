//CS300, Group Project: Land of Frupal
//Group 4

//This map file contains all the functons for the map
//each Gronik represents a cell on the map and can contain
//an item

#include "map.h"

Grovnik::Grovnik(int new_type)
{
	type = (Type)new_type;
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

//THIS IS ONLY USED FOR TESTING
//GENERATES A RANDOM MAP
Map::Map()
{
	int vis = 4; 	//4 = All cells visible, 8 puts invis cells also

	map = new Grovnik**[128];

	for(int i=0; i<128; i++)
	{
		map[i] = new Grovnik*[128];
		for(int j = 0; j<128; j++)
		{
			map[i][j] = new Grovnik(rand() % vis);			
		}
	}
}

Map::~Map()
{
	for(int i=0; i<128; i++)
	{
		for(int j = 0; j<128; j++)
		{
			delete map[i][j];			
      map[i][j] = NULL;
		}
	}
}
void Map::draw(int size[])
{
  int x,y;
  Type grov = MEADOW_INV;
  if(size[0] > (128 + 25))
    x = 128;
  else
    x = size[0] - 25;

  if(size[1] < 128)
    y = 128;
  else
    y = size[1];

  start_color();
  init_pair(MEADOW, COLOR_BLACK, COLOR_GREEN);
  init_pair(SWAMP, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(WATER, COLOR_WHITE, COLOR_BLUE);
  init_pair(WALL, COLOR_BLACK, COLOR_WHITE);

  for(int i=0; i<x; i++)
  {
    for(int j=0; j<y; j++)
    {
      grov = map[i][j]->get_type();
      switch(grov)
      {
        case MEADOW_VIS:
          attron(COLOR_PAIR(MEADOW));
          mvaddch(j,i, EMPTY);
          attroff(COLOR_PAIR(MEADOW));
          break;

        case SWAMP_VIS:
          attron(COLOR_PAIR(SWAMP));
          mvaddch(j,i, EMPTY);
          attroff(COLOR_PAIR(SWAMP));
          break;        

        case WATER_VIS:
          attron(COLOR_PAIR(WATER));
          mvaddch(j,i, EMPTY);
          attroff(COLOR_PAIR(WATER));
          break;        

        case WALL_VIS:
          attron(COLOR_PAIR(WALL));
          mvaddch(j,i, EMPTY);
          attroff(COLOR_PAIR(WALL));
          break;        

        default:
          break;
      }
    }
  }
}
