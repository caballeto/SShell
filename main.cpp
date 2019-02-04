#include <iterator>
#include "commands.h"

using namespace std;

int main() {
  string line;
  string current_path = getCurrentDir();

  cout << "$" << current_path << "> ";
  while (getline(cin, line)) {
    istringstream is(line);
    vector<string> commands{istream_iterator<string>(is), istream_iterator<string>{}};

    if (commands.empty()) continue;
    string command = commands[0];
    commands.erase(commands.begin());

    if (command == "cd") {
      cd(commands, current_path);
    } else if (command == "pwd") {
      pwd(commands, current_path);
    } else if (command == "cat") {
      cat(commands, current_path);
    } else if (command == "touch") {
      touch(commands);
    } else if (command == "rm") {
      rm(commands);
    } else if (command == "ls") {
      ls(current_path);
    } else if (command == "help") {
      help();
    } else if (command == "exit") {
      break;
    } else {
      cout << "Unknown command. Executing in default bash." << endl;
      execute(line);
    }

    cout << "$" << current_path << "> ";
  }

  return 0;
}
