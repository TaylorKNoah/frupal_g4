// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// .cpp file for entity.h, constructor, destructor, needed
// functions for game, etc.



#include "entity.h"


/*****************ENTITY************************/

//constructor
Entity::Entity():name(NULL),entity_x(0),entity_y(0),type(' '){}

//destructor
Entity::~Entity(){}


/**************OBSTACLE*************************/
Obstacle::Obstacle():energy_needed(0){}
Obstacle::Obstacle(int obs_type):energy_needed(obs_type){}

Obstacle::~Obstacle(){}

/***********ROYAL_DIAMOND**********************/
Royal_Diamond::Royal_Diamond():something(NULL),game_end(false){}
Royal_Diamond::Royal_Diamond(string a_thing,bool found_diamond):something(a_thing),game_end(found_diamond){}

Royal_Diamond::~Royal_Diamond(){}


/****************CLUES**************************/
Clue::Clue():clue_type(0),sentence(NULL){}
Clue::Clue(int type,string a_sentence):clue_type(type),sentence(a_sentence){}

Clue::~Clue(){}
  
