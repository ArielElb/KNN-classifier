#ifndef ASS4_MENU_H
#define ASS4_MENU_H
#include <vector>
#include "Command.h"
class Menu {

public:
    Menu() = default;
    virtual ~Menu() = default;
     void showMenu(std::vector<Command*> commands);
};
#endif
