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

int GamePiece::getStartXPos() const {
    return startXPos;
}

int GamePiece::getStartYPos() const {
    return startYPos;
}

void GamePiece::setXPos(int xPos) {
    if (xPos > 0){
        GamePiece::xPos = xPos;
    }
}

void GamePiece::setYPos(int yPos) {
    if (yPos > 0){
        GamePiece::yPos = yPos;
    }
}

void GamePiece::setType(Type t) {
    if(t == wall){
        if(t == wall){
            type = t;
        }
    }
    else if(t == pellet || t == empty){
        if(t == pellet){
            type = t;
        }
        if(t == empty){
            type = t;
        }
    }
    else if(t == ghost){
        if(t == ghost){
            type = t;
        }
    }
    else if (t == pacMan){
        if(t == pacMan){
            type = t;
        }
    }
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

