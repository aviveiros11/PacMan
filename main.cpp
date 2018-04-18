#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game a("Austin", 0);

    cout << a << endl;

    a.moveUp(a.gameBoard[14][22]);
    cout << a << endl;
    a.moveUp(a.gameBoard[14][21]);
    cout << a << endl;


    cout << "Lives: " << a.getLives() << endl;






    return 0;
}