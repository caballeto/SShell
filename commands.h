//
// Created by caballeto on 04.02.19.
//

#ifndef SHELL_COMMANDS_H
#define SHELL_COMMANDS_H

#include <algorithm>
#include "utilities.h"

template <typename T>
void printVec(const std::vector<T>& v);

void cd(const std::vector<std::string>& commands, std::string& path);
void pwd(const std::vector<std::string>& commands, const std::string& path);
void cat(const std::vector<std::string>& commands, const std::string& path);
void touch(const std::vector<std::string>& commands);
void rm(const std::vector<std::string>& commands);
void ls(const std::string& path);
int execute(const std::string& command);
void help();

#endif //SHELL_COMMANDS_H
