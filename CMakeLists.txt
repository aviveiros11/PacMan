cmake_minimum_required(VERSION 3.9)
project(paC)

set(CMAKE_CXX_STANDARD 14)

add_executable(paC main.cpp ghost.cpp ghost.h Game.cpp Game.h Gamepiece.cpp GamePiece.h)