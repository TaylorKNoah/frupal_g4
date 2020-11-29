// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// This .h file will hold the entity class 


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ncurses.h> 

using namespace std;


<<<<<<< HEAD
class Entity{

  public:
    Entity();
    ~Entity();

  protected:
=======
class Entity
{

  public:
    Entity();  
    ~Entity();  
    int* get_loc();  


  //set protoc so derived classes can set themselves
  // but clients can't touch
  protected:
 
>>>>>>> b9af4e7d36d3036a687d255b1f3b946d5920b0ef
    string name;

  private:
    int entity_x;
    int entity_y;
   // int * location;
    char type;

};
<<<<<<< HEAD
class Obstacle:public Entity{

  public:
    Obstacle();
    Obstacle(int obs_type);
    ~Obstacle();
=======


class Obstacle:public Entity
{

  public:
    Obstacle();
    ~Obstacle();

    //creats an obstacle
    void init(int i);
>>>>>>> b9af4e7d36d3036a687d255b1f3b946d5920b0ef

  private:
    int energy_needed;

};
<<<<<<< HEAD
class Royal_Diamond:public Entity{

  public:
    Royal_Diamond();
    Royal_Diamond(string a_string,bool found_diamond);
    ~Royal_Diamond();
=======


class Royal_diamonds:public Entity
{
>>>>>>> b9af4e7d36d3036a687d255b1f3b946d5920b0ef

  private:
    string something;
    bool game_end;

};
<<<<<<< HEAD
class Clue:public Entity{

  public:
    Clue();
    Clue(int type,string a_sentence);
    ~Clue();

  private:
    int clue_type;  // 0 = false clue -- 1 = true clue
=======


class Clue:public Entity
{

  private:
>>>>>>> b9af4e7d36d3036a687d255b1f3b946d5920b0ef
    string sentence;

};
