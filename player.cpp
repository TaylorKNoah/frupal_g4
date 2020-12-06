// Lawrence Scroggs, Carl Knori -- 11/17/2020 -- CS300:Frupal:Group 4
// This will be the player.cpp file where we will implement
// the functions for the player class



#include "player.h"



/***************PLAYER*************************/

//constructor
Player::Player() 
{
  my_items = NULL;
  has_binoculars = false;
  has_ship = false;
  win = stdscr;
}

bool Player::has_boat()
{
  return has_ship;
}
bool Player::has_binocs()
{
  return has_binoculars;
}
void Player::build(string file)
{
    ifstream in;

    in.open(file);

    char locx[4];
    char locy[4];

    in.get(locx, 4, ',');
    in.ignore(100, ',');
    in.get(locy, 4, ':');
    in.ignore(100, ':');

    in.clear();
    in.close();

    int x = stoi(locx);
    int y = stoi(locy);

    set_loc(x, y);


    my_whiffles = 1000;
    my_energy = 100;
    my_items = new Item* [10];

    for(int i = 0; i < 10; ++i)
    {
        my_items[i] = NULL;
    }

}

//destructor
Player::~Player()
{

    my_whiffles = 0;
    my_energy = 0;

    if(my_items)
    {
        for(int i=0; i<10; ++i)
        {
            if(my_items[i])
                delete my_items[i];
        }
        delete [] my_items;
    } 
}


int Player::get_energy()
{
    return my_energy;
}


void Player::add_energy(int energy) 
{
    my_energy += energy;
}


void Player::draw(int menu_start, WINDOW* game_win)
{

    string energy = to_string(my_energy);
    string whiffles = to_string(my_whiffles);

    mvwprintw(game_win, 5, menu_start+1, " Energy: ");
    mvwprintw(game_win, 5, menu_start+12, energy.data());

    mvwprintw(game_win, 6, menu_start+1, " Whiffles: ");
    mvwprintw(game_win, 6, menu_start+12, whiffles.data());

}



void Player::reset_location()
{
    Entity::set_loc(player_previous_x, player_previous_y);
}


void Player::set_previous_location(int x, int y)
{
    player_previous_x = x;
    player_previous_y = y;
}

//Displays players inventory (axe and hammer counts)
//  First clears the menu of WASD controls
//  Then displays inventory in that area of the menu
void Player::display_inventory(int menu_start, WINDOW* &game_win)
{
    int num_axe = 0;
    int num_hammer = 0;
    char axe_cmp[4] = "Axe";
    char hammer_cmp[7] = "Hammer";

    //Get item counts
    for(int i=0; i<10; ++i)
    {
        if(my_items[i]->compare_name(axe_cmp))
            num_axe += my_items[i]->get_is_owned();

        else if(my_items[i]->compare_name(hammer_cmp))
            num_hammer += my_items[i]->get_is_owned();
    }

    //clear WASD
    mvwprintw(game_win, 12, menu_start+1, "          ");
    mvwprintw(game_win, 13, menu_start+1, "          ");
    mvwprintw(game_win, 14, menu_start+1, "          ");
    mvwprintw(game_win, 15, menu_start+1, "          ");
    mvwprintw(game_win, 16, menu_start+1, "          ");

    //construct char* for prints
    char axe[16];
    int j = sprintf(axe, "%s", "Axes: ");
    sprintf(axe+j, "%d", num_axe);

    char hammer[16];
    j = sprintf(hammer, "%s", "Hammers: ");
    sprintf(hammer+j, "%d", num_hammer);

    //Display inventory
    mvwprintw(game_win, 12, menu_start+1, "Inventory");
    mvwprintw(game_win, 13, menu_start+1, axe);
    mvwprintw(game_win, 14, menu_start+1, hammer);
}



