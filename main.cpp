#include <iostream>
#include "Game.h"
#include "GamePiece.h"
#include "PacMan.h"
#include <vector>
using namespace std;

int main() {


    vector<vector<GamePiece>> vec1;
    vector<GamePiece> vec2;



    for (int x = 0; x < 5; x++) {
        Path path;
        path.setType(pellet);
        vec2.push_back(path);
    }

    for (int y = 0; y < 5; y++) {
        vec1.push_back(vec2);
    }

    Game g(vec1, 0);

    cout << g << endl;

    cout << "Test" << endl;
    cout << "Test Again" << endl;


    return 0;
}