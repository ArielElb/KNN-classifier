#include <thread>
#include "ServerCLI/SettingsCommand.h"

void SettingsCommand::execute() {
    // change the settings of the server
    // send the current settings to the client
    dio->write("The current KNN parameters are: K = " + std::string(database->getK()) +
    ", distance metric = " + database->getDistanceFunction());
    std::string userResponse;
    try {
        userResponse = dio->read();
    } catch (...) {
        std::cerr << "Error reading from socket." << std::endl;
        return;
    }
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
        database->setK(k);
        database->setDistanceFunction(b);
        database->setClassfications("");
    }
    dio->write(returnMessage);
    try {
        dio->read();
    } catch (...) {
        std::cerr << "Error reading from socket." << std::endl;
        return;
    }
}

SettingsCommand::SettingsCommand(DefaultIO *pIo, Database *pDatabase) {
    dio = pIo;
    database = pDatabase;
}
