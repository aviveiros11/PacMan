#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game a("Austin", 0);

    cout << a << endl;

    a.moveUp(a.gameBoard[14][20]);
    cout << a << endl;
    a.moveDown(a.getGameBoard()[14][19]);
    cout << a << endl;
    a.moveRight(a.getGameBoard()[14][20]);
    cout << a << endl;
    a.moveLeft(a.getGameBoard()[15][20]);
    cout << a << endl;

    a.setHighScore(30);
    a.saveHighScore(a.getHighScore(), a.getPlayer());
    a.displayHighScore();

    cout << "Lives: " << a.getLives() << endl;

    return 0;
}