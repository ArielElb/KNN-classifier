#include <condition_variable>
#include "ServerCLI/ServerCLI.h"


void ServerCLI::initCommands() {
    commands.push_back(new UploadCommand(dio,database));
    commands.push_back(new SettingsCommand(dio, database));
    commands.push_back(new ClassifyCommand(dio, database));
    commands.push_back(new DisplayCommand(dio, database));
    commands.push_back(new DownloadCommand(dio, database));
}
ServerCLI::ServerCLI(DefaultIO *dio) {
    this->dio = dio;
    initCommands();
}

/*
 * Runs server side of main menu.
 */
void ServerCLI::start() {
    int choice;
    do {
        std::string  menu = "Welcome to the KNN Classifier Server.\nPlease choose an option:\n1. upload an unclassified csv data "
                            "file\n2. algorithm settings\n3. classify data\n4. display results\n5. download"
                            " results\n8. exit";
        dio->write(menu);
        std::string input;
        try {
            // read the choice from the user
            input = dio->read();
        }
        catch (std::exception &e) {
            std::cerr << "Error reading from socket" << std::endl;
            return;
        }
        //std::cout << input << std::endl;
        try {
            choice = std::stoi(input);
        } catch (...) {
            std::cerr << "Client has aborted" << std::endl;
            choice = 8;
        }
        // check if the choice is valid
        if ((choice >= 1 && choice <= 5) || choice == 8) {
            if (choice != 8) {
                commands[choice - 1]->execute();
            }
        } else {
            std::cerr << "Received unexpected input from client" << std::endl;
            return;
        }
        if (choice == 8) {
            std::cout << "Client has disconnected" << std::endl;
        }
    } while (choice != 8);

}
ServerCLI::~ServerCLI() {
    delete database;
    delete dio;
    for (auto &command : commands) {
        delete command;
    }
}






