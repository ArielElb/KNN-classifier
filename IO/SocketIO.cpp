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
                size_t start_pos = 0;
                while((start_pos = data.find('\t', start_pos)) != std::string::npos) {
                    data.replace(start_pos, 1, "");
                    start_pos += 1; // Handles cases where there are multiple consecutive tabs
                }
                break;
            }
        }
    }
//    std::cout << "read: " << data << std::endl;
    return data;
}

int SocketIO::write(std::string s) {
    // send a big amont of data to client in a while loop
    int total_bytes_sent = 0;
    while (total_bytes_sent < s.length()) {
        int bytes_sent = send(this->sockfd, s.c_str() + total_bytes_sent, s.length() - total_bytes_sent, 0);
        if (bytes_sent < 0) {
            // sending to client failed, drop client
            throw std::ios_base::failure("Error writing to socket");
        }
        total_bytes_sent += bytes_sent;
    }
    send(this->sockfd, "\t", 1, 0);
    return total_bytes_sent;
}
