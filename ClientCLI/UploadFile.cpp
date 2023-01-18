//
// Created by arie1 on 1/17/2023.
//

#include "UploadFile.h"

void UploadFile::execute() {
    //read "Please upload your local train CSV file.\n"
    std::string toScreen = this->dio->read();
    //print to screen
    std::cout << toScreen << std::endl;
    std::string path1;
    std::cin >> path1;
    FileIO fileIO(path1);
    std::string localTrain = fileIO.read();
    //send the file to the server
    this->dio->write(localTrain);
    //read "Upload complete.\n"
    toScreen = this->dio->read();
    // Upload complete.
    std::cout << toScreen << std::endl;

    std::string path2;
    std::cin >> path2;
    FileIO fileIO2(path2);
    std::string localTest = fileIO2.read();
    //send the file to the server
    this->dio->write(localTest);
    //read "Upload complete.\n"
    toScreen = this->dio->read();
    /// wait for the server to finish the upload - sleep

    //print to screen
    std::cout << toScreen;
}







UploadFile::UploadFile(DefaultIO *socketIO) {
    this->dio = socketIO;

}
