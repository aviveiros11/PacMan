//
// Created by Jean-Baptiste Bolh on 4/11/18.
//

#include "GamePiece.h"

using namespace std;

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

Type GamePiece::getType() const {
    return type;
}

void GamePiece::setXPos(int xPos) {
    GamePiece::xPos = xPos;
}

void GamePiece::setYPos(int yPos) {
    GamePiece::yPos = yPos;
}

void GamePiece::setType(Type type) {
    GamePiece::type = type;
}

std::ostream& operator <<(std::ostream& outs, const GamePiece &g) {
    if (g.getType() == ghost) {
        outs << " ∩ ";
    } else if (g.getType() == wall) {
        outs << "☐☐☐";
    } else if (g.getType() == pellet) {
        outs << " ☉ ";
    } else if (g.getType() == pacMan){
        outs << " C ";
    } else if(g.getType() == empty){
        outs << "   ";
    }
    return outs;
}

Wall::Wall(){
    type = wall;
}

Path::Path(){
    type = pellet;
    pelletStatus = true;
}

Path::Path(Type typeIn, bool pelletStat) {
    type = typeIn;
    pelletStat = false;
}

void Path::setPelletStatus(bool b) {
    pelletStatus = b;
}

bool Path::getPelletStatus() const {
    return pelletStatus;
}