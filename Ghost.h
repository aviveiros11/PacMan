//
// Created by Liam Hogan on 4/11/18.
//

#ifndef PAC_GHOST_H
#define PAC_GHOST_H

#include "GamePiece.h"

class Ghost: public GamePiece {

public:

    /** Default Constructor
     * Requires: Nothing
     * Modifies: type, and currentStatus
     * Effects: Creates a Ghost Object with currentStatus set to noPellet
    */
    Ghost();

    /** Non-Default Constructor
     * Requires: Nothing
     * Modifies: startXPos, startYPos, and currentStatus
     * Effects: Creates a Ghost Object with startXPos startXPosIn, startYPos startYPosIn and with currentStatus set to noPellet
     */
    Ghost(int startXPosIn, int startYPosIn);

};

#endif //PAC_GHOST_H