cmake_minimum_required(VERSION 3.13)
project(Shell)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shell main.cpp utilities.cpp utilities.h commands.cpp commands.h)