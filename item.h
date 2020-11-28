#include "entity.h"


class Item: public Entity
{
	public:
		Item();
        ~Item();
	protected:
		int whiffles;
		int isOwned;
};


class Treasure: public Item{
	public:
		Treasure();
	//protected:
};


class Tools: public Item{
	public:
		Tools();
        ~Tools();


        //creates a tool based off arg
        void init(int i);

	protected:

		int rating;

};


class Food: public Item{
	public:
		Food();
	protected:
		int energy;
};

