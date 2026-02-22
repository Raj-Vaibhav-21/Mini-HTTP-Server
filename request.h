//  request.h
//  Mini HTTP Server
//  Created by Raj Vaibhav on 03/12/25.

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

struct Request {
    std::string method;
    std::string path;
    std::string version;
};

#endif


