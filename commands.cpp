//
// Created by caballeto on 04.02.19.
//

#include "commands.h"

using namespace std;

template <typename T>
void printVec(const vector<T>& v) {
  for (const auto& w : v) {
    cout << w << ' ';
  }
  cout << endl;
}

void touch(const vector<string>& commands) {
  if (commands.size() != 1) {
    cout << "Error: invalid number of arguments: " << commands.size() << endl;
  } else {
    string path = commands[0];

    if (!isExist(path)) {
      ofstream file(path);
      file.close();
    } else {
      cout << "Error: file already exists" << endl;
    }
  }
}

void rm(const vector<string>& commands) {
  if (commands.size() != 1) {
    cout << "Error: invalid number of arguments: " << commands.size() << endl;
  } else {
    string path = commands[0];

    if (!isFile(path)) {
      cout << "Error: '" << path << "' is not a file" << endl;
    } else {
      remove(path.c_str());
    }
  }
}

void cat(const vector<string>& commands, const string& path) {
  if (commands.size() != 1) {
    cout << "Error: invalid number of arguments: " << commands.size() << endl;
  } else {
    string p = commands[0];

    if (!isFile(p)) {
      cout << "Error: '" << p << "' is not a file" << endl;
    } else {
      cout << getFileContent(p);
    }
  }
}

void ls(const string& path) {
  vector<string> v = getAllFilenames(path);
  v.erase(remove(v.begin(), v.end(), "."));
  v.erase(remove(v.begin(), v.end(), ".."));
  printVec(v);
}

void pwd(const vector<string>& commands, const string& path) {
  if (!commands.empty()) {
    cout << "Error: invalid number of arguments: " << commands.size() << endl;
  } else {
    cout << path << endl;
  }
}

void cd(const vector<string>& commands, string& path) {
  if (commands.size() != 1) {
    cout << "Error: invalid number of arguments: " << commands.size() << endl;
  } else {
    string p = commands[0];

    if (!isDirectory(p)) {
      cout << "Error: '" << p << "' is not a directory" << endl;
    } else {
      path = getPathTo(p);
      chdir(path.c_str());
    }
  }
}

void help() {
  cout << "Shell supports commands: " << endl;
  cout << "1. cd path" << endl;
  cout << "2. pwd" << endl;
  cout << "3. cat filename" << endl;
  cout << "4. touch filename" << endl;
  cout << "5. rm filename" << endl;
  cout << "6. ls" << endl;
  cout << "7. help" << endl;
  cout << "8. exit" << endl;
  cout << "Unknown command will be executed in default bash." << endl;
}

int execute(const string& command) {
  return system(command.c_str());
}
