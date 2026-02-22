//  main.cpp
//  Mini HTTP Server
//  Created by Raj Vaibhav on 28/11/25.

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "parser.h"
#include "request.h"
#include "response.h"
#include "router.h"

using std::cin;
using std::cout;

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); /*Sockets are funadamental for end to end communication
                                                      AF_INET is for IPv4 , SOCK_STREAM is for TCP Protocol
                                                      AF_INET6 is for IPv6 , SOCK_DGRAM is for UDP Protocol*/
    
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; /* .sin_addr holds the IPv4 address
                                          .s_addr is the numeric value of that address
                                          INADDR_ANY means all IPv4 addresses are accepted on the local machine*/
    address.sin_port = htons(8080); //Sets the port number to 8080

    
    bind(server_fd, (sockaddr*)&address, sizeof(address));//Binds the socket to the address and port                                                        specified by address
    
    listen(server_fd, 10);/*Puts the socket into "listening" mode, so it can accept incoming connection                         requests
                        10 is the backlog parameter: the maximum number of pending connections that can be
                              queued up before the system starts rejecting new ones*/
    cout << "Server running on port 8080...\n";

    int addrlen = sizeof(address);//Initializes addrlen to the size of the address structure
    while (true) {
            int client_fd = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen);

            std::string raw = read_request(client_fd);
            Request req = parse_request_line(raw);

            Response res = handle_route(req);
            std::string http = build_http_response(res);

            send(client_fd, http.c_str(), http.size(), 0);
            close(client_fd);
        }
}
