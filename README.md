# SShell

SShell (Simple Shell) is an implementation of simple unix-like shell using 
C/C++.
## Commands

Implemented commands are presented below. If command is unknown 
application will try to execute it in default bash.

- `cd` - change directory
- `pwd` - get current directory
- `cat` - print contents of file
- `touch` - create empty file
- `rm` - delete file
- `ls` - print files in current directory
- `help` - help
- `exit` - end session

## Run

Run with command:

```
cmake CMakeLists.txt
make
./bin/main 
```
