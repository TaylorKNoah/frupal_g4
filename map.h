//Taylor Noah
//CS300, Group Project: Land of Frupal
//Group 4 et al

//This is the Map header file
//It contains the classes:
//  Grovnik
//  Map

#include "player.h"

//type 0-3 = visable, 4-7 = invisible
enum Type {MEADOW_VIS, SWAMP_VIS, WATER_VIS, WALL_VIS, MEADOW_INV, SWAMP_INV, WATER_INV, WALL_INV};
string name_type[8] = {"Meadow","Swamp","Water","Wall","Unknown","Unkown","Unkown","Unkown"};

//These are used to control color pairs
#define MEADOW  1
#define SWAMP   2
#define WATER   3
#define WALL    4
#define HERO    5

//Definitions for entities on map
#define EMPTY       ' '
#define PLAYER      '@'
#define FOOD        'F'
#define TOOL        'T'
#define OBSTACLE    '!'
#define TREASURE    '$'
#define CLUE        '?'
#define SHIP        'S'
#define BINOCULARS  'B'

class Grovnik
{
  public:
    Grovnik(Type new_type);		//TODO add entity creation to constructor
    Type get_type();
    ~Grovnik();

  private:
    Entity* entity;
    Type type;
};

class Map
{
  public:
    Map(string file_name);              //constructor take filename to load map info
    void draw(int win_x,int win_y,int cur_x, int cur_y, int play_x, int play_y);		//draw uses terminal size to leave room for menu
    void update(int play_x,int play_y,bool binocs);
    Type info(int x, int y);
    ~Map();

  private:
    Grovnik*** map;     //This is a 2D Array of the form map[y][x]
};
