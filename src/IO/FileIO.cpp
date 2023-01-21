#include "IO/FileIO.h"


FileIO::FileIO(std::string path) {
    this->path = path;
}

/*
 * Returns the content of the file as a std::string
 */
std::string FileIO::read() {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::ios_base::failure("Error opening file");
    }
    std::string data;
    std::string line;
    while (std::getline(file, line)) {
        data += line + "\n";
    }
    return data;
}

/*
 * Adds std::string text at the end of the file, then new line.
 */
int FileIO::write(std::string text) {
    std::ofstream file;
    std::cout << "A" << std::endl;
    file.open(path, std::ios::app | std::ios::app);
    std::cout << "B" << std::endl;
    if (!file.is_open()) {
        return 1;
    }
    file << text << "\n";
    std::cout << "C" << std::endl;
    return 0;
}
