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

string Entity::get_name()
{
    return name;
}

//Lazy mans pure virtual functions
void Entity::init(int i) {}
void Entity::init(int x, int y) {}


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

int Obstacle::get_energy()
{
    return energy_needed;
}



/***********ROYAL_DIAMOND**********************/
Royal_Diamond::Royal_Diamond():game_end(false){}
Royal_Diamond::Royal_Diamond(string a_thing,bool found_diamond):something(a_thing),game_end(found_diamond){}

Royal_Diamond::~Royal_Diamond(){}


/****************CLUES**************************/
Clue::Clue():clue_type(0){}
Clue::Clue(int type,string a_sentence):clue_type(type),sentence(a_sentence){}

Clue::~Clue(){}

void Clue::display_clue(WINDOW *& game_win)
{ 

}
int Clue::make_clue(int q,int royal_x,int royal_y)
{
  int x_dir, y_dir;

  x_dir = royal_x - entity_x;
  y_dir = royal_y - entity_y;
  string begin = "The Royal Diamond is ";
  string andd = " and ";
  string go_x = to_string(x_dir);
  string go_y = to_string(y_dir);
  string south = " paces south ";
  string north = " paces north ";
  string east = " paces east ";
  string west = " paces west ";
  string end = " of this clue\n";

  if(q == 0)
  {
    sentence = "Through the swampy marsh across the great plains at the foot of Mt. Doom the Royal Diamond awaits\n";
    return 0;
  }
  else
  {
    if(x_dir < 0 && y_dir < 0)
      sentence = begin + go_x + west + andd + go_y + south + end;

    else if(x_dir < 0 && y_dir > 0)
      sentence = begin + go_x + west + andd + go_y + north + end;

    else if(x_dir > 0 && y_dir < 0)
      sentence = begin + go_x + east + andd + go_y + south + end;

    else if(x_dir > 0 && y_dir > 0)
      sentence = begin + go_x + east + andd + go_y + north + end;

    else if(x_dir > 0 && y_dir == 0)
      sentence = begin + go_x + east + end;

    else if(x_dir < 0 && y_dir == 0)
      sentence = begin + go_x + west + end;

    else if(x_dir == 0 && y_dir > 0)
      sentence = begin + north + end;

    else if(x_dir == 0 && y_dir < 0)
      sentence = begin + south + end;

    else
      sentence = "You're at the Royal Diamond and a clue somehow.\n";

    return 1;
  }
}
  
