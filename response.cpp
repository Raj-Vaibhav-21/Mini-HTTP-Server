//  response.cpp
//  Mini HTTP Server
//  Created by Raj Vaibhav on 13/12/25.

#include "response.h"
#include <sstream>

std::string build_http_response(const Response& res) {
    std::ostringstream out;
    //std::ostringstream creates an in-memory output stream that lets you build a string incrementally, and then materialize the final string at once.
    out << "HTTP/1.1 " << res.status_code << " OK\r\n";
    out << "Content-Type: " << res.content_type << "\r\n";
    out << "Content-Length: " << res.body.size() << "\r\n";
    out << "\r\n"; //This line tells the browser that header ends here
    out << res.body;

    return out.str();
}
/*Common status codes:
 • 200 — OK (success; the requested resource is delivered)
 • 404 — Not Found (the resource doesn’t exist)
 • 500 — Internal Server Error (something went wrong on the server)
 • 301 — Moved Permanently (resource has moved to a new URL)
 • 400 — Bad Request (the request was invalid)*/


