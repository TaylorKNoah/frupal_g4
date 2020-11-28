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


class Treasure: public Item
{
	public:
		Treasure();
	//protected:
};


class Tools: public Item
{
	public:
		Tools();
	protected:

		int rating;

        //creates a tool based off arg
        void init(int i);
};


class Food: public Item
{
	public:
		Food();
	protected:
		int energy;
};

