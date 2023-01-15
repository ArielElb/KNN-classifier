//
// Created by arie1 on 1/14/2023.
//

#include "DisplayCommand.h"

void DisplayCommand::execute() {
    // display the data file that is already uploaded to the server


}

DisplayCommand::DisplayCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->database = pDatabase;
}


