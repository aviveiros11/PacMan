#include <iostream>
#include "Game.h"

using namespace std;

int main() {

    Game a("Austin", 0);

    cout << a << endl;

    cout << a.getPlayer() << endl;

    cout << a.getLives() << endl;

    a.saveHighScore(a.getHighScore(), a.getPlayer());

    a.displayHighScore();

    return 0;
}