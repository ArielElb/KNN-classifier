#include "IO/SocketIO.h"

//override the read function
std::string SocketIO::read() {
    std::string data;
    while (true) {
        //  clear buffer for safety
        char buffer[4096] = {0};
        int expected_data_len = sizeof(buffer);
        // receive from client
        int read_bytes = recv(sockfd, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            // nothing received, drop client
            break;
        } else if (read_bytes < 0) {
            // receiving from client failed, drop client
            throw std::ios_base::failure("Error reading from socket");
        } else {
            // input received, do work on input 
            data += std::string(buffer, read_bytes);    // turn buffer into string type
            if (data == "-1") {
                // client wants to disconnect, drop client
                throw std::out_of_range("Nothing to read from socket");
            }
            // check if accumulated input contains '\n' (i.e. message has been completed), 
            // otherwise, continue receiving
            if (data[data.length() - 1] == '\n') {      // Complete message recieved, proceed
                break;
            }
        }
    }
    return data;
}

int SocketIO::write(std::string s) {
    return send(sockfd, s.c_str(), s.length(), 0);   
}
