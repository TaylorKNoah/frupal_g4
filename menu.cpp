//CS300, Group Project: Land of Frupal
//Group 4 et al

//This is the Menu implementation file
//It contains the menu class functions



///////////////////////////////////////////////////////////
//                  MENU FUCNTIONS
///////////////////////////////////////////////////////////


Menu::Menu() {};

~Menu::Menu() {};

void Menu::draw(int menu_start, WINDOW* &game_win)
{
    //set menu's WINDOW pointer
    // to use in other funcs

    //init if needed
    if(win == NULL)
        win = game_win;

    //create a column of #
    for(int i=0; i<LINES; ++i)
        mvprintw(win, i, menu_start, "#");

    //Menu Header
    mvprintw(win, 1, menu_start+1, " THE KINDOM OF FRUPAL ");
    mvprintw(win, 3, menu_start+1, "----- MENU -----");

    //Directional Input info
    mvprint(win, 10, menu_start+1, "To Move:");
    mvprint(win, 11, menu_start+1, "W) North");
    mvprint(win, 12, menu_start+1, "A) West");
    mvprint(win, 13, menu_start+1, "S) South");
    mvprint(win, 14, menu_start+1, "D) Weast");


    //get curor loc and display info about entities
    //TO ADD LATER

    //refresh the window
    wrefresh(win);
}
