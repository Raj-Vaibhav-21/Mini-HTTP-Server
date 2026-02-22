//  router.h
//  Mini HTTP Server
//  Created by Raj Vaibhav on 03/12/25.

#ifndef ROUTER_H
#define ROUTER_H

#include "request.h"
#include "response.h"

Response handle_route(const Request& req);

#endif
