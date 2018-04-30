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
#include "PacMan.h"
#include "ghost.h"

enum GameStatus {over, won, inProgress, paused};

class Game {

private:
    int highscore;
    int numLives;
    std::string player;

public:
    bool resetCalled = false;               // <---- TODO: ADD THESE TO CONSTRUCTOR
    GameStatus gameStatus = inProgress;     // <---- TODO: ADD THESE TO CONSTRUCTOR
    bool firstPlay = true;                  // <---- TODO: ADD THESE TO CONSTRUCTOR
    bool runFromStartingPositions = true;   // <---- TODO: ADD THESE TO CONSTRUCTOR
    //std::vector<GamePiece> pieces;

//    PacMan pm;
//    Ghost ghost1;
//    Ghost ghost2;
//    Ghost ghost3;
//    Ghost ghost4;

    std::vector<std::vector<GamePiece>> gameBoard;
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
    Game(std::string player, int h);

    /** Getters
     * Requires: nothing
     * Modifies: nothing
     * Effects: Gets the Field Values
     */
    int getHighScore() const;
    int getLives() const;
    std::vector<std::vector<GamePiece>> getGameBoard() const;
    std::string getPlayer() const;

    /** Setters
     * Requires: Nothing
     * Modifies: The Private Field Value
     * Effects: Sets the Field Values
     */
    void setHighScore(int h);
    void setLives(int lives);
    void setGameBoard(std::vector<std::vector<GamePiece>> &g);

    /**
     * Resets gameBoard after ghost-PacMan collision
     * Requires: nothing
     * Modifies: gameBoard
     * Effects: Places ghosts and PacMan back in starting x and y positions
     */
    void resetGameBoard();

    /**
     * Saves the high scores to a file
     * Requires: High Score
     * Modifies: nothing
     * Effects: the Highscore.txt file
     */
    void saveHighScore(int highScore, std::string player);


    /**
     * Reads the high scores from a file
     * Requires: Nothing
     * Modifies: nothing
     * Effects: the console output of highScores
     */
    static std::string displayHighScore();

    /**
     * Overloaded Operator (binary)
     * Friend of the class (not a member)
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns a text-based visualization of the gameBoard vector.
    */

    bool moveUp(GamePiece &g);
    bool moveLeft(GamePiece &g);
    bool moveDown(GamePiece &g);
    bool moveRight(GamePiece &g);

    /**
     * Overloaded Operator (binary)
     * Friend of the class (not a member)
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns a text-based visualization of each gameBoard Vector.
    */
    friend std::ostream& operator <<(std::ostream& outs, const Game &g);

};

#endif //PAC_GAME_H