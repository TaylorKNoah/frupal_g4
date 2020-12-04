// Lawrence Scroggs -- 11/13/2020 -- CS300:Frupal:Group 4
// This .h file will hold the entity class 


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ncurses.h> 

using namespace std;


class Entity
{

  public:
    Entity();  
    virtual ~Entity();  

    int get_x();
    int get_y();
    void get_loc(int* &loc);  
    void set_loc(int x, int y);
    bool compare_name(char* to_cmp);
    string get_name();

  //set protoc so derived classes can set themselves
  // but clients can't touch
  protected:
    int entity_x;
    int entity_y;

    string name;

  private:
   // int * location;
    char type;

};

class Obstacle:public Entity
{

  public:
    Obstacle();
    Obstacle(int obs_type);
    ~Obstacle();

    int get_energy();

    //creats an obstacle
    void init(int i);

  private:
    int energy_needed;

};

class Royal_Diamond: public Entity
{

  public:
    Royal_Diamond();
    Royal_Diamond(string a_string,bool found_diamond);
    ~Royal_Diamond();
  
  private:
    string something;
    bool game_end;

};

class Clue: public Entity
{

  public:
    Clue();
    Clue(int type,string a_sentence);
    ~Clue();

    int make_clue(int q, int royal_x,int royal_y);
    void display_clue();

  private:
    int clue_type;  // 0 = false clue -- 1 = true clue
    string sentence;
};
