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
        Type type;

    public:
        

        //Grovnik();
        //~Grovnik();
        
        Type get_type();


};


class Map
{
    private:

        Grovnik** game_map;
        Entity* ent;

    public:

        //Map();
        //~Map();
        Type get_grov_type(int x, int y);
        void draw(int x, int y, string filename);
        void reveal(int x, int y);

};
