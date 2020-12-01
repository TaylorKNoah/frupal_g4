//CS300, Group Project: Land of Frupal
//Group 4 et al

//This is the Menu header file
//It contains the menu class


#include "map.h"

class Menu
{

    public:

        Menu();
        ~Menu();

    private:

        WINDOW* win;
        void draw(int menu_start, WINDOW* &game_win);
};
