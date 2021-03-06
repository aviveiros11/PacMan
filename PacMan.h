//
// Created by The Flash on 4/15/18.
//

#ifndef PAC_PACMAN_H
#define PAC_PACMAN_H

#include "PacDaddy.h"

class PacMan : public PacDaddy {

public:

    /** Default Constructor
     * Requires: Nothing
     * Modifies: type
     * Effects: Creates a PacMan Object
     */
    PacMan();

    /** Pure Virtual makeNoise
     * Requires: nothing
     * Modifies: nothing
     * Effects: Emits noise
     */
    void makeNoise() override;
};

#endif //PAC_PACMAN_H