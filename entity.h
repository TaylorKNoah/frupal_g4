// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// This .h file will hold the entity class 


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ncurses.h> 

using namespace std;


class Entity
{

  public:
    Entity();  
    ~Entity();  
    int* get_loc();  


  //set protoc so derived classes can set themselves
  // but clients can't touch
  protected:
 
    string name;

  private:
    int entity_x;
    int entity_y;
   // int * location;
    char type;

};


class Obstacle:public Entity
{

  public:
    Obstacle();
    ~Obstacle();

    //creats an obstacle
    void init(int i);

  private:
    int energy_needed;

};


class Royal_diamonds:public Entity
{

  private:
    string something;
    bool game_end;

};


class Clue:public Entity
{

  private:
    string sentence;

};
