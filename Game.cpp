//
// Created by Jean-Baptiste Bolh on 4/11/18.
#include <fstream>
#include "Game.h"
#include "GamePiece.h"
#include "Ghost.h"
#include "PacMan.h"

using namespace std;

Game::Game(){
    highscore = 0;
    numLives = 3;

    //==================================================================================================================

    vector<GamePiece> rows;

    for (int x = 0; x < 28; x++) {
        Wall wall;
        rows.push_back(wall);
    }
    for (int y = 0; y < 28; y++) {
        gameBoard.push_back(rows);
    }

    //------------------------------------------------------------------------------------------------------------------
    ///Place pellet objects in "rows" of vector of vectors

    ///Row Index 1 Pellets
    for (int i = 1; i < 13; i++) {
        Path path;
        gameBoard[i][1] = path;
    }
    for (int i = 15; i < 27; i++) {
        Path path;
        gameBoard[i][1] = path;
    }
    ///Row Index 5 Pellets
    for (int i = 1; i < 27; i++) {
        Path path;
        gameBoard[i][5] = path;
    }
    ///Row Index 8 Pellets
    for (int i = 9; i < 13; i++) {
        Path path;
        gameBoard[i][8] = path;
    }
    for (int i = 15; i < 19; i++) {
        Path path;
        gameBoard[i][8] = path;
    }
    ///Row Index 11 Pellets
    for (int i = 1; i < 7; i++) {
        Path path;
        gameBoard[i][11] = path;
    }
    for (int i = 22; i < 27; i++) {
        Path path;
        gameBoard[i][11] = path;
    }
    ///Row Index 16 Pellets
    for (int i = 1; i < 7; i++) {
        Path path;
        gameBoard[i][16] = path;
    }
    for (int i = 22; i < 27; i++) {
        Path path;
        gameBoard[i][16] = path;
    }
    ///Row Index 20 Pellets
    for (int i = 1; i < 27; i++) {
        Path path;
        gameBoard[i][20] = path;
    }
    ///Row Index 23 Pellets
    for (int i = 1; i < 4; i++) {
        Path path;
        gameBoard[i][23] = path;
    }
    for (int i = 6; i < 22; i++) {
        Path path;
        gameBoard[i][23] = path;
    }
    for (int i = 24; i < 27; i++) {
        Path path;
        gameBoard[i][23] = path;
    }
    ///Row Index 26 Pellets
    for (int i = 1; i < 13; i++) {
        Path path;
        gameBoard[i][26] = path;
    }
    for (int i = 15; i < 27; i++) {
        Path path;
        gameBoard[i][26] = path;
    }

    //------------------------------------------------------------------------------------------------------------------
    ///Place pellet objects in "columns" of vector of vectors

    ///Column Index 1 Pellets
    for (int i = 1; i < 21; i++) {
        Path path;
        gameBoard[1][i] = path;
    }
    for (int i = 24; i < 26; i++) {
        Path path;
        gameBoard[1][i] = path;
    }
    ///Column Index 3 Pellets
    for (int i = 21; i < 24; i++) {
        Path path;
        gameBoard[3][i] = path;
    }
    ///Column Index 6 Pellets
    for (int i = 1; i < 26; i++) {
        Path path;
        gameBoard[6][i] = path;
    }
    ///Column Index 9 Pellets
    for (int i = 5; i < 8; i++) {
        Path path;
        gameBoard[9][i] = path;
    }
    for (int i = 17; i < 20; i++) {
        Path path;
        gameBoard[9][i] = path;
    }
    ///Column Index 12 Pellets
    for (int i = 1; i < 5; i++) {
        Path path;
        gameBoard[12][i] = path;
    }
    for (int i = 24; i < 26; i++) {
        Path path;
        gameBoard[12][i] = path;
    }
    ///Column Index 15 Pellets
    for (int i = 1; i < 5; i++) {
        Path path;
        gameBoard[15][i] = path;
    }
    for (int i = 24; i < 26; i++) {
        Path path;
        gameBoard[15][i] = path;
    }
    ///Column Index 18 Pellets
    for (int i = 5; i < 8; i++) {
        Path path;
        gameBoard[18][i] = path;
    }
    for (int i = 17; i < 20; i++) {
        Path path;
        gameBoard[18][i] = path;
    }
    ///Column Index 21 Pellets
    for (int i = 1; i < 26; i++) {
        Path path;
        gameBoard[21][i] = path;
    }
    ///Column Index 24 Pellets
    for (int i = 21; i < 24; i++) {
        Path path;
        gameBoard[24][i] = path;
    }
    ///Column Index 26 Pellets
    for (int i = 1; i < 21; i++) {
        Path path;
        gameBoard[26][i] = path;
    }
    for (int i = 24; i < 26; i++) {
        Path path;
        gameBoard[26][i] = path;
    }

    //------------------------------------------------------------------------------------------------------------------
    ///Place empty Path objects around center of board (Rows)

    for (int i = 7; i < 21; i++) {
        Path path(empty, false);
        gameBoard[i][11] = path;
    }
    for (int i = 13; i < 15; i++) {
        Path path(empty, false);
        gameBoard[i][12] = path;
    }
    for (int i = 11; i < 17; i++) {
        Path path(empty, false);
        gameBoard[i][13] = path;
    }
    for (int i = 11; i < 17; i++) {
        Path path(empty, false);
        gameBoard[i][14] = path;
    }
    for (int i = 7; i < 21; i++) {
        Path path(empty, false);
        gameBoard[i][16] = path;
    }

    //------------------------------------------------------------------------------------------------------------------
    ///Place empty Path objects around center of board (Columns)

    for (int i = 11; i < 17; i++) {
        Path path(empty, false);
        gameBoard[9][i] = path;
    }
    for (int i = 9; i < 11; i++) {
        Path path(empty, false);
        gameBoard[12][i] = path;
    }
    for (int i = 17; i < 20; i++) {
        Path path(empty, false);
        gameBoard[12][i] = path;
    }
    for (int i = 9; i < 11; i++) {
        Path path(empty, false);
        gameBoard[15][i] = path;
    }
    for (int i = 17; i < 20; i++) {
        Path path(empty, false);
        gameBoard[15][i] = path;
    }
    for (int i = 11; i < 17; i++) {
        Path path(empty, false);
        gameBoard[18][i] = path;
    }

    //------------------------------------------------------------------------------------------------------------------
    ///Individually place ghosts and pacMan piece

    Ghost ghost1;
    Ghost ghost2;
    Ghost ghost3;
    Ghost ghost4;
    gameBoard[12][14] = ghost1;
    gameBoard[15][14] = ghost2;
    gameBoard[11][11] = ghost3;
    gameBoard[16][11] = ghost4;
    PacMan pacMan;
    gameBoard[14][20] = pacMan;

    //==================================================================================================================

    highscore = 100;
    gameBoard = gameBoard;
    numLives = 3;
    player = "Lisa-Dion";
}

Game::Game(std::string p, double h) {
    Game tempGame;
    gameBoard = tempGame.getGameBoard();
    highscore = h;
    numLives = 3;
    player = p;

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

string Game::getPlayer() const{
    return player;
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

void Game::saveHighScore(int highScore, string player) {
    ofstream highScores("HighScores.txt", ios::app);
    if(highScores){
        highScores << player << endl;
        highScores << highScore << endl;
    }
    highScores.close();
}

void Game::displayHighScore() {
    ifstream highScores("HighScores.txt");
    int score;
    string player;
    while (highScores >> player >> score) {
        cout << player << " - " << score << endl;
    }
    highScores.close();
}


ostream& operator <<(ostream& outs, const Game &g) {
    for (int y = 0; y < g.gameBoard.size(); y++) {
        for (int x = 0; x < g.gameBoard[y].size(); x++) {
            outs << g.gameBoard[x][y];
        }
        outs << endl;
    }
    return outs;
}
