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

class Game {

private:
    std::vector<std::vector<GamePiece>> gameBoard;
    double highscore;
    int numLives;

public:

    /** Default Construct
     * Requires: Nothing
     * Modifies: gameBoard
     * Effects: Creates a Game Object and fills the gameBoard vector with gamePiece objcets to be used for move checking
     */
    Game();

    /** Non - Default Construct
     * Requires: Nothing
     * Modifies: Vector, High Score
     * Effects: Creates a Game Object with a gameBoard vector and a high score
     */
    Game(std::vector<std::vector<GamePiece>> &gBoard, double h);

    /** Getters
     * Requires: nothing
     * Modifies: nothing
     * Effects: Gets the Field Values
     */
    double getHighScore() const;
    int getLives() const;
    std::vector<std::vector<GamePiece>> getGameBoard() const;

    /** Setters
     * Requires: Nothing
     * Modifies: The Private Field Value
     * Effects: Sets the Field Values
     */
    void setHighScore(double h);
    void setLives(int lives);
    void setGameBoard(std::vector<std::vector<GamePiece>> &g);

    /**
     * Saves the high scores to a file
     * Requires: High Score
     * Modifies: nothing
     * Effects: the Highscore.txt file
     */
    void saveHighScore(int highScore);


    /**
     * Reads the high scores from a file
     * Requires: Nothing
     * Modifies: nothing
     * Effects: the console output of highScores
     */
    void displayHighScore();

    /**
     * Overloaded Operator (binary)
     * Friend of the class (not a member)
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns a text-based visualization of the gameBoard vector.
    */
    friend std::ostream& operator <<(std::ostream& outs, const Game &g);

};

#endif //PAC_GAME_H