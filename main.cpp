#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game a("Austin", 0);

    cout << a << endl;

    a.moveUp(a.gameBoard[18][20]);
    cout << a << endl;
    a.moveUp(a.getGameBoard()[18][19]);
    cout << a << endl;
    a.moveUp(a.getGameBoard()[18][18]);
    cout << a << endl;
    a.moveUp(a.getGameBoard()[18][17]);
    cout << a << endl;
    a.moveUp(a.getGameBoard()[18][16]);
    cout << a << endl;

    cout << "Lives: " << a.getLives() << endl;






    return 0;
}