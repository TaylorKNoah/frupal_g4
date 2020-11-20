//Taylor Noah
//CS300, Group Project: Land of Frupal
//Group 4 et al

//This is the Map header file
//It contains the classes:
//  Grovnik
//  Map

//#include "player.h"

//TODO remove thess includes, they are only for testing purposes
#include <stdlib.h>
#include <ncurses.h>

//type 0-3 = visable, 4-7 = invisible
enum Type {MEADOW_VIS, SWAMP_VIS, WATER_VIS, WALL_VIS, MEADOW_INV, SWAMP_INV, WATER_INV, WALL_INV};

//These are used to control color pairs
#define MEADOW  1
#define SWAMP   2
#define WATER   3
#define WALL    4

//Definitions for entities on map
#define EMPTY       ' '
#define HERO        '@'
#define FOOD        'F'
#define TOOL        'T'
#define OBSTACLE    '!'
#define TREASURE    '$'
#define CLUE        '?'
#define SHIP        'S'
#define BINOCULARS  'B'

class Grovnik
{
    private:
        
      //Entity* entity;
	    int *entity;  			//Filler for testing
	    Type type;

    public:

      Grovnik(int new_type);		//TODO add entity creation to constructor
	    Type get_type();
      ~Grovnik();
};

class Map
{
    private:

      Grovnik*** map;

    public:

	    Map();				            //default constructor makes grovniks for map
      //Map(string file_name);  //constructor take filename to load map info
	    void draw(int size[]);		//draw uses terminal size to leave room for menu
	    Grovnik info(int loc[]);	//returns info for cursor/comparison
      ~Map();
};
