//
// Created by caballeto on 04.02.19.
//

#ifndef SHELL_UTILITIES_H
#define SHELL_UTILITIES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define SIZE 512

std::string getCurrentDir();
std::string getFileContent(const std::string& path);
std::string getPathTo(const std::string &relative);
std::vector<std::string> getAllFilenames(const std::string& path);
bool isDirectory(const std::string& path);
bool isFile(const std::string& path);
bool isExist(const std::string& path);

#endif //SHELL_UTILITIES_H
