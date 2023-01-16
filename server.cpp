#include "Server.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include "ServerCLI//ConnectionHandler.h"
#include <cstring>
#include <thread>



using std::string;


/**
 * Check if inputed vector size, k, are valid for database. Throw exception if not
 */
void Server::checkUserInput(unsigned long vectorSize, Database &database, int k) {
    if (vectorSize != database.getVectorSize()) {
        throw std::ios_base::failure("Invalid Input");
    }
    if (k > database.size()) {
        throw std::ios_base::failure("Invalid Input");
    }
}
/**
 * Extract vector from user input
 * @return Vector object from user input
 */
Vector Server::extractVector(string &input) {
    std::vector<std::string> elems;
    string vector;
    std::stringstream ss(input);
    string item;
    while (std::getline(ss, item, ',')) {
        elems.push_back(item);
    }
    if (elems.size() < 3) {
        throw std::ios_base::failure("Invalid Input");
    }
    for (int i = 0; i < elems.size() - 2; i++) {
        if (i == elems.size() - 3)
            vector += elems[i];
        else
            vector += elems[i] + ",";
    }
    Vector v(vector);
    return v;
}

/**
 * Converts string into valid int for port
 * @return valid port number, or -1 if none exists
 */
int Server::extractPort(string portStr) {
    int port;
    try {
        port = std::stoi(portStr);
    }
    catch (std::invalid_argument const &ex) {
        std::cout << "Invalid Input" << std::endl;
        return -1;
    }
    if (port > 65535 || port < 1) {
        std::cout << "Invalid port number. Exiting program" << std::endl;
        return -1;
    }
    return port;
}

/**
 * Get socket file descriptor, throw exception in case of failure
 * @return file descriptor of binded socket
 */
int Server::bindSock(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);     // get socket
    if (sock < 0) {
        throw std::ios_base::failure("error creating socket");
    }
    // prepare for binding
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {    // bind to socket
        throw std::ios_base::failure("error binding socket");
    }
    return sock;
}

Server::Server(std::string portStr) {
    port = extractPort(portStr);        // get int representation of port number
}

void Server::run() {
    int sock;
    try {
        sock = bindSock(port);
    } catch (std::ios_base::failure const &ex) {
        throw std::ios_base::failure(ex.what());
    }
    // listen
    if (listen(sock, 4) < 0) {
        throw std::ios_base::failure("Error listening to a socket");
    }
    std::thread thread;
    //pthread_t thread_id;
    // all is good, proceed to run server functionality
    while (true) {
        // initialize connection to next client
        struct sockaddr_in client_sin{};
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < -1) {
            throw std::ios_base::failure("Error accepting client");
        }
        std::cout << "Accepted client" << std::endl;
        SocketIO s(client_sock);
        ConnectionHandler c;
        std::thread clientThread(c, &s);
    }
}





