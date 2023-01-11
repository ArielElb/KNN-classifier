#ifndef ASS4_MENU_H
#define ASS4_MENU_H
#include <vector>

class Menu {

private:
    vector<Command> commands;

public:
    Menu();
    void showMenu();
};


#endif
