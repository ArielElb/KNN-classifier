#include "Server.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#include <cstring>

struct {
    Server* server;
    int sock;
} typedef ServerData;

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


// Multithreaded client handling credited to "How to write a multithreaded server in C (threads, sockets)"
// by Jacob Sorber, YouTube (https://www.youtube.com/watch?v=Pg_4Jz8ZIH4)
void* connectionHandler(void* inputServer) {
    ServerData* serverData = (ServerData*) inputServer;
    Server* server = serverData->server;
    int sock = serverData->sock;
    std::string data;
    // client connected established, accept input until client closes connection
    while (true) {
        //  clear buffer for safety
        char buffer[4096] = {0};
        int expected_data_len = sizeof(buffer);
        // receive from client
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            // nothing received, drop client
            break;
        } else if (read_bytes < 0) {
            // receiving from client failed, drop client
            std::cout << "Something went wrong receiving from the client." << std::endl;
            break;
        } else {
            // input received, do work on input
            data += std::string(buffer, read_bytes);    // turn buffer into string type
            if (data == "-1") {
                // client wants to disconnect, drop client
                std::cout << "Client disconnected" << std::endl;
                close(sock);
                break;
            }
            // check if accumulated input contains '\n' (i.e. message has been completed),
            // otherwise, continue receiving
            if (data[data.length() - 1] == '\n') {      // Complete message recieved, proceed
                int k;
                Vector v;
                try {           // parse input, check validity of k and vector size
                    k = std::stoi(data.substr(data.find_last_of(',') + 1));
                    v = Server::extractVector(data);
                    Server::checkUserInput(v.size(), *server->getDatabase(), k);
                }
                catch (std::ios_base::failure const &ex) {
                    send(sock, "invalid input", 13, 0);
                    data = "";
                    continue;
                }
                catch (std::invalid_argument const &ex) {
                    send(sock, "invalid input", 13, 0);
                    data = "";
                    continue;
                }
                // extract the distance function from the input
                string distanceFunction = data.substr(data.find_last_of(',') - 3, 3);
                // input has been parsed and checked, do knn on vector, and send classification
                string classification = server->getDatabase()->knn(v, distanceFunction, k);
                int sent_bytes = send(sock, classification.c_str(),classification.length(), 0);
                data = "";
                if (sent_bytes < 0) {
                    perror("Error sending to client");
                }
            }
        }
    }
    return nullptr;
}

Server::Server(std::string portStr, std::string path) {
    port = extractPort(portStr);        // get int representation of port number
    if (port < 0) {
        throw std::ios_base::failure("Error getting port number");
    }
    database = new Database(path);  // create database object
    try {
        database->init();
    } catch (std::ios_base::failure const &ex) {
        throw std::ios_base::failure("Error initializing database. Check input files.");
    }
}

void Server::run() {
    // Multithreaded client handling credited to "How to write a multithreaded server in C (threads, sockets)"
    // by Jacob Sorber, YouTube (https://www.youtube.com/watch?v=Pg_3Jz8ZIH4)
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
    pthread_t thread_id;
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
        // create thread to handle client
        ServerData data;
        data.sock = client_sock;
        data.server = this;
        if (pthread_create(&thread_id, nullptr, connectionHandler, (void *) &data) < 0) {
            throw std::ios_base::failure("Could not create thread");
        }
    }
}

Database *Server::getDatabase() {
    return database;
}






