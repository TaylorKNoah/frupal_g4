#include "entity.h"


class Item: public Entity{
	public:
		Item();
	protected:
		int whiffles;
		int isOwned;
};

class Treasure: public Item{
	public:
		Treasure();
	protected:
};

class Tools: public Item{
	public:
		Tools();
	protected:
		int rating;
};

class Food: public Item{
	public:
		Food();
	protected:
		int energy;
};

