//  parser.h
//  Mini HTTP Server
//  Created by Raj Vaibhav on 03/12/25.

#ifndef PARSER_H
#define PARSER_H

#include "request.h"
#include <string>

std::string read_request(int client_fd);
Request parse_request_line(const std::string& req);

#endif


