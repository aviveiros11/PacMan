#include <iostream>
#include "Game.h"
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
    for (int x = 0; x < 5; x++) {
        vec1.push_back(vec2);
    }

    Game g(vec1, 0);

    cout << g << endl;

    //cout << g.getLives() << endl;
    cout << "Test" << endl;


    return 0;
}