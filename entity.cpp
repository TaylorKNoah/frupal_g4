// CS300:Frupal:Group 4
// .cpp file for entity.h



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
void Entity::init(int q, int x, int y) {}


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


//returns true if name is "Tree"
bool Obstacle::is_tree()
{
    char tree[5] = "Tree";
    if(strcmp(tree, name.data()) == 0)
        return true;

    return false;
}



/***********ROYAL_DIAMOND**********************/
Royal_Diamond::Royal_Diamond():game_end(false)
{
    name = "Royal Diamond";
}
Royal_Diamond::Royal_Diamond(string a_thing,bool found_diamond):something(a_thing),game_end(found_diamond){}

Royal_Diamond::~Royal_Diamond(){}


/****************CLUES**************************/
Clue::Clue():clue_type(0){}
Clue::Clue(int type,string a_sentence):clue_type(type),sentence1(a_sentence){}

Clue::~Clue(){}


void Clue::display_clue(int menu_start,WINDOW *& game_win)
{ 
    mvwprintw(game_win, 12, menu_start+1, "%s",sentence1.data());
    mvwprintw(game_win, 13, menu_start+1, "%s",sentence2.data());
    mvwprintw(game_win, 14, menu_start+1, "%s",sentence3.data());
    mvwprintw(game_win, 15, menu_start+1, "%s",sentence4.data());
    mvwprintw(game_win, 16, menu_start+1, "            ");

  return;

}


void Clue::init(int q,int royal_x,int royal_y)
{
  clue_type = q;
  x_dir = royal_x - this->entity_x;
  y_dir = royal_y - this->entity_y;
  string begin = "The Royal Diamond is ";
  string andd = " and ";
  string go_x = to_string(x_dir);
  string go_y = to_string(y_dir);
  string south = " paces south ";
  string north = " paces north ";
  string east = " paces east ";
  string west = " paces west ";
  string end = "of this clue.";

  if(clue_type == 0)
  {

    sentence1 = "Through the swampy marsh";
    sentence2 = "across the great plains"; 
    sentence3 = "at the foot of Mt. Doom";
    sentence4 = "the Royal Diamond awaits";
  }
  else
  {
    if(x_dir < 0 && y_dir < 0)
    {
      x_dir = abs(x_dir);
      y_dir = abs(y_dir);
      go_x = to_string(x_dir);
      go_y = to_string(y_dir);
      sentence1 = begin; 
      sentence2 = go_x + west + andd; 
      sentence3 = go_y + north;
      sentence4 = end;
    }
    else if(x_dir < 0 && y_dir > 0)
    {
      x_dir = abs(x_dir);
      go_x = to_string(x_dir);
      sentence1 = begin;
      sentence2 = go_x + west + andd;
      sentence3 = go_y + south;
      sentence4 = end;
    }
    else if(x_dir > 0 && y_dir < 0)
    {
      y_dir = abs(y_dir);
      go_y = to_string(y_dir);
      sentence1 = begin; 
      sentence1 = begin;
      sentence2 = go_x + east + andd;
      sentence3 = go_y + north;
      sentence4 = end;
    }
    else if(x_dir > 0 && y_dir > 0)
    {
      sentence1 = begin;
      sentence2 = go_x + east + andd;
      sentence3 = go_y + south;
      sentence4 = end;
    }
    else if(x_dir > 0 && y_dir == 0)
    {
      sentence1 = begin;
      sentence2 = go_x + east;
      sentence3 = end;
      sentence4 = "              ";
    }
    else if(x_dir < 0 && y_dir == 0)
    {
      x_dir = abs(x_dir);
      go_x = to_string(x_dir);
      sentence1 = begin;
      sentence2 = go_x + west;
      sentence3 = end;
      sentence4 = "              ";
    }
    else if(x_dir == 0 && y_dir > 0)
    {
      sentence1 = begin;
      sentence2 = go_y + south;
      sentence3 = end;
      sentence4 = "              ";
    }
    else if(x_dir == 0 && y_dir < 0)
    {
      y_dir = abs(y_dir);
      go_y = to_string(y_dir);
      sentence1 = begin;
      sentence2 = go_y + north;
      sentence3 = end;
      sentence4 = "              ";
    }
    else
    {
      sentence1 = "You're at the Royal";
      sentence2 = "Diamond and a clue";
      sentence3 = "somehow.       ";
      sentence4 = "              ";
    }
  }


}
  
