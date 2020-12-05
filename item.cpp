#include "item.h"


////////////////////////////////////////////////////////////////////
//                        Item functions
////////////////////////////////////////////////////////////////////

Item::Item(): whiffles(0), isOwned(0) {}

Item::~Item()
{ 
    whiffles = 0;
    isOwned = 0;
}

int Item::get_is_owned()
{
    return isOwned;
}

int Item::get_whiffles()
{
    return whiffles;
}

// initialize the diff types of treasure
int Item::bury_treasure(int z)
{

  if(z == 0)
  {
    name = "Gil";
    whiffles = 100;
  }
  else if(z == 1)
  {
    name = "Double Dollars";
    whiffles = 200;
  }
  else if(z == 2)
  {
    name = "Galactic Credits";
    whiffles = 300;
  }
  else if(z == 3)
  {
    name = "Rupees";
    whiffles = 400;
  }
  else
  {
    name = "BitCoin";
    whiffles = 500;
  }

  return whiffles;

}


void Item::use()
{
    --isOwned;
}


void Item::change_is_owned(int x)
{
    isOwned += x;
}




////////////////////////////////////////////////////////////////////
//                       Tool  functions
////////////////////////////////////////////////////////////////////


Tools::Tools(): rating(0) {}

Tools::~Tools()
{
    rating = 0;
}


//initializes a tool
void Tools::init(int i)
{
    //create Axe
    if( i == 0)
    {
        rating = 2;
        whiffles = 50;
        name = "Axe";
    }

    //create Hammer
    else if( i == 1)
    {
        rating = 3;
        whiffles = 100;
        name = "Hammer";
    }

    //create binocluars
    else if( i == 2)
    {
        name = "Binoculars";
        whiffles = 500;
    }

    else if ( i == 3)
    {
        name = "Ship";
        whiffles = 1000;
    }
}


int Tools::get_rating()
{
    return rating;
}


////////////////////////////////////////////////////////////////////
//                      Food   functions
////////////////////////////////////////////////////////////////////
Food::Food():food_energy(0){}

Food::~Food(){}


int Food::make_food(int i)
{
  // if less than 0 troll food
  if(i < 0)
  {
    food_energy = -10;
    whiffles = 100;
    name = "Mysterious Food";
  }
  else if(i == 1)
  {
    food_energy = 100;
    whiffles = 50;
    name = "Lembas";
  }
  else if(i == 2)
  {
    food_energy = 200;
    whiffles = 75;
    name = "Green Eggs & Ham";
  }
  else if(i == 3)
  {
    food_energy = 300;
    whiffles = 100;
    name = "Soylent Green";
  }
  else if(i == 4)
  {
    food_energy = 400;
    whiffles = 125;
    name = "Nuka-Cola";
  }
  else if(i == 5)
  {
    food_energy = 500;
    whiffles = 150;
    name = "Senzu Beans";
  }
  else
  {
    food_energy = 1000;
    whiffles = 100;
    name = "Mysterious Food";
  }

  return food_energy;

}


int Food::get_energy()
{
    return food_energy;
}

