//
// Created by arie1 on 1/14/2023.
//

#include "CLI.h"
#include "SettingsCommand.h"
#include "ClassifyCommand.h"
#include "DisplayCommand.h"
#include "DownloadCommand.h"

void CLI::initCommands() {
commands.push_back(new UploadCommand());
commands.push_back(new SettingsCommand());
commands.push_back(new ClassifyCommand());
commands.push_back(new DisplayCommand());
commands.push_back(new DownloadCommand());
}

CLI::CLI() {
    initCommands();
}
void CLI::start() {
    menu->showMenu(commands);
}





