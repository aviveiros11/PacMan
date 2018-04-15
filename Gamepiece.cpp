//
// Created by Jean-Baptiste Bolh on 4/11/18.
//
//using namespace std;

#include "GamePiece.h"


GamePiece::GamePiece() {
    xPos = 0;
    yPos = 0;
}

int GamePiece::getXPos() const {
    return xPos;
}

int GamePiece::getYPos() const {
    return yPos;
}

void GamePiece::setXPos(int xPos) {
    GamePiece::xPos = xPos;
}

void GamePiece::setYPos(int yPos) {
    GamePiece::yPos = yPos;
}

Type GamePiece::getType() const {
    return type;
}

void GamePiece::setType(Type type) {
    GamePiece::type = type;
}

std::ostream& operator <<(std::ostream& outs, const GamePiece &g) {
    outs << "GP" << std::endl;
    return outs;
}
Wall::Wall(){
    type = wall;
}

int Wall::getXPos() const {
    return xPos;
}

void Wall::setXPos(int xPos) {
    Wall::xPos = xPos;
}

int Wall::getYPos() const {
    return yPos;
}

Type Wall::getType() const {
    return type;
}

void Wall::setYPos(int yPos) {
    Wall::yPos = yPos;
}
