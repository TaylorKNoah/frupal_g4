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

//These are used to control color pairs
#define MEADOW  1
#define SWAMP   2
#define WATER   3
#define WALL    4
#define HERO    5
#define ROYAL   6

#define EMPTY       ' '
#define PLAYER      '@'
#define FOOD        'F'
#define TOOL        'T'
#define OBSTACLE    '!'
#define TREASURE    '$'
#define DIAMOND     '$'
#define CLUE        '?'
#define SHIP        'S'
#define BINOCULARS  'B'

class Grovnik
{
  public:
    Grovnik(Type new_type);		//TODO add entity creation to constructor
    ~Grovnik();

    Type get_type();
    void toggle_vis(bool vis);
    void build_ent(int ent,int i=0,int dia_x=0,int dia_y=0);
    char get_char();
    Entity* get_ent();

  private:
    Entity* entity;
    Type type;
    char draw;
};

class Map
{
  public:
    Map();              //constructor take filename to load map info
    void build(string filename);
    Entity* draw(WINDOW* &game_win,int cur_x, int cur_y, int play_x, int play_y);		//draw uses terminal size to leave room for menu
    void reveal(int play_x,int play_y,bool binocs);
    Type info(int x, int y);
    ~Map();

  private:
    Grovnik*** map;     //This is a 2D Array of the form map[y][x]
    string name_type[8] = {"Meadow","Swamp","Water","Wall","Unknown","Unknown","Unknown","Unknown"};
    int offset[2];
};
