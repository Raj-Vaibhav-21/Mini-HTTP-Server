//  router.cpp
//  Mini HTTP Server
//  Created by Raj Vaibhav on 03/12/25.

#include "router.h"
#include "file_utils.h"
#include <ctime>
#include <iostream>

Response handle_route(const Request& req) {
    Response res;
    // Dynamic routes
    if (req.path == "/time") {
        std::time_t now = std::time(nullptr);
        res.body = std::ctime(&now);
        return res;
    }

    // Static files
    std::string file_path;

    // Handle root path
    if (req.path == "/") {
        file_path = "www/index.html";
    } else {
        file_path = "www" + req.path;
    }

    std::cout << "Trying to open: " << file_path << std::endl;

    if (file_exists(file_path)) {
        res.content_type = "text/html";
        res.body = read_file(file_path);
        return res;
    }

    // Not found
    res.status_code = 404;
    res.body = "404 Not Found";
    return res;
    
}
