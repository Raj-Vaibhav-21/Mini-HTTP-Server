//  file_utils.cpp
//  Mini HTTP Server
//  Created by Raj Vaibhav on 24/12/25.

#include "file_utils.h"
#include <fstream>
#include <sstream>

bool file_exists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}

std::string read_file(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return "";

    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}


