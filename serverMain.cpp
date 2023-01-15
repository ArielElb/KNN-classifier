#include "Server.h"

int main(int argc, char *argv[]) {
    string path = argv[1];              // save file path argument
    string portStr = argv[2];           // save port argument
    CLI cli = CLI();                    // create CLI object
    try {
        Server server(portStr, path);   // create server object
        server.run();
    } catch (std::ios_base::failure const &ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }
}