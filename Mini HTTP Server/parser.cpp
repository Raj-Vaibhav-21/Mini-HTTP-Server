//  parser.cpp
//  Mini HTTP Server
//  Created by Raj Vaibhav on 10/12/25.

#include "parser.h"
#include <unistd.h>
#include <sstream>

std::string read_request(int client_fd) {
    char buffer[4096];
    ssize_t bytes = read(client_fd, buffer, sizeof(buffer) - 1);

    if (bytes <= 0) return "";

    buffer[bytes] = '\0';
    return std::string(buffer);
}

Request parse_request_line(const std::string& raw) {
    std::istringstream iss(raw);
    Request req;
    iss >> req.method >> req.path >> req.version;
    if (!req.path.empty() && req.path.back() == '\r') {
            req.path.pop_back();
        }
    return req;
}


