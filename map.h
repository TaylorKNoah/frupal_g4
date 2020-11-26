//Taylor Noah
//CS300, Group Project: Land of Frupal
//Group 4 et al

//This is the Mpa header file
//It contains the classes:
//  Grovnik
//  Map

#include "player.h"

//type 0-3 = visable, 4-7 = invisible
enum Type {MEADOW_VIS, SWAMP_VIS, WATER_VIS, WALL_VIS, MEADOW_INV, SWAMP_INV, WATER_INV, WALL_INV};
class Grovnik
{
    private:
        
        //still need bool since enum change?
        bool isVisable;
        Entity* entity;

    public:
        
        Type type;

        //Grovnik();
        //~Grovnik();
        


};


class Map
{
    private:

        Grovnik** map;
        Entity* ent;

    public:

        //Map();
        //~Map();

};
