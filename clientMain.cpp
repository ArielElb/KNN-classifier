#include "Client.h"

int main(int argc, char *argv[]) {
    std::string ip = argv[1];
    std::string portStr = argv[2];
    try {
        Client client(ip, portStr);
        client.run();
    } catch (std::ios_base::failure const &ex) {
        std::cout << ex.what() <<std::endl;
        return 1;
    }
}
