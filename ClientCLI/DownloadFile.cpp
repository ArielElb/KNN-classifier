//
// Created by arie1 on 1/16/2023.
//

#include "DownloadFile.h"

void DownloadFile::execute() {

}

DownloadFile::DownloadFile(DefaultIO *socketIO, DefaultIO *file) {
    this->dio = socketIO;
    this->fileIO = file;

}