// just reports if player can remove the obstacle
bool Player::clear_obstacle(int menu_start, WINDOW* &game_win, Obstacle* optr)
{

    char input = 'Y';
    mvwprintw(game_win, 12, menu_start+1, "          ");
    mvwprintw(game_win, 13, menu_start+1, "          ");
    mvwprintw(game_win, 14, menu_start+1, "          ");
    mvwprintw(game_win, 15, menu_start+1, "          ");
    mvwprintw(game_win, 16, menu_start+1, "          ");


    //if tree
    if(optr -> is_tree())
    {

        mvwprintw(game_win, 12, menu_start+1, "Tree blocks path.");
        //check for axe
        char axe[4] = "Axe";
        if(has_item(axe))
        {
            mvwprintw(game_win, 13, menu_start+1, "Use axe?");
            mvwprintw(game_win, 14, menu_start+1, "Enter Y / N: ");

            do
            {
                input = toupper(getch());

            }while(input != 'Y' && input != 'N');

            if(input == 'Y')
            {
                for(int i=0; i<10; ++i)
                {
                    if(my_items[i] != NULL && my_items[i]->compare_name(axe))
                    {
                        mvwprintw(game_win, 15, menu_start+1, "Tree cleared with axe!");

                        Item* iptr = my_items[i];
                        Tools* tptr = dynamic_cast<Tools*>(iptr);
                        my_energy -= (optr->get_energy() / tptr->get_rating());

                        use_item(i);

                        return true;
                    }
                }
            }
        }

        //will only be reached if player has no axe or declines to use axe
        mvwprintw(game_win, 13, menu_start+1, "Clear without axe?");
        mvwprintw(game_win, 14, menu_start+1, "Enter Y / N");
        do
        {

            input = getch();
            input = toupper(input);

        }while(input != 'Y' && input != 'N');


        if(input == 'Y')
        {
          mvwprintw(game_win, 15, menu_start+1, "Cleared by hand!");
          my_energy -= (optr->get_energy());
          return true;
        }
    }

    //optr is boulder
    else
    {
        mvwprintw(game_win, 12, menu_start+1, "Boulder blocks path.");
        //check for hammer
        char hammer[7] = "Hammer";
        if(has_item(hammer))
        {

            mvwprintw(game_win, 13, menu_start+1, "Use hammer?");
            mvwprintw(game_win, 14, menu_start+1, "Enter Y / N");

            do
            {
                //get user input
                if(input != 'Y' && input != 'N')
                    mvwprintw(game_win, 14, menu_start+1, "Please answer with Y or N");

                input = getch();
                input = toupper(input);

            }while(input != 'Y' && input != 'N');

             if(input == 'Y')
             {
               for(int i=0; i<10; ++i)
               {
                 if(my_items[i]->compare_name(hammer))
                {
                  mvwprintw(game_win, 15, menu_start+1, "Cleared with hammer!");
                  my_items[i]->use();

                  Tools* tptr = dynamic_cast<Tools*>(my_items[i]);
                  my_energy -= (optr->get_energy() / tptr->get_rating());
                  return true;
                }
               }
             }
         }



        mvwprintw(game_win, 13, menu_start+1, "Clear without hammer?");
        mvwprintw(game_win, 14, menu_start+1, "Enter Y / N");

        do
        {

            //get user input
            if(input != 'Y' && input != 'N')
                mvwprintw(game_win, 14, menu_start+1, "Please answer with Y or N");

            input = getch();
            input = toupper(input);

        }while(input != 'Y' && input != 'N');


        if(input == 'Y')
        {
            mvwprintw(game_win, 15, menu_start+1, "Cleared by hand!");
            my_energy -= (optr->get_energy());
            return true;
        }
    }

    //player does not want to clear obstacle
    mvwprintw(game_win, 15, menu_start+1, "Obstacle not cleared.");
    return false;
}


bool Player::has_item(char* to_cmp)
{
    for(int i=0; i<10; ++i)
    {
        //if ptr isnt null and name is match
        if(my_items[i] != NULL && my_items[i]->compare_name(to_cmp))
            return true;

        //if we reach a null ptr then it's not in t he list
        if(my_items[i] == NULL)
            return false;
    }

    //if list is full, but no match
    return false;
}


