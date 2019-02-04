//
// Created by caballeto on 04.02.19.
//

#include "utilities.h"
using namespace std;

vector<string> getAllFilenames(const string& path) {
  struct dirent* file;
  vector<string> files;
  DIR* directory = opendir(path.c_str());
  while ((file = readdir(directory)) != nullptr) {
    files.emplace_back(string(file->d_name));
  }
  closedir(directory);
  return files;
}

string getCurrentDir() {
  char buffer[SIZE];
  getcwd(buffer, SIZE);
  return string(buffer);
}

bool isDirectory(const string& path) {
  struct stat s;
  return stat(path.c_str(), &s) == 0 && (s.st_mode & S_IFDIR);
}

bool isFile(const string& path) {
  struct stat s;
  return stat(path.c_str(), &s) == 0 && (s.st_mode & S_IFREG);
}

bool isExist(const string& path) {
  struct stat s;
  return stat(path.c_str(), &s) == 0;
}

string getPathTo(const string &relative) {
  char buffer[SIZE];
  realpath(relative.c_str(), buffer);
  return string(buffer);
}

// utilities
string getFileContent(const string& path) {
  ifstream file(path);
  string line;
  ostringstream ss;

  if (file.is_open()) {
    while (getline(file, line))
      ss << line << '\n';
    return ss.str();
  } else {
    throw invalid_argument("No such file.");
  }
}
