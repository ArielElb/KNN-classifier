#include "FileIO.h"


FileIO::FileIO(std::string path) {
    this->path = path;
}

std::string FileIO::read() {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::ios_base::failure("Error opening file");
    }
    std::string data;
    std::string line;
    while (file) {
        std::getline(file, line);
        data += line + "\n";
    }
    return data;
}

int FileIO::write(std::string text) {
    return 0;
}

