//
// Created by Jean-Baptiste Bolh on 4/11/18.
//

#include <fstream>
#include "Game.h"
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

    Ghost ghost1(12, 14);
    Ghost ghost2(15, 14);
    Ghost ghost3(11, 11);
    Ghost ghost4(16, 11);
    gameBoard[ghost1.getStartXPos()][ghost1.getStartYPos()] = ghost1;
    gameBoard[ghost2.getStartXPos()][ghost2.getStartYPos()] = ghost2;
    gameBoard[ghost3.getStartXPos()][ghost3.getStartYPos()] = ghost3;
    gameBoard[ghost4.getStartXPos()][ghost4.getStartYPos()] = ghost4;
    PacMan pacMan;
    gameBoard[pacMan.getStartXPos()][pacMan.getStartYPos()] = pacMan;

    //TODO DELETE THIS IN FUTURE 123ertghjlkhgfdreszdxfcvbnjiuytredsxdgfhbnjkmiuy6t5r4edcv bnjkiouy7t6r5dcvbhuytrdcfgnvk
    Path path1;
    gameBoard[14][19] = path1;
    Ghost ghost5(18, 20);
    gameBoard[18][20] = ghost5;
    Ghost ghost6(10, 20);
    gameBoard[10][20] = ghost5;
    Ghost ghost7(14, 18);
    gameBoard[14][18] = ghost5;
    Ghost ghost8(14, 22);
    gameBoard[14][22] = ghost8;
    Path path2;
    gameBoard[14][21] = path2;

    for(int y = 0; y < gameBoard.size(); y++){
        for (int x = 0; x < gameBoard[0].size(); x++){
            gameBoard[x][y].setXPos(x);
            gameBoard[x][y].setYPos(y);
        }
    }

    //==================================================================================================================

    highscore = 100;
    gameBoard = gameBoard;
    numLives = 3;
    player = "Lisa-Dion";
}

Game::Game(std::string p, int h) {
    Game tempGame;
    gameBoard = tempGame.getGameBoard();
    highscore = h;
    numLives = 3;
    player = p;

}

