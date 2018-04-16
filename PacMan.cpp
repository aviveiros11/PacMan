//
// Created by The Flash on 4/15/18.
//

#include "PacMan.h"

PacMan::PacMan() {
    type = pacMan;
}

//void PacMan::moveUp(Game &g) {
//    if(g.gameBoard[xPos][(yPos - 1)].getType() != wall){
//        //Create copy of piece being moved
//        GamePiece pCopy = g.gameBoard[xPos][yPos];
//        if(g.gameBoard[xPos][(yPos - 1)].getType() == ghost){
//            //Need to decrease lives somehow
//            //send pacman back to his starting position
//        }
//        else{
//            if(g.gameBoard[xPos][(yPos - 1)].getType() == pellet){
//                Path rep(empty, false);
//                //increase high score
//                //delete the object being stored there, set the type to empty and store that as a temp object.
//                //g.gameBoard[xPos][(yPos + 1)]= nullptr;
//                g.gameBoard[xPos][(yPos - 1)] = pCopy;
//                pCopy.setYPos(yPos - 1);
//                g.gameBoard[xPos][yPos] = rep;
//
//            }
//            else{
//                //starting state must be empty, so save in temp and then add when leave.
//            }
//        }
//    }
//}