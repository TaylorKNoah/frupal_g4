// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// .cpp file for entity.h, constructor, destructor, needed
// functions for game, etc.



#include "entity.h"


/**************Entity*************************/
//constructor
Entity::Entity(): entity_x(0),entity_y(0),type(' '){}

//destructor
Entity::~Entity(){}

//Takes int* and mods first two elements
void Entity::get_loc(int* &loc)
{
    loc[0] = entity_x;
    loc[1] = entity_y;
}

void Entity::set_loc(int x,  int y) 
{
    entity_x = x;
    entity_y = y;
}

int Entity::get_x()
{
    return entity_x;
}


int Entity::get_y()
{
    return entity_y;
}

bool Entity::compare_name(char* to_cmp)
{
    if(strcmp(to_cmp, name.data()) == 0)
        return true;

    return false;
}



/**************OBSTACLE*************************/
Obstacle::Obstacle():energy_needed(0){}
Obstacle::Obstacle(int obs_type):energy_needed(obs_type){}

Obstacle::~Obstacle(){}

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



/***********ROYAL_DIAMOND**********************/
Royal_Diamond::Royal_Diamond():something(NULL),game_end(false){}
Royal_Diamond::Royal_Diamond(string a_thing,bool found_diamond):something(a_thing),game_end(found_diamond){}

Royal_Diamond::~Royal_Diamond(){}


/****************CLUES**************************/
Clue::Clue():clue_type(0),sentence(NULL){}
Clue::Clue(int type,string a_sentence):clue_type(type),sentence(a_sentence){}

Clue::~Clue(){}
  
