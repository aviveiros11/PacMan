//
// Created by Jean-Baptiste Bolh on 4/11/18.
//

using namespace std;

#include "Game.h"
#include "GamePiece.h"

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

ostream& operator <<(ostream& outs, const Game &g) {
    for (int x = 0; x < g.gameBoard.size(); x++) {
        for (int y = 0; y < g.gameBoard[x].size(); y++) {
            outs << g.gameBoard[x][y];
        }
        outs << endl;
    }
    return outs;
}