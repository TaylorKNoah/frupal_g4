//CS300, Group Project: Land of Frupal
//Group 4 et al

//This is the Menu implementation file
//It contains the menu class functions


#include "menu.h"



///////////////////////////////////////////////////////////
//                  MENU FUCNTIONS
///////////////////////////////////////////////////////////


Menu::Menu() {};

Menu::~Menu() {};

void Menu::draw(int menu_start, WINDOW* &game_win)
{
    int x = 0;
    int y = 0;
    getmaxyx(game_win, y, x);

    //create a column of #
    for(int i=0; i<y; ++i)
        mvwprintw(game_win, i, menu_start, "#");

    //Menu Header
    mvwprintw(game_win, 1, menu_start+1, "  THE KINGDOM OF FRUPAL ");
    mvwprintw(game_win, 3, menu_start+1, "     ----- MENU -----");

    //Directional Input info
    mvwprintw(game_win, 12, menu_start+1, " To Move:");
    mvwprintw(game_win, 13, menu_start+1, " W) North");
    mvwprintw(game_win, 14, menu_start+1, " A) West");
    mvwprintw(game_win, 15, menu_start+1, " S) South");
    mvwprintw(game_win, 16, menu_start+1, " D) East");


    //get curor loc and display info about entities
    //TO ADD LATER

    //refresh the window
    //wrefresh(game_win);
}


void Menu::prompt_interaction(int menu_start, WINDOW* &game_win, Entity* temp)
{
    //Clear WASD Display
    mvwprintw(game_win, 12, menu_start+1, "         ");
    mvwprintw(game_win, 13, menu_start+1, "         ");
    mvwprintw(game_win, 14, menu_start+1, "         ");
    mvwprintw(game_win, 15, menu_start+1, "         ");
    mvwprintw(game_win, 16, menu_start+1, "         ");

    char prompt[32];

    //Get entity type
    //Construct prompt accordingly
    Obstacle* optr = dynamic_cast <Obstacle*> (temp);
    if(optr)
    {
        //construct string for prompt2
        int j = sprintf(prompt, "%s", "Energy needed to clear ");
        j += sprintf(prompt+j, "%s", optr->get_name().data());
        j += sprintf(prompt+j, "%s", ": ");
        sprintf(prompt+j, "%i", optr->get_energy());
    }


    else
    {
        Food* fptr = dynamic_cast<Food*>(temp);
        if(fptr)
        {
            int j = sprintf(prompt, "%s", "Cost of food '");
            j += sprintf(prompt+j, "%s", fptr->get_name().data());
            j += sprintf(prompt+j, "%s", "' : ");
            sprintf(prompt, "%i", fptr->get_whiffles());
        }

        else
        {
            Tools* tptr = dynamic_cast<Tools*>(temp);
            if(tptr)
            {
                int j = sprintf(prompt, "%s", "Cost of tool '");
                j += sprintf(prompt+j, "%s", tptr->get_name().data());
                j += sprintf(prompt+j, "%s", "' : ");
                sprintf(prompt, "%i", tptr->get_whiffles());
            }

            //must be treasure
            else
            {
               Item* iptr = dynamic_cast<Item*>(temp);
               if(iptr)
               {
                   int j = sprintf(prompt, "%s", "Found "); 
                   j += sprintf(prompt, "%s", iptr->get_name().data());
                   j += sprintf(prompt, "%s", "!"); 
               }
            }
        }


    }

    //send prompt script to screen
    mvwprintw(win, 12, menu_start+1, prompt);
}







