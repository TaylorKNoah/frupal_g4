#include "entity.h"


class Item: public Entity
{
	public:
		Item();
    	~Item();

        int get_is_owned();
        int get_whiffles();
        void use();

  	protected:
		int whiffles;
		int isOwned;
};


class Tools: public Item
{
	public:
    	Tools();  
    	~Tools();  
        
        int get_rating();

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
