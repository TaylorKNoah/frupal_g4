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
<<<<<<< HEAD
    ~Food();
	protected:
    // make food based on arg
    int make_food(int i);
		int food_energy;
=======
	private:
		int energy;
>>>>>>> b9af4e7d36d3036a687d255b1f3b946d5920b0ef
};
