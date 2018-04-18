//
// Created by The Flash on 4/15/18.
//

#include "PacMan.h"

PacMan::PacMan() {
    type = pacMan;
    startXPos = 14;
    startYPos = 20;
}

void PacMan::makeNoise() {
    std::cout << "BLOOP BLOOP BLOOP DEAD" << std::endl;
}