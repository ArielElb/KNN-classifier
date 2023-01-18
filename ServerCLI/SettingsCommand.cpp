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
    bool validK = true;
    bool validMetric = true;
    int k;
    std::string returnMessage = "";
    std::istringstream sstream(userResponse);
    string b;
    std::getline(sstream, b, ' ');
    for (char i : b) {
        if (!isdigit(i)) {
            returnMessage += "invalid value for k\n";
            validK = false;
            break;
        }
    }
    if (validK) {
        k = std::stoi(b);
    }
    std::getline(sstream, b);
    if (!checkDistanceFunc(b)) {
       returnMessage += "invalid value for metric\n";
       validMetric = false;
    }
    if (validK && validMetric) {
        this->database->isKValid(k);
        this->database->setDistanceFunction(b);
    }
    this->dio->write(returnMessage);
}

SettingsCommand::SettingsCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->database = pDatabase;
}
