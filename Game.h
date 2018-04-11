//
// Created by Jean-Baptiste Bolh on 4/11/18.
//
//Description: A 2D vector of GamePieces

#ifndef PAC_GAME_H
#define PAC_GAME_H


#include <vector>
#include "GamePiece.h"
#include <iostream>

class Game {

private:

    std::vector<std::vector<GamePiece>> gameBoard;
    double highscore;
    int numLives;

public:

    /** Default Construct
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Creates a Game Object
     */
    Game();

    /** Non - Default Construct
     * Requires: Nothing
     * Modifies: Vector, High Score
     * Effects: Creates a Game Object with a vector and a high score
     */
    Game(std::vector<std::vector<GamePiece>> gameBoard, double highscore);


    /** Getters
     * Requires: Private Field Value
     * Modifies: nothing
     * Effects: Gets the Highscore
     */
    double getHighScore() const;
    int getLives() const;


    /** Setters
     * Requires: Nothing
     * Modifies: The Private Field Value
     * Effects: Sets the Field Value
     */
    void setHighScore(double h);
    void setLives(int lives);

    friend std::ostream& operator <<(std::ostream& outs, const Game &Game);






};


#endif //PAC_GAME_H
