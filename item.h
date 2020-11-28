#include "entity.h"


class Item: public Entity{
	public:
		Item();
    ~Item();
    Item * next;
  protected:
		int whiffles;
		int isOwned;
};


class Treasure: public Item{
	public:
		Treasure();
	protected:
  private:
};


class Tools: public Item{
  public:
    Tools();  
    ~Tools();  

  protected:
    //creates a tool based off arg  
    void init(int i);  
    int rating;  
};


class Food: public Item{
	public:
		Food();
    ~Food();
	protected:
    // make food based on arg
    int make_food(int i);
		int food_energy;
};
