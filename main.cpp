#include <iostream>
#include "Game.h"
#include "GamePiece.h"
#include <vector>
using namespace std;

int main() {

    GamePiece p;

    vector<vector<GamePiece>> vec;

    for (int i = 0; i < 5; i++) {
        vec[i].push_back(p);
        vec[i].push_back(p);
        vec[i].push_back(p);
        vec[i].push_back(p);
        vec[i].push_back(p);
    }

    Game g(vec, 0);

    cout << g;

    //cout << g.getLives() << endl;






    return 0;
}