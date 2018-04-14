#include <iostream>
#include "Game.h"
#include "GamePiece.h"
#include <vector>
using namespace std;

int main() {

    GamePiece p;

    vector<vector<GamePiece>> vec1;
    vector<GamePiece> vec2;

    for (int i = 0; i < 5; i++) {
        GamePiece g1;
        vec2.push_back(g1);
    }
    vec1.push_back(vec2);

    Game g(vec1, 0);

    cout << g << endl;

    //cout << g.getLives() << endl;






    return 0;
}