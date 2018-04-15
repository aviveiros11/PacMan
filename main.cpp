#include <iostream>
#include "Game.h"
#include "GamePiece.h"
#include <vector>
using namespace std;

int main() {

    Wall p;
    Path path;

    vector<vector<GamePiece>> vec1;
    vector<GamePiece> vec2;

    for (int i = 0; i < 5; i++) {
        Path p;
        vec2.push_back(p);
    }
    for (int x = 0; x < 5; x++) {
        vec1.push_back(vec2);
    }

    Game g(vec1, 0);

    cout << g << endl;

    return 0;
}