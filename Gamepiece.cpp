//
// Created by Jean-Baptiste Bolh on 4/11/18.
//
using namespace std;

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
    if (g.getType() == 0) {
        outs << "Gho";
    } else if (g.getType() == 1) {
        outs << "Wal";
    } else if (g.getType() == 2) {
        outs << '   ';
    } else {
        outs << "Pac";
    }
    return outs;
}

Wall::Wall(){
    type = wall;
}