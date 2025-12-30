//  response.h
//  Mini HTTP Server
//  Created by Raj Vaibhav on 03/12/25.

#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

struct Response {
    int status_code = 200;
    std::string content_type = "text/plain";
    std::string body;
};

std::string build_http_response(const Response& res);

#endif
