// Lawrence Scroggs -- CS300 -- Frupal Group 4
// Item class for different types of entities 
// Removed Treasure on 12/4/20 to be absorbed by Item.


#include "entity.h"


class Item: public Entity
{
	public:
		Item();
    ~Item();

    int get_is_owned();
    int get_whiffles(); 
    int bury_treasure(int z);
   
  	protected:
		int whiffles;
		int isOwned;
};


class Tools: public Item
{
	public:
    	Tools();  
    	~Tools();  

  	protected:
    	//creates a tool based off arg  
    	void init(int i);  
    	int rating;  
};


class Food: public Item
{
	public:
		Food();
    ~Food();
	protected:
    // make food based on arg
    int make_food(int i);
		int food_energy;

	private:
		int energy;

};
