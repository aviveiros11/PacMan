//
// Created by Jean-Baptiste Bolh on 4/11/18.
//

#include "Game.h"

Game::Game(){
    highscore = 0;
    numLives = 3;
}

Game::Game(std::vector<std::vector<GamePiece>> gBoard, double h) {
    highscore = h;
    gameBoard = gBoard;
    numLives = 3;
}

double Game::getHighScore() const{
    return highscore;
}

int Game::getLives() const{
    return numLives;
}

void Game::setHighScore(double h){
        highscore = h;
}

void Game::setLives(int lives){
        numLives = lives;
}
