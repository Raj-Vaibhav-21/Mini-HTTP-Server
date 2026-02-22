//  file_utils.h
//  Mini HTTP Server
//  Created by Raj Vaibhav on 24/12/25.

#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

std::string read_file(const std::string& path);
bool file_exists(const std::string& path);

#endif


