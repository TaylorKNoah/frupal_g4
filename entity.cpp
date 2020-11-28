// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// .cpp file for entity.h, constructor, destructor, needed
// functions for game, etc.



#include "entity.h"



//////////////////////////////////////////////////////////
//                      Entity
//////////////////////////////////////////////////////////

//constructor
Entity::Entity():name(NULL),entity_x(0),entity_y(0),type(' '){}

//destructor
Entity::~Entity(){}



//////////////////////////////////////////////////////////
//                      Obstacle
//////////////////////////////////////////////////////////


//consturctor
Obstacle::Obstacle(): energy_needed(0) {}

//destructor
Obstacle::~Obstacle(): energy_needed(0) {}

void Obstacle::init(int i)
{
    //create tree
    // axe will divide eng_need by 2 (5)
    if(i==0)
    {
        name = "Tree";
        energy_needed = 10;
    }

    //create boulder
    //  hammer will divide energy by 3 (7)
    else if(i==1)
    {
        name = "Boulder";
        energy_needed = 21;
    }

}
