//
// Created by Liam Hogan on 4/19/18.
//

#include "Game.h"
#include "Ghost.h"
#include "PacMan.h"

int main(){
    bool passed = true;


    //========== Game Class Testing ==========
    Game g;

    if(g.getHighScore() != 100 || g.getLives() != 3 || g.getPlayer() != "Lisa-Dion"){
        std::cout << "Game Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    g.setHighScore(999);
    g.setLives(2);

    if(g.getHighScore() != 999 || g.getLives() != 2){
        std::cout << "HighScore Setter or Lives Setter Failed" << std::endl;
        passed = false;
    }

    g.setHighScore(-2);
    g.setLives(-2);

    if(g.getHighScore() != 0 || g.getLives() != 0){
        std::cout << "HighScore Setter or Lives Setter if-statement Failed" << std::endl;
        passed = false;
    }

    std::cout << g << std::endl; // should print the game board with the overloaded operator for a game object.

    std::cout << "^^^ Game Board should be printed above." << std::endl;

    Game ng("Liam", 8675309);

    if(ng.getHighScore() != 8675309 || ng.getLives() != 3 || ng.getPlayer() != "Liam"){
        std::cout << "Game Non-Default Constructor Test Failed" << std::endl;
        passed = false;
    }


    //Move Methods


    // ========== Gamepiece Class Testing===========

    GamePiece gp;

    if(gp.getXPos() != 0 || gp.getYPos() != 0){
        std::cout << "Gamepiece Deault Constructor Test Failed" << std::endl;
        passed = false;
    }

    gp.setXPos(20);
    gp.setYPos(20);
    gp.setType(pacMan);

    if(gp.getXPos() != 20 || gp.getYPos() != 20 || gp.getType() != pacMan){
        std::cout << "Gampiece setters Test Failed" << std::endl;
        passed = false;
    }

    // ========== Wall Class Testing ==========

    Wall w;

    if(w.getType() != wall){
        std::cout << "Wall Constructor Test Failed" << std::endl;
        passed = false;
    }

    w.setType(pellet);
    w.setXPos(20);
    w.setXPos(20);

    if(w.getType() != wall || w.getXPos() != 20 || w.getYPos() != 20){
        std::cout << "Wall setter Test Failed" << std::endl;
        passed = false;
    }

    // ========== Path Class Testing ==========

    Path p;

    if(p.getType() != pellet || p.getPelletStatus() == false){
        std::cout << "Path Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    p.setXPos(20);
    p.setYPos(20);
    p.setType(empty);
    p.setPelletStatus(true);

    if(p.getType() != empty || p.getPelletStatus() == true || p.getXPos() != 20 || p.getYPos() != 20){
        std::cout << "Path Setters Test Failed" << std::endl;
        passed = false;
    }

    // ========== Ghost Class Testing ==========

    Ghost gh;

    if(gh.getType() != ghost){
        std::cout << "Ghost Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    gh.setType(pellet);
    gh.setXPos(20);
    gh.setYPos(20);

    if(gh.getType() != ghost || gh.getXPos() != 20 || gh.getYPos() != 20){
        std::cout << "Ghost Setters Test Failed" << std::endl;
        passed = false;
    }

    Ghost ghn(20, 20);

    if(gh.getType() != ghost || gh.getStartXPos() != 20 || gh.getStartYPos() != 20){
        std::cout << "Ghost Non-Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    // ========== PacMan Class Testing ==========

    PacMan pm;

    if(pm.getType() != pacMan || pm.getStartXPos() != 14 || pm.getStartYPos() != 20){
        std::cout << "PacMan Default Constructor Test Failed" << std::endl;
        passed = false;
    }

    pm.setXPos(25);
    pm.setYPos(25);
    pm.setType(wall);

    if(pm.getType() != pacMan || pm.getXPos() != 25 || pm.getYPos() != 25){
        std::cout << "PacMan Setters Test Failed" << std::endl;
        passed = false;
    }

    pm.makeNoise();

    std::cout << "^^^ Should print BLOOP BLOOP BLOOP DEAD" << std::endl;

    std::cout << "Passed = " << std::boolalpha << passed << std::endl;
}
