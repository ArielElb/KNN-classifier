#include "ClientCLI/UploadFile.h"

void UploadFile::execute() {
    //read "Please upload your local train CSV file.\n"
    std::string toScreen;
    try {
        toScreen = dio->read();
    } catch (std::ios_base::failure const &ex) {
        std::cerr << "Error reading from socket." << std::endl;
        return;
    }
    //print to screen
    std::string path1;
    std::string localTrain;
    std::cout << toScreen;
    while (true) {
        std::getline(std::cin, path1);
        FileIO fileIO(path1);
        try {
            localTrain = fileIO.read();
        } catch (std::ios_base::failure const &ex) {
            std::cerr << "Invalid path. Please input a valid path and try again." << std::endl;
            continue;
        }
        if (localTrain.empty()) {
            std::cerr << "The selected file is empty."
                         " Please input a non-empty file and try again." << std::endl;
            continue;
        }
        break;
    }
    //send the file to the server
    dio->write(localTrain);
    // read message
    try {
        toScreen = dio->read();
    } catch (std::ios_base::failure const &ex) {
        std::cerr << "Error reading from socket." << std::endl;
        return;
    }
    // get train file from user
    std::string path2;
    std::string localTest;
    std::cout << toScreen;
    while (true) {
        std::getline(std::cin, path2);
        //std::cin >> path2;
        FileIO fileIO2(path2);
        try {
            localTest = fileIO2.read();
        } catch (std::ios_base::failure const &ex) {
            std::cerr << "Invalid path. Please input a valid path and try again." << std::endl;
            continue;
        }
        if (localTest.empty()) {
            std::cerr << "The selected file is empty."
                         " Please input a non-empty file and try again." << std::endl;
            continue;
        }
        break;
    }
    //send the file to the server
    dio->write(localTest);
    //read "Upload complete.\n"
    try {
        toScreen = this->dio->read();
    } catch (std::ios_base::failure const &ex) {
        std::cerr << "Error reading from socket." << std::endl;
        return;
    }
    /// wait for the server to finish the upload - sleep

    //print to screen
    std::cout << toScreen;
}







UploadFile::UploadFile(DefaultIO *socketIO) {
    this->dio = socketIO;

}