int Game::getHighScore() const{
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

void Game::setHighScore(int h){
    highscore = h;
}

void Game::setLives(int lives){
    numLives = lives;
}
void Game::setGameBoard(vector<vector<GamePiece>> &g){
    gameBoard = g;
}

void Game::resetGameBoard() {
    for(int y = 0; y < gameBoard.size(); y++){
        for (int x = 0; x < gameBoard[0].size(); x++){
            if (gameBoard[x][y].getType() == pacMan) {
                GamePiece pCopy;
                pCopy = gameBoard[x][y];
                Path rep(empty, false);
                gameBoard[x][y] = rep;
                //delete the object being stored there, set the type to empty and store that as a temp object.
                //g.gameBoard[xPos][(yPos + 1)]= nullptr;
                gameBoard[pCopy.getStartXPos()][pCopy.getStartYPos()] = pCopy;
            } else if (gameBoard[x][y].getType() == ghost) {
                GamePiece gCopy;
                gCopy = gameBoard[x][y];
                Path rep;
                if (gCopy.currentStatus == noPellet) {
                    rep.setType(empty);
                    rep.setPelletStatus(false);
                }
                gameBoard[x][y] = rep;
                //delete the object being stored there, set the type to empty and store that as a temp object.
                //g.gameBoard[xPos][(yPos + 1)]= nullptr;
                gameBoard[gCopy.getStartXPos()][gCopy.getStartYPos()] = gCopy;
            }
        }
    }
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

void Game::moveUp(GamePiece &g) {
    if (g.getType() == ghost && numLives >= 1) {
        if (gameBoard[g.getXPos()][(g.getYPos() - 1)].getType() != wall) {
            //Create copy of piece being moved
            if (gameBoard[g.getXPos()][(g.getYPos() - 1)].getType() == pacMan) {
                //send pacman back to his starting position
                --numLives;
                resetGameBoard();
            } else {
                if (gameBoard[g.getXPos()][(g.getYPos() - 1)].getType() == pellet) {
                    g.currentStatus = yesPellet;
                } else {
                    g.currentStatus = noPellet;
                }
                Path rep;
                if (g.currentStatus == noPellet) {
                    rep.setType(empty);
                    rep.setPelletStatus(false);
                }
                GamePiece gCopy = gameBoard[g.getXPos()][g.getYPos()];
                gameBoard[g.getXPos()][(g.getYPos() - 1)] = gCopy;
                //gCopy.setYPos(g.getYPos() - 1);
                gameBoard[g.getXPos()][g.getYPos()] = rep;
                //starting state must be empty, so save in temp and then add when leave.

            }
        }
    }
    if (g.getType() == pacMan && numLives >= 1) {
        if (gameBoard[g.getXPos()][(g.getYPos() - 1)].getType() != wall) {
            //Create copy of piece being moved
            GamePiece pCopy = gameBoard[g.getXPos()][g.getYPos()];
            if (gameBoard[g.getXPos()][(g.getYPos() - 1)].getType() == ghost) {
                //Need to decrease lives somehow
                --numLives;
                //send pacman back to his starting position
                resetGameBoard();
            } else {
                if (gameBoard[g.getXPos()][(g.getYPos() - 1)].getType() == pellet) {
                    highscore += 10;
                    Path rep(empty, false);
                    //increase high score
                    //delete the object being stored there, set the type to empty and store that as a temp object.
                    //g.gameBoard[xPos][(yPos + 1)]= nullptr;
                    gameBoard[g.getXPos()][(g.getYPos() - 1)] = pCopy;
                    pCopy.setYPos(g.getYPos() - 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;

                } else {
                    Path rep(empty, false);
                    gameBoard[g.getXPos()][(g.getYPos() - 1)] = pCopy;
                    pCopy.setYPos(g.getYPos() - 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;
                    //starting state must be empty, so save in temp and then add when leave.
                }

            }

        }
    }
    for (int y = 0; y < gameBoard.size(); y++) {
        for (int x = 0; x < gameBoard[0].size(); x++) {
            gameBoard[x][y].setXPos(x);
            gameBoard[x][y].setYPos(y);
        }
    }
}

void Game::moveLeft(GamePiece &g) {
    if (g.getType() == ghost && numLives >= 1) {
        if (gameBoard[(g.getXPos() - 1)][g.getYPos()].getType() != wall) { //If piece to the left is not wall
            //Create copy of piece being moved
            if (gameBoard[g.getXPos() - 1][g.getYPos()].getType() == pacMan) {
                //send pacman back to his starting position
                --numLives;
                resetGameBoard();
            } else {
                if (gameBoard[(g.getXPos() - 1)][g.getYPos()].getType() == pellet) {
                    g.currentStatus = yesPellet;
                } else {
                    g.currentStatus = noPellet;
                }
                Path rep;
                if (g.currentStatus == noPellet) {
                    rep.setType(empty);
                    rep.setPelletStatus(false);
                }
                GamePiece gCopy = gameBoard[g.getXPos()][g.getYPos()];
                gameBoard[g.getXPos() - 1][(g.getYPos())] = gCopy;
                //gCopy.setYPos(g.getYPos() - 1);
                gameBoard[g.getXPos()][g.getYPos()] = rep;
                //starting state must be empty, so save in temp and then add when leave.

            }
        }
    }
    if(g.getType() == pacMan && numLives >= 1) {
        if (gameBoard[g.getXPos() - 1][g.getYPos()].getType() != wall) {
            //Create copy of piece being moved
            GamePiece pCopy = gameBoard[g.getXPos()][g.getYPos()];
            if (gameBoard[g.getXPos() - 1][(g.getYPos())].getType() == ghost) {
                //Need to decrease lives somehow
                --numLives;
                //send pacman back to his starting position
                resetGameBoard();
            } else {
                if (gameBoard[(g.getXPos() - 1)][g.getYPos()].getType() == pellet) {
                    highscore += 10;
                    Path rep(empty, false);
                    //increase high score
                    //delete the object being stored there, set the type to empty and store that as a temp object.
                    //g.gameBoard[xPos][(yPos + 1)]= nullptr;
                    gameBoard[(g.getXPos() - 1)][g.getYPos()] = pCopy;
                    pCopy.setXPos(g.getXPos() - 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;

                } else {
                    Path rep(empty, false);
                    gameBoard[(g.getXPos() - 1)][g.getYPos()] = pCopy;
                    pCopy.setXPos(g.getXPos() - 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;
                    //starting state must be empty, so save in temp and then add when leave.
                }
            }

        }
    }
    for (int y = 0; y < gameBoard.size(); y++) {
        for (int x = 0; x < gameBoard[0].size(); x++) {
            gameBoard[x][y].setXPos(x);
            gameBoard[x][y].setYPos(y);
        }
    }
}

void Game::moveDown(GamePiece &g) {
    if (g.getType() == ghost && numLives >= 1) {
        if (gameBoard[(g.getXPos())][g.getYPos() + 1].getType() != wall) { //If piece to the left is not wall
            //Create copy of piece being moved
            if (gameBoard[g.getXPos()][g.getYPos() + 1].getType() == pacMan) {
                //send pacman back to his starting position
                --numLives;
                resetGameBoard();
            } else {
                if (gameBoard[(g.getXPos())][g.getYPos() + 1].getType() == pellet) {
                    g.currentStatus = yesPellet;
                } else {
                    g.currentStatus = noPellet;
                }
                Path rep;
                if (g.currentStatus == noPellet) {
                    rep.setType(empty);
                    rep.setPelletStatus(false);
                }
                GamePiece gCopy = gameBoard[g.getXPos()][g.getYPos()];
                gameBoard[g.getXPos()][(g.getYPos() + 1)] = gCopy;
                //gCopy.setYPos(g.getYPos() - 1);
                gameBoard[g.getXPos()][g.getYPos()] = rep;
                //starting state must be empty, so save in temp and then add when leave.

            }
        }
    }
    if (g.getType() == pacMan && numLives >= 1) {
        if (gameBoard[g.getXPos()][(g.getYPos() + 1)].getType() != wall) {
            //Create copy of piece being moved
            GamePiece pCopy = gameBoard[g.getXPos()][g.getYPos()];
            if (gameBoard[g.getXPos()][(g.getYPos() + 1)].getType() == ghost) {
                //Need to decrease lives somehow
                --numLives;
                //send pacman back to his starting position
                resetGameBoard();
            } else {
                if (gameBoard[g.getXPos()][(g.getYPos() + 1)].getType() == pellet) {
                    highscore += 10;
                    Path rep(empty, false);
                    //increase high score
                    //delete the object being stored there, set the type to empty and store that as a temp object.
                    //g.gameBoard[xPos][(yPos + 1)]= nullptr;
                    gameBoard[g.getXPos()][(g.getYPos() + 1)] = pCopy;
                    pCopy.setYPos(g.getYPos() + 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;

                } else {
                    Path rep(empty, false);
                    gameBoard[g.getXPos()][(g.getYPos() + 1)] = pCopy;
                    pCopy.setYPos(g.getYPos() + 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;
                    //starting state must be empty, so save in temp and then add when leave.
                }

            }

        }
    }
    for (int y = 0; y < gameBoard.size(); y++) {
        for (int x = 0; x < gameBoard[0].size(); x++) {
            gameBoard[x][y].setXPos(x);
            gameBoard[x][y].setYPos(y);
        }
    }
}

void Game::moveRight(GamePiece &g) {
    if (g.getType() == ghost && numLives >= 1) {
        if (gameBoard[(g.getXPos() + 1)][g.getYPos()].getType() != wall) { //If piece to the left is not wall
            //Create copy of piece being moved
            if (gameBoard[g.getXPos() + 1][g.getYPos()].getType() == pacMan) {
                //send pacman back to his starting position
                --numLives;
                resetGameBoard();
            } else {
                if (gameBoard[(g.getXPos() + 1)][g.getYPos()].getType() == pellet) {
                    g.currentStatus = yesPellet;
                } else {
                    g.currentStatus = noPellet;
                }
                Path rep;
                if (g.currentStatus == noPellet) {
                    rep.setType(empty);
                    rep.setPelletStatus(false);
                }
                GamePiece gCopy = gameBoard[g.getXPos()][g.getYPos()];
                gameBoard[g.getXPos() + 1][(g.getYPos())] = gCopy;
                //gCopy.setYPos(g.getYPos() - 1);
                gameBoard[g.getXPos()][g.getYPos()] = rep;
                //starting state must be empty, so save in temp and then add when leave.

            }
        }
    }
    if(g.getType() == pacMan && numLives >= 1) {
        if (gameBoard[g.getXPos() + 1][g.getYPos()].getType() != wall) {
            //Create copy of piece being moved
            GamePiece pCopy = gameBoard[g.getXPos()][g.getYPos()];
            if (gameBoard[g.getXPos() + 1][(g.getYPos())].getType() == ghost) {
                //Need to decrease lives somehow
                --numLives;
                //send pacman back to his starting position
                resetGameBoard();
            } else {
                if (gameBoard[(g.getXPos() + 1)][g.getYPos()].getType() == pellet) {
                    highscore += 10;
                    Path rep(empty, false);
                    //increase high score
                    //delete the object being stored there, set the type to empty and store that as a temp object.
                    //g.gameBoard[xPos][(yPos + 1)]= nullptr;
                    gameBoard[(g.getXPos() + 1)][g.getYPos()] = pCopy;
                    pCopy.setXPos(g.getXPos() + 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;

                } else {
                    Path rep(empty, false);
                    gameBoard[(g.getXPos() + 1)][g.getYPos()] = pCopy;
                    pCopy.setXPos(g.getXPos() + 1);
                    gameBoard[g.getXPos()][g.getYPos()] = rep;
                    //starting state must be empty, so save in temp and then add when leave.
                }
            }

        }
    }
    for (int y = 0; y < gameBoard.size(); y++) {
        for (int x = 0; x < gameBoard[0].size(); x++) {
            gameBoard[x][y].setXPos(x);
            gameBoard[x][y].setYPos(y);
        }
    }
}