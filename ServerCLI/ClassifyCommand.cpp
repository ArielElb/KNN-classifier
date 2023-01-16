//
// Created by arie1 on 1/14/2023.
//

#include "ClassifyCommand.h"

void ClassifyCommand::execute() {
    // classify a data file that is already uploaded to the server


}

ClassifyCommand::ClassifyCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->pDatabase = pDatabase;

}
