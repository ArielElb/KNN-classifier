//
// Created by arie1 on 1/17/2023.
//

#include "UploadFile.h"

void UploadFile::execute() {
    //read "Please upload your local train CSV file.\n"
    std::string toScreen = this->dio->read();
    //print to screen
    std::cout << toScreen << std::endl;
    std::string path;
    std::cin >> path;






}
void UploadFile::UploadFile(DefaultIO *socketIO) {
    this->dio = socketIO;

}
