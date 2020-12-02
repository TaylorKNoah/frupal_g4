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
    mvwprintw(game_win, 1, menu_start+1, "   THE KINDOM OF FRUPAL ");
    mvwprintw(game_win, 3, menu_start+1, "     ----- MENU -----");

    //Directional Input info
    mvwprintw(game_win, 10, menu_start+1, " To Move:");
    mvwprintw(game_win, 11, menu_start+1, " W) North");
    mvwprintw(game_win, 12, menu_start+1, " A) West");
    mvwprintw(game_win, 13, menu_start+1, " S) South");
    mvwprintw(game_win, 14, menu_start+1, " D) East");


    //get curor loc and display info about entities
    //TO ADD LATER

    //refresh the window
    wrefresh(game_win);
}
