#include "SocketIO.h"

//override the read function
std::string SocketIO::read() {
    std::string data = "";
    while (true) {
        //  clear buffer for safety
        char buffer[4096] = {0};
        int expected_data_len = sizeof(buffer);
        // receive from client
        int read_bytes = recv(this->sockfd, buffer, expected_data_len, 0);
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
            if (data[data.length() - 1] == '\t') {
                break;
            }
        }
    }
    return data;
}

int SocketIO::write(std::string s) {
    // send message to client
    s = s + "\t";
    int sent_bytes = send(this->sockfd,s.c_str(), s.length() , 0);
    if (sent_bytes < 0) {
        // sending to client failed, drop client
        throw std::ios_base::failure("Error writing to socket");
    }
    return sent_bytes;
}
