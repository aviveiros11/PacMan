#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game a("Austin", 0);

    cout << a << endl;

    a.moveUp(a.gameBoard[18][20]);
    cout << a << endl;
    a.moveDown(a.getGameBoard()[18][19]);
    cout << a << endl;
    a.moveRight(a.getGameBoard()[18][20]);
    cout << a << endl;
    a.moveLeft(a.getGameBoard()[19][20]);
    cout << a << endl;


    cout << "Lives: " << a.getLives() << endl;






    return 0;
}