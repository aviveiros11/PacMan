//
// Created by Liam Hogan on 4/11/18.
//

#include "Ghost.h"
//yeet

Ghost::Ghost() {
    type = ghost;
    currentStatus = noPellet;
}

Ghost::Ghost(int startXPosIn, int startYPosIn) {
    type = ghost;
    startXPos = startXPosIn;
    startYPos = startYPosIn;
    currentStatus = noPellet;
}