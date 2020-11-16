// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// .cpp file for entity.h, constructor, destructor, needed
// functions for game, etc.



#include "entity.h"


/*****************ENTITY************************/

//constructor
entity::entity():name(NULL),entity_x(0),entity_y(0),type(' '){}

//destructor
entity::~entity(){}

/***************PLAYER*************************/

//constructor
player::player():my_whiffles(1000),my_energy(100),my_items(NULL){}

//destructor
player::~player(){

  my_whiffles = 0;
  my_energy = 0;

  while(my_items->next != NULL)
  {
    items * temp = my_items;
    my_items = my_items->next;
    delete temp;
  }

}