//Return int idicates what to do with the Item* after this function is done
// 0 - Do nothing. Leave this pointer on the map
// 1 - Delete this pointer / Player will not use this pointer's contents
// 2 - Set this pointer to NULL / Player will use this pointer's contents
int Player::pickup_item(int menu_start, WINDOW* &win, Item* to_pickup)
{
    int pointer_fate = 0;
    char input = 'Y';

    if(to_pickup == NULL)
        return pointer_fate;

    //clear WASD
    mvwprintw(win, 12, menu_start+1, "          ");
    mvwprintw(win, 13, menu_start+1, "          ");
    mvwprintw(win, 14, menu_start+1, "          ");
    mvwprintw(win, 15, menu_start+1, "          ");
    mvwprintw(win, 16, menu_start+1, "          ");

    //get whiffles
    int whif_temp = to_pickup->get_whiffles();

    //make a string for whiffles
    char whiffles[8];
    sprintf(whiffles, "%i", whif_temp);

    // RTTI TIME
    Tools* tptr = dynamic_cast <Tools*> (to_pickup);
    //tool is found
    if(tptr)
    {
        char tool[20]; 
        int j = sprintf(tool, "%s", tptr->get_name().data());
        sprintf(tool+j, "%c", '!');

        mvwprintw(win, 12, menu_start+1, "You found:");
        mvwprintw(win, 13, menu_start+4, tool);
        mvwprintw(win, 14, menu_start+1, "Cost: ");
        mvwprintw(win, 14, menu_start+10, whiffles);
        mvwprintw(win, 15, menu_start+1, "Pay cost to pickup?");


        do
        {
            mvwprintw(win, 16, menu_start+1, "Enter Y or N: ");
            input = toupper(getch());


        }while(input != 'Y' && input != 'N');
        
        if(input == 'Y')
        {
            bool need_maps_pointer = false;
            if(my_whiffles >= whif_temp)
                need_maps_pointer = get_tool(tptr);
            else
              mvwprintw(win, 17, menu_start+1, "Not enough whiffles.");
          
            if(need_maps_pointer)
              pointer_fate = 2;
        }

    }
    //food or treasure is found
    else
    {
        Food* fptr = dynamic_cast <Food*> (to_pickup);
        //food is found
        if(fptr)
        {
            char food[20];
            int j = sprintf(food, "%s", fptr->get_name().data());
            sprintf(food+j, "%c", '!');

            mvwprintw(win, 12, menu_start+1, "You found:");
            mvwprintw(win, 13, menu_start+4, food);
            mvwprintw(win, 14, menu_start+1, "Cost: ");
            mvwprintw(win, 14, menu_start+8, whiffles);
            mvwprintw(win, 15, menu_start+1, "Pay cost and eat?");

            do
            {
                mvwprintw(win, 16, menu_start+1, "Enter Y or N: ");
                input = toupper(getch());

            }while(input != 'Y' && input != 'N');

            if(input == 'Y')
            {
                if(my_whiffles > whif_temp)
                {
                    eat_food(fptr);
                    pointer_fate = 1;
                }
                else
                    mvwprintw(win, 17, menu_start+1, "Not enough whiffles.");
            }

        }

        //treasure is found
        else
        {
            char treasure[24];
            int j = sprintf(treasure, "%s", to_pickup->get_name().data());
            sprintf(treasure+j, "%s", "!!!");

            mvwprintw(win, 12, menu_start+1, "You found:");
            mvwprintw(win, 13, menu_start+4, treasure);
            mvwprintw(win, 14, menu_start+1, "Whiffles gained: ");
            mvwprintw(win, 15, menu_start+1, whiffles);
            mvwprintw(win, 16, menu_start+1, "Pick up?");

            do
            {
                mvwprintw(win, 17, menu_start+1, "Enter Y or N: ");
                input = toupper(getch());

            }while(input != 'Y' && input != 'N');

            if(input == 'Y')
            {
                get_treasure(to_pickup);
                pointer_fate = 1;
            }

        }

    }

    return pointer_fate;
}


//returns true if player does not already have the item
// this way it will use the map pointer and increment hasOwned
//
// If the player has the tool already it will
// increment hasOwned only.
// Then it returns flase to indicate to the map
// to delete the poitner.
//
// decrements player money by tool cost
bool Player::get_tool(Tools* &tptr)
{
    bool picked_up = false;

    for(int i=0; i<10; ++i)
    {
        if(my_items[i] != NULL && (strcmp(my_items[i]->get_name().data(), tptr->get_name().data())) == 0)
        {
           my_items[i]->change_is_owned(1); 
           picked_up = true;
           break;
        }

        if(my_items[i] == NULL)
        {
            my_items[i] = tptr;
            my_items[i]->change_is_owned(1); 
            break;
        }
    }

   my_whiffles -= tptr->get_whiffles();

   char binoc [11] = "Binoculars";
   if(strcmp(tptr->get_name().data(), binoc) == 0)
       has_binoculars = true;

   char ship [5] = "Ship";
   if(strcmp(tptr->get_name().data(), ship) == 0)
       has_ship = true;

   return picked_up;
}


//gives energy to player from food
//takes money away from player based on food cost
void Player::eat_food(Food* fptr)
{
    my_energy += fptr->get_energy();
    my_whiffles -= fptr->get_whiffles();
}


void Player::get_treasure(Item* treasure)
{
    my_whiffles += treasure->get_whiffles();
}



void Player::use_item(int i)
{
    if(my_items[i] == NULL)
        return;

    int left = my_items[i] -> use();

    if(left == 0)
    {
        delete my_items[i];
        my_items[i] = NULL;
    }
}





