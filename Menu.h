#ifndef ASS4_MENU_H
#define ASS4_MENU_H
#include <vector>
#include "Command.h"
class Menu {
private:
    std::vector<Command> commands;
public:
    Menu();
    void showMenu();
    void setCommand(Command command, int index);
};
#endif
