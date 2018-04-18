//
// Created by Jean-Baptiste Bolh on 4/18/18.
//

#ifndef PAC_PACDADDY_H
#define PAC_PACDADDY_H

#include "GamePiece.h"

class PacDaddy : public GamePiece{
public:
    /** Default Constructor
     * Requires: Nothing
     * Modifies: type
     * Effects: Creates a PacMan Object
     */
    PacDaddy();

    /** Pure Virtual makeNoise
     * Requires: nothing
     * Modifies: nothing
     * Effects: Emits noise
     */
    virtual void makeNoise() = 0;

};


#endif //PAC_PACDADDY_H
