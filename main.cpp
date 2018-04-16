#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game a("Austin", 0);

    cout << a << endl;

//    a.moveLeft(a.getGameBoard()[14][20]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[13][20]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[12][20]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[11][20]);
//    cout << a << endl;

    a.moveRight(a.getGameBoard()[14][20]);
    cout << a << endl;
    a.moveUp(a.getGameBoard()[15][20]);
    cout << a << endl;
    a.moveDown(a.getGameBoard()[15][19]);
    cout << a << endl;


//    a.moveLeft(a.getGameBoard()[14][20]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[13][20]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[12][20]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[11][20]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[10][20]);
//    cout << a << endl;
//
//    a.moveUp(a.getGameBoard()[9][20]);
//    cout << a << endl;
//    a.moveUp(a.getGameBoard()[9][19]);
//    cout << a << endl;
//    a.moveUp(a.getGameBoard()[9][18]);
//    cout << a << endl;
//    a.moveUp(a.getGameBoard()[9][17]);
//    cout << a << endl;
//
//    a.moveRight(a.getGameBoard()[9][16]);
//    cout << a << endl;
//    a.moveLeft(a.getGameBoard()[10][16]);
//    cout << a << endl;


    //cout << a.getPlayer() << endl;
    //cout << a.getLives() << endl;

    //a.saveHighScore(a.getHighScore(), a.getPlayer());

    //a.displayHighScore();






    return 0;
}