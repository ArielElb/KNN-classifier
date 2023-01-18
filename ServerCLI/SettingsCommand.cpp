//
// Created by arie1 on 1/14/2023.
//

#include "SettingsCommand.h"

void SettingsCommand::execute() {
    // change the settings of the server
    // send the current settings to the client
    this->dio->write("The current KNN parameters are:" + std::string(this->database->getK()) +
    " " + this->database->getDistanceFunction());
    std::string userResponse = this->dio->read();
    if (userResponse == "") {
        return;
    }

}

SettingsCommand::SettingsCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->database = pDatabase;
}
