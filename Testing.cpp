//
// Created by Liam Hogan on 4/19/18.
//

#include "Game.h"
#include "Ghost.h"
#include "PacMan.h"

//I broke up Liams sections into these methods:
bool testGame();
bool testGamePiece();
bool testGhost();
bool testPacMan();

int main() {

    bool gameClassTestResult = testGame();
    if(gameClassTestResult == false){
        std::cout << "Game Testing Failed!" << std::endl;
    }
    else{
        std::cout << "Game Testing Successful!" << std::endl;
    }

    bool gamePieceClassTestResult = testGamePiece();
    if(gamePieceClassTestResult == false){
        std::cout << "GamePiece Resting Failed!" << std::endl;
    }
    else{
        std::cout << "GamePiece Testing Successful!" << std::endl;
    }

    bool ghostClassTestResult = testGhost();
    if(ghostClassTestResult == false){
        std::cout << "Ghost Testing Failed!" << std::endl;
    }
    else{
        std::cout << "Ghost Testing Successful!" << std::endl;
    }

    bool pacManClassTestResult = testPacMan();
    if(pacManClassTestResult = false){
        std::cout << "PacMan Testing Failed!" << std::endl;
    }
    else{
        std::cout << "PacMan Testing Successful!" << std::endl;
    }
}

//========== Game Class Testing ==========
bool testGame() {

    bool passed = true;
    Game g;

    if (g.getHighScore() != 100 || g.getLives() != 3 || g.getPlayer() != "Lisa-Dion") {
        std::cout << "Game Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    g.setHighScore(999);
    g.setLives(2);

    if (g.getHighScore() != 999 || g.getLives() != 2) {
        std::cout << "HighScore Setter or Lives Setter Failed" << std::endl;
        passed = false;
    }

    g.setHighScore(-2);
    g.setLives(-2);

    if (g.getHighScore() != 0 || g.getLives() != 0) {
        std::cout << "HighScore Setter or Lives Setter if-statement Failed" << std::endl;
        passed = false;
    }

    std::cout << g << std::endl; // should print the game board with the overloaded operator for a game object.

    std::cout << "^^^ Game Board should be printed above." << std::endl;

    Game ng("Liam", 8675309);

    if (ng.getHighScore() != 8675309 || ng.getLives() != 3 || ng.getPlayer() != "Liam") {
        std::cout << "Game Non-Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    std::cout << "Testing Move methods: " << std::endl;
    g.setLives(5);

// Here I attempt to move pacman from his original pos. on the board.  Not working!  And triggering checks I added to the end of each move method.
    //Move Methods
    //Pacman
    g.moveRight(g.gameBoard[14][20]);
    g.moveUp(g.getGameBoard()[15][20]);
    g.moveDown(g.getGameBoard()[15][19]);
    g.moveLeft(g.getGameBoard()[15][20]);

    //Wall
    g.moveUp(g.gameBoard[2][2]);
    g.moveDown(g.getGameBoard()[2][2]);
    g.moveRight(g.getGameBoard()[2][2]);
    g.moveLeft(g.getGameBoard()[2][2]);

    //Path
    g.moveUp(g.gameBoard[18][20]);
    g.moveDown(g.getGameBoard()[18][19]);
    g.moveRight(g.getGameBoard()[18][20]);
    g.moveLeft(g.getGameBoard()[19][20]);

    //Ghost
    g.moveUp(g.gameBoard[18][20]);
    g.moveDown(g.getGameBoard()[18][19]);
    g.moveRight(g.getGameBoard()[18][20]);
    g.moveLeft(g.getGameBoard()[19][20]);

    return passed;

}

// ========== Gamepiece Class Testing===========
bool testGamePiece(){
    bool passed = true;

    GamePiece gp;
    if (gp.getXPos() != 0 && gp.getYPos() != 0){
        std::cout << "Gamepiece Deault Constructor Test Failed" << std::endl;
        passed = false;
    }

    gp.setXPos(20);
    gp.setYPos(20);
    gp.setType(pacMan);
    if (gp.getXPos() != 20 && gp.getYPos() != 20 && gp.getType() != pacMan){
        std::cout << "Gampiece setters Test Failed" << std::endl;
        passed = false;
    }

    // ========== Wall Class Testing ==========

    Wall w;

    if (w.getType() != wall){
        std::cout << "Wall Constructor Test Failed" << std::endl;
        passed = false;
    }

    w.setType(pellet);
    w.setXPos(20);
    w.setXPos(20);

    if (w.getType() != pellet && w.getXPos() != 20 && w.getYPos() != 20){
        std::cout << "Wall setter Test Failed" << std::endl;
        passed = false;
    }

    // ========== Path Class Testing ==========

    Path p;

    if (p.getType() != pellet && p.getPelletStatus() == false){
        std::cout << "Path Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    p.setXPos(20);
    p.setYPos(20);
    p.setType(empty);
    p.setPelletStatus(true);

    if (p.getType() != empty && p.getPelletStatus() == true && p.getXPos() != 20 && p.getYPos() != 20){
        std::cout << "Path Setters Test Failed" << std::endl;
        passed = false;
    }

    return passed;
};

// ========== Ghost Class Testing ==========
bool testGhost() {

        bool passed = true;

        Ghost gh;
        if (gh.getType() != ghost){
            std::cout << "Ghost Default Constructor Test Failed" << std::endl;
            passed = false;
        }

        gh.setType(pellet);
        gh.setXPos(20);
        gh.setYPos(20);

        if (gh.getType() != ghost && gh.getXPos() != 20 && gh.getYPos() != 20){
            std::cout << "Ghost Setters Test Failed" << std::endl;
            passed = false;
        }

        Ghost ghn(20, 20);
        if (ghn.getType() != ghost && ghn.getStartXPos() != 20 && ghn.getStartYPos() != 20){
            std::cout << "Ghost Non-Default Constructor Test Failed" << std::endl;
            passed = false;
        }
    return passed;
};

// ========== PacMan Class Testing ==========
bool testPacMan() {

    bool passed = true;
    PacMan pm;

    if (pm.getType() != pacMan || pm.getStartXPos() != 14 || pm.getStartYPos() != 20) {
        std::cout << "PacMan Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    pm.setXPos(25);
    pm.setYPos(25);
    pm.setType(wall);

    if (pm.getType() != pacMan || pm.getXPos() != 25 || pm.getYPos() != 25) {
        std::cout << "PacMan Setters Test Failed" << std::endl;
        passed = false;
    }

    pm.makeNoise();

    std::cout << "^^^ Should print BLOOP BLOOP BLOOP DEAD" << std::endl;

    std::cout << "Passed = " << std::boolalpha << passed << std::endl;
}
