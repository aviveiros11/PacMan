//
// Created by Jean-Baptiste Bolh on 4/11/18.
//
//Heyyyyyyy

#ifndef PAC_GAMEPIECE_H
#define PAC_GAMEPIECE_H

#include <iostream>
#include <iomanip>

enum Type {ghost, wall, path, pacMan, empty};

class GamePiece {

protected:
    int xPos;
    int yPos;
    Type type;

public:
    /** Default Construct
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Creates a GamePiece Object
     */
    GamePiece();

    /** Getters and Setters
     * Requires: nothing
     * Modifies: nothing
     * Effects: Gets/Sets the x and y coordinates
     */
    int getXPos() const;

    int getYPos() const;

    void setXPos(int xPos);

    void setYPos(int yPos);

    Type getType() const;

    void setType(Type type);

//    virtual void moveUp(int newX, int newY);
//
//    virtual void moveDown(int newX, int newY);
//
//    virtual void moveLeft(int newX, int newY);
//
//    virtual void moveRight(int newX, int newY);

    friend std::ostream& operator <<(std::ostream& outs, const GamePiece &g);
};

class Wall : public GamePiece {

public:
    Wall();

    friend std::ostream& operator <<(std::ostream& outs, const GamePiece &g);
};

class Path : public GamePiece{

private:

    bool pellet = true;

public:

    Path();

    bool getPellet() const;

    void setPellet(bool b);

};

#endif //PAC_GAMEPIECE_H