//
// Created by Jean-Baptiste Bolh on 4/11/18.
//

//using namespace std;

#include "Game.h"
#include "GamePiece.h"

Game::Game(){
    highscore = 0;
    numLives = 3;

    vector<vector<GamePiece>> vec1;
    vector<GamePiece> vec2;

    for (int x = 0; x < 10; x++) {
        Path path;
        path.setType(wall);
        vec2.push_back(path);
    }
    for (int y = 0; y < 10; y++) {
        vec1.push_back(vec2);
    }

    gameBoard = vec1;
}

Game::Game(std::vector<std::vector<GamePiece>> &gBoard, double h) {
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
vector<vector<GamePiece>> Game::getGameBoard() const{
    return gameBoard;
}

void Game::setHighScore(double h){
        highscore = h;
}

void Game::setLives(int lives){
        numLives = lives;
}
void Game::setGameBoard(vector<vector<GamePiece>> &g){
    gameBoard = g;
}

ostream& operator <<(ostream& outs, const Game &g) {
    for (int y = 0; y < g.gameBoard.size(); y++) {
        for (int x = 0; x < g.gameBoard[y].size(); x++) {
            outs << '|' << g.gameBoard[x][y];
        }
        outs << '|' << endl;
    }
    return outs;
}
