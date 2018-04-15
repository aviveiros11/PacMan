//
// Created by Jean-Baptiste Bolh on 4/11/18.
//
//Description: A 2D vector of GamePieces

#ifndef PAC_GAME_H
#define PAC_GAME_H

#include <iomanip>
#include <vector>
#include <iostream>
#include "GamePiece.h"

using namespace std;

class Game {

private:
    vector<vector<GamePiece>> gameBoard;
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
    Game(std::vector<std::vector<GamePiece>> &gBoard, double h);

    /** Getters
     * Requires: nothing
     * Modifies: nothing
     * Effects: Gets the Highscore
     */

    double getHighScore() const;
    int getLives() const;
    vector<vector<GamePiece>> getGameBoard() const;

    /** Setters
     * Requires: Nothing
     * Modifies: The Private Field Value
     * Effects: Sets the Field Value
     */
    void setHighScore(double h);
    void setLives(int lives);
    void setGameBoard(vector<vector<GamePiece>> &g);

    friend std::ostream& operator <<(std::ostream& outs, const Game &g);

};


#endif //PAC_GAME_H
