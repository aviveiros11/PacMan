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

void GamePiece::setType(Type type) {
    if(type == wall){
        if(GamePiece::type == wall){
            GamePiece::type = type;
        }
    }
    if(GamePiece::type == pellet || GamePiece::type == empty){
        if(type == pellet){
            GamePiece::type = type;
        }
        if(type == empty){
            GamePiece::type = type;
        }
    }
    if(GamePiece::type == ghost){
        if(type == ghost){
            GamePiece::type = type;
        }
    }
    if (GamePiece::type == pacMan){
        if(type == pacMan){
            GamePiece::type = type;
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

