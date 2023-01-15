//
// Created by arie1 on 1/14/2023.
//

#include "ServerCLI.h"
#include "SettingsCommand.h"
#include "ClassifyCommand.h"
#include "DisplayCommand.h"
#include "DownloadCommand.h"
#include "SocketIO.h"

void ServerCLI::initCommands() {
    commands.push_back(new UploadCommand(dio, database));
    commands.push_back(new SettingsCommand(dio, database));
    commands.push_back(new ClassifyCommand(dio, database));
    commands.push_back(new DisplayCommand(dio, database));
    commands.push_back(new DownloadCommand(dio, database));

}

ServerCLI::ServerCLI(DefaultIO *dio) {
    initCommands();
    this->dio = dio;
    int k = 0;
    std::string matrix;
}

void ServerCLI::start() {
    int choice;
    dio->write("Welcome to the Anomaly Detection Server.\nPlease choose an option:\n");
    do {
        std::string data  = dio->read();
        try {
            choice = std::stoi(data);
        }
        catch (std::exception &e) {
            dio->write("Not a valid input");
        }
        switch (choice) {
            case 1:
                commands[0]->execute();
                break;
            case 2:
                commands[1]->execute();
                break;
            case 3:
                commands[2]->execute();
                break;
            case 4:
                commands[3]->execute();
                break;
            case 5:
                commands[4]->execute();
                break;
            case 8:
                break;
            default:
                dio->write("Not a valid input");
                break;
        }
    } while (choice != 8);

}
ServerCLI::~ServerCLI() {
    delete this->database;
    delete this->dio;
    for (auto &command : commands) {
        delete command;
    }
}






