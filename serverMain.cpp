#include "Server.h"

int main(int argc, char *argv[]) {
    // save file path argument
    string portStr = argv[1];           // save port argument
    try {
        Server server(portStr);   // create server object
        server.run();
    } catch (std::ios_base::failure const &ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }
}