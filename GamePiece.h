//
// Created by Jean-Baptiste Bolh on 4/11/18.
//
//Heyyyyyyy

#ifndef PAC_GAMEPIECE_H
#define PAC_GAMEPIECE_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include <GLUT/glut.h>

#include "shapes.h"

enum Type {ghost, wall, pellet, pacMan, empty};

enum CurrentStatus {yesPellet, noPellet};

class GamePiece {

protected:
    int xPos;
    int yPos;
    Type type;
    int startXPos;
    int startYPos;

public:

    CurrentStatus currentStatus;

    /** Default Constructor
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Creates a GamePiece Object
     */
    GamePiece();

    /** Getters and Setters
     * Requires: nothing
     * Modifies: nothing
     * Effects: Gets/Sets the field values
     */
    int getXPos() const;
    int getYPos() const;
    Type getType() const;
    int getStartXPos() const;
    int getStartYPos() const;
    void setXPos(int xPos);
    void setYPos(int yPos);
    void setType(Type type);

    /**
     * Overloaded Operator (binary)
     * Friend of the class (not a member)
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns a text-based visualization of each GamePiece.
    */
    friend std::ostream& operator <<(std::ostream& outs, const GamePiece &g);

    /**
     * Draws pellets for graphics
     * Requires: Nothing
     * Modifies: nothing
     * Effects: draws pellets for graphics.  Will only draw pellet if the GamePiece is a type pellet.
     */
    void drawPellet(GLfloat x, GLfloat y, GLfloat radius);
};

class Wall : public GamePiece {

public:

    /** Default Constructor
     * Requires: Nothing
     * Modifies: type
     * Effects: Creates a Wall Object
     */
    Wall();

};

class Path : public GamePiece {

private:

    bool pelletStatus = true;

public:

    /** Default Constructor
     * Requires: Nothing
     * Modifies: type, pelletStatus
     * Effects: Creates a Path Object
     */
    Path();

    /** Non-Default Constructor
     * Requires: Nothing
     * Modifies: type, pelletStatus
     * Effects: Creates a Path Object
     */
    Path(Type typeIn, bool pelletStat);

    /** Getters and Setters
     * Requires: nothing
     * Modifies: nothing
     * Effects: Gets/Sets field values
     */
    bool getPelletStatus() const;
    void setPelletStatus(bool b);

};

#endif //PAC_GAMEPIECE_H