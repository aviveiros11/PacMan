#include <iostream>
#include "Game.h"
#include "GamePiece.h"
#include "PacMan.h"
#include <vector>
using namespace std;

int main() {

    Game g;

    cout << g << endl;

    g.saveHighScore(g.getHighScore());

    return 0;
}