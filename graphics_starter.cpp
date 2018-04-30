#include "graphics.h"
#include "shapes.h"
#include <string>
#include <random>
#include "Game.h"
#include <unistd.h>
#include <chrono>
#include <ctime>
using namespace std;

enum mode {start, game, gameOver, highScore, instructions};

int pDir = 0;
int nextPDir = 0;

int inkyDir = 0;
int clydeDir = 1;
int pinkyDir = 1;
int blinkyDir = 0;

auto startTimer = std::chrono::high_resolution_clock::now();
auto finishTimer = std::chrono::high_resolution_clock::now();

int currentGame = -1;
Game g;
vector<Game> games;

mode screen;
GLdouble width, height;
int wd;
Circle pacman(8);
Circle blinky(8);
Circle pinky(8);
Circle inky(8);
Circle clyde(8);

Tangle startBtn;
Tangle highScoBtn;
Tangle mainMenuBtn;
Tangle instructionsBtn;
Tangle exitBtn;

Tangle victoryBackground;

//Side Walls
Tangle topWall;
Tangle leftWall;
Tangle rightWall;
Tangle bottomWall;

//First Group of Rectangles Across
Tangle firstQuadRec1;
Tangle firstQuadRec2;
Tangle firstQuadRec3;
Tangle firstQuadRec4;
Tangle firstQuadRec5;

//Second Group of Rectangles Across
Tangle secondQuadRec1;
Tangle secondQuadRec2;
Tangle secondQuadRec3;
Tangle secondQuadRec4;
Tangle secondQuadRec5;
Tangle secondQuadRec6;
Tangle secondQuadRec7;
Tangle secondQuadRec8;

//Third Group of Rectangles
Tangle thirdQuadRec1;
Tangle thirdQuadRec2;
Tangle thirdQuadRec3;
Tangle thirdQuadRec4;
Tangle thirdQuadRec5;
Tangle thirdQuadRec6;
Tangle thirdQuadRec7;
Tangle thirdQuadRec8;
Tangle thirdQuadRec9;

//Fourth Group
Tangle fourthQuadRec1;
Tangle fourthQuadRec2;
Tangle fourthQuadRec3;
Tangle fourthQuadRec4;
Tangle fourthQuadRec5;
Tangle fourthQuadRec6;
Tangle fourthQuadRec7;

//Fifth Quad
Tangle fifthQuadRec1;
Tangle fifthQuadRec2;
Tangle fifthQuadRec3;
Tangle fifthQuadRec4;
Tangle fifthQuadRec5;
Tangle fifthQuadRec6;
Tangle fifthQuadRec7;
Tangle fifthQuadRec8;
Tangle fifthQuadRec9;
Tangle fifthQuadRec10;

void init() {
    width = 540;
    height = 560;

    screen = start;

    startBtn.setDimensions(30, 150);
    startBtn.setFillColor(255,238,0);
    startBtn.setCenter(280, 280);

    highScoBtn.setDimensions(30, 150);
    highScoBtn.setFillColor(250/255.0,192/255.0,203/255.0);
    highScoBtn.setCenter(280, 330);

    mainMenuBtn.setDimensions(30, 150);
    mainMenuBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    mainMenuBtn.setCenter(280, 60);

    instructionsBtn.setDimensions(30, 150);
    instructionsBtn.setFillColor(0.5,1,1);
    instructionsBtn.setCenter(280, 380);

    exitBtn.setDimensions(30, 150);
    exitBtn.setFillColor(1,0.5,0);
    exitBtn.setCenter(280, 430);

    victoryBackground.setDimensions(20, 160);
    victoryBackground.setFillColor(0, 0, 0);
    victoryBackground.setCenter(270, 320 + 10);

    //==============================================================================================================

    topWall.setDimensions(20, 560);
    topWall.setFillColor(0, 0, 1.0);
    topWall.setCenter(270, 10);

    //==================================================================================================================

    leftWall.setDimensions(560, 20);
    leftWall.setFillColor(0, 0, 1.0);
    leftWall.setCenter(0, 280);

    //==================================================================================================================

    rightWall.setDimensions(560, 20);
    rightWall.setFillColor(0, 0, 1.0);
    rightWall.setCenter(540, 280);

    //==================================================================================================================

    bottomWall.setDimensions(20, 560);
    bottomWall.setFillColor(0, 0, 1.0);
    bottomWall.setCenter(270, 550);

    //===START Q1===========================================================================================================

    firstQuadRec1.setDimensions(60, 80);
    firstQuadRec1.setFillColor(0, 0, 1.0);
    firstQuadRec1.setCenter(70, 70);

    //==============================================================================================================

    firstQuadRec2.setDimensions(60, 100);
    firstQuadRec2.setFillColor(0, 0, 1.0);
    firstQuadRec2.setCenter(180, 70);

    //==============================================================================================================

    firstQuadRec3.setDimensions(100, 40);
    firstQuadRec3.setFillColor(0, 0, 1.0);
    firstQuadRec3.setCenter(270, 50);

    //=============================================================================================================

    firstQuadRec4.setDimensions(60, 100);
    firstQuadRec4.setFillColor(0, 0, 1.0);
    firstQuadRec4.setCenter(360, 70);

    //==============================================================================================================

    firstQuadRec5.setDimensions(60, 80);
    firstQuadRec5.setFillColor(0, 0, 1.0);
    firstQuadRec5.setCenter(470, 70);

    //=====START Q2==========================================================================================================

    secondQuadRec1.setDimensions(100, 80);
    secondQuadRec1.setFillColor(0, 0, 1.0);
    secondQuadRec1.setCenter(70, 170);

    //================================================================================================================

    secondQuadRec2.setDimensions(100, 40);
    secondQuadRec2.setFillColor(0, 0, 1.0);
    secondQuadRec2.setCenter(150, 170);

    //================================================================================================================

    secondQuadRec3.setDimensions(40, 100);
    secondQuadRec3.setFillColor(0, 0, 1.0);
    secondQuadRec3.setCenter(180, 200);

    //================================================================================================================

    secondQuadRec4.setDimensions(40, 160);
    secondQuadRec4.setFillColor(0, 0, 1.0);
    secondQuadRec4.setCenter(270, 140);

    //================================================================================================================

    secondQuadRec5.setDimensions(100, 40);
    secondQuadRec5.setFillColor(0, 0, 1.0);
    secondQuadRec5.setCenter(270, 170);

    //================================================================================================================

    secondQuadRec6.setDimensions(100, 40);
    secondQuadRec6.setFillColor(0, 0, 1.0);
    secondQuadRec6.setCenter(390, 170);

    //================================================================================================================

    secondQuadRec7.setDimensions(40, 100);
    secondQuadRec7.setFillColor(0, 0, 1.0);
    secondQuadRec7.setCenter(360, 200);

    //================================================================================================================

    secondQuadRec8.setDimensions(100, 80);
    secondQuadRec8.setFillColor(0, 0, 1.0);
    secondQuadRec8.setCenter(470, 170);

    //========START Q3========================================================================================================

    thirdQuadRec1.setDimensions(80, 80);
    thirdQuadRec1.setFillColor(0, 0, 1.0);
    thirdQuadRec1.setCenter(70, 280);

    //================================================================================================================

    thirdQuadRec2.setDimensions(80, 40);
    thirdQuadRec2.setFillColor(0, 0, 1.0);
    thirdQuadRec2.setCenter(150, 280);

    //================================================================================================================

    thirdQuadRec3.setDimensions(80, 20);
    thirdQuadRec3.setFillColor(0, 0, 1.0);
    thirdQuadRec3.setCenter(200, 280);

    //================================================================================================================

    thirdQuadRec4.setDimensions(20, 160);
    thirdQuadRec4.setFillColor(0, 0, 1.0);
    thirdQuadRec4.setCenter(270, 310);

    //================================================================================================================

    thirdQuadRec5.setDimensions(20, 60);
    thirdQuadRec5.setFillColor(0, 0, 1.0);
    thirdQuadRec5.setCenter(220, 250);

    //================================================================================================================

    thirdQuadRec6.setDimensions(80, 20);
    thirdQuadRec6.setFillColor(0, 0, 1.0);
    thirdQuadRec6.setCenter(340, 280);

    //================================================================================================================

    thirdQuadRec7.setDimensions(20, 60);
    thirdQuadRec7.setFillColor(0, 0, 1.0);
    thirdQuadRec7.setCenter(320, 250);

    //================================================================================================================

    thirdQuadRec8.setDimensions(80, 40);
    thirdQuadRec8.setFillColor(0, 0, 1.0);
    thirdQuadRec8.setCenter(390, 280);

    //================================================================================================================

    thirdQuadRec9.setDimensions(80, 80);
    thirdQuadRec9.setFillColor(0, 0, 1.0);
    thirdQuadRec9.setCenter(470, 280);

    //========START Q4========================================================================================================

    fourthQuadRec1.setDimensions(60, 80);
    fourthQuadRec1.setFillColor(0, 0, 1.0);
    fourthQuadRec1.setCenter(70, 370);

    //================================================================================================================

    fourthQuadRec2.setDimensions(60, 40);
    fourthQuadRec2.setFillColor(0, 0, 1.0);
    fourthQuadRec2.setCenter(150, 370);

    //================================================================================================================

    fourthQuadRec3.setDimensions(60, 40);
    fourthQuadRec3.setFillColor(0, 0, 1.0);
    fourthQuadRec3.setCenter(210, 370);

    //================================================================================================================

    fourthQuadRec4.setDimensions(60, 40);
    fourthQuadRec4.setFillColor(0, 0, 1.0);
    fourthQuadRec4.setCenter(270, 370);

    //================================================================================================================

    fourthQuadRec5.setDimensions(60, 40);
    fourthQuadRec5.setFillColor(0, 0, 1.0);
    fourthQuadRec5.setCenter(330, 370);

    //================================================================================================================

    fourthQuadRec6.setDimensions(60, 40);
    fourthQuadRec6.setFillColor(0, 0, 1.0);
    fourthQuadRec6.setCenter(390, 370);

    //================================================================================================================

    fourthQuadRec7.setDimensions(60, 80);
    fourthQuadRec7.setFillColor(0, 0, 1.0);
    fourthQuadRec7.setCenter(470, 370);

    //======START Q5==========================================================================================================

    fifthQuadRec1.setDimensions(40, 40);
    fifthQuadRec1.setFillColor(0, 0, 1.0);
    fifthQuadRec1.setCenter(30, 440);

    //================================================================================================================

    fifthQuadRec2.setDimensions(40, 80);
    fifthQuadRec2.setFillColor(0, 0, 1.0);
    fifthQuadRec2.setCenter(70, 500);

    //================================================================================================================

    fifthQuadRec3.setDimensions(80, 40);
    fifthQuadRec3.setFillColor(0, 0, 1.0);
    fifthQuadRec3.setCenter(90, 460);

    //================================================================================================================

    fifthQuadRec4.setDimensions(40, 280);
    fifthQuadRec4.setFillColor(0, 0, 1.0);
    fifthQuadRec4.setCenter(270, 440);

    //================================================================================================================

    fifthQuadRec5.setDimensions(40, 100);
    fifthQuadRec5.setFillColor(0, 0, 1.0);
    fifthQuadRec5.setCenter(180, 500);

    //================================================================================================================

    fifthQuadRec6.setDimensions(80, 40);
    fifthQuadRec6.setFillColor(0, 0, 1.0);
    fifthQuadRec6.setCenter(270, 520);

    //================================================================================================================

    fifthQuadRec7.setDimensions(40, 100);
    fifthQuadRec7.setFillColor(0, 0, 1.0);
    fifthQuadRec7.setCenter(360, 500);

    //================================================================================================================

    fifthQuadRec8.setDimensions(40, 80);
    fifthQuadRec8.setFillColor(0, 0, 1.0);
    fifthQuadRec8.setCenter(470, 500);

    //================================================================================================================

    fifthQuadRec9.setDimensions(80, 40);
    fifthQuadRec9.setFillColor(0, 0, 1.0);
    fifthQuadRec9.setCenter(450, 460);

    //================================================================================================================

    fifthQuadRec10.setDimensions(40, 40);
    fifthQuadRec10.setFillColor(0, 0, 1.0);
    fifthQuadRec10.setCenter(510, 440);

    //================================================================================================================

    pacman.setCenter(280, 410);
    pacman.setFillColor(255,238,0);

    blinky.setCenter(240,290);
    blinky.setFillColor(1,0,0);

    pinky.setCenter(300,290);
    pinky.setFillColor(250/255.0,192/255.0,203/255.0);

    inky.setCenter(220,230);
    inky.setFillColor(0.5,1,1);

    clyde.setCenter(320,230);
    clyde.setFillColor(1,0.5,0);

}
/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

//======================================================================================================================

void displayStart() {

    string message = "Welcome to paC++!";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(200, 200);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    startBtn.draw();
    string startMsg = "Start";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(260, 285);
    for (char c : startMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    highScoBtn.draw();
    string highScoMsg = "Scores";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(253, 335);
    for (char c : highScoMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    instructionsBtn.draw();
    string instructionsMsg = "Instructions";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(233, 385);
    for (char c : instructionsMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    exitBtn.draw();
    string exitMsg = "Exit";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(263, 435);
    for (char c : exitMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

//======================================================================================================================

void displayGame() {

    for(int y = 0; y < games[currentGame].gameBoard.size(); y++){
        for (int x = 0; x < games[currentGame].gameBoard[0].size(); x++){
            if (games[currentGame].gameBoard[x][y].getType() == pellet) {
                games[currentGame].gameBoard[x][y].drawPellet((20 * x), 10 + (20 * y), 3);
            }
        }
    }

    //Draw Sides
    topWall.draw();
    leftWall.draw();
    rightWall.draw();
    bottomWall.draw();

    //Draw 1st Quad
    firstQuadRec1.draw();
    firstQuadRec2.draw();
    firstQuadRec3.draw();
    firstQuadRec4.draw();
    firstQuadRec5.draw();

    //Second Quad
    secondQuadRec1.draw();
    secondQuadRec2.draw();
    secondQuadRec3.draw();
    secondQuadRec4.draw();
    secondQuadRec5.draw();
    secondQuadRec6.draw();
    secondQuadRec7.draw();
    secondQuadRec8.draw();

    //Third Quad
    thirdQuadRec1.draw();
    thirdQuadRec2.draw();
    //thirdQuadRec3.draw();
    thirdQuadRec4.draw();
    thirdQuadRec5.draw();
    //thirdQuadRec6.draw();
    thirdQuadRec7.draw();
    thirdQuadRec8.draw();
    thirdQuadRec9.draw();

    fourthQuadRec1.draw();
    fourthQuadRec2.draw();
    fourthQuadRec3.draw();
    fourthQuadRec4.draw();
    fourthQuadRec5.draw();
    fourthQuadRec6.draw();
    fourthQuadRec7.draw();

    fifthQuadRec1.draw();
    fifthQuadRec2.draw();
    fifthQuadRec3.draw();
    fifthQuadRec4.draw();
    fifthQuadRec5.draw();
    fifthQuadRec6.draw();
    fifthQuadRec7.draw();
    fifthQuadRec8.draw();
    fifthQuadRec9.draw();
    fifthQuadRec10.draw();

    pacman.draw();
    blinky.draw();
    pinky.draw();
    inky.draw();
    clyde.draw();

    string score = "Score: " + to_string(games[currentGame].getHighScore());
    glColor3f(1, 1, 1.0);
    glRasterPos2i(200, 140);
    for (char c : score) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    string lives = "Lives: " + to_string(games[currentGame].getLives());
    glColor3f(1, 1, 1.0);
    glRasterPos2i(290, 140);
    for (char c : lives) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    if (games[currentGame].runFromStartingPositions) {
        string getReadyMsg = "GET READY";
        glColor3f(1, 1, 0);
        glRasterPos2i(220, 338);
        for (char c : getReadyMsg) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    if (games[currentGame].gameStatus == over || games[currentGame].getLives() == 0) {
        string gameOvrMsg = "GAME OVER";
        glColor3f(1, 0, 0);
        glRasterPos2i(215, 338);
        for (char c : gameOvrMsg) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    } else if (games[currentGame].gameStatus == won || games[currentGame].getLives() == 0) {
        victoryBackground.draw();
        string victoryMsg = "VICTORY!";
        glColor3f(0, 1, 0);
        glRasterPos2i(225, 338);
        for (char c : victoryMsg) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    } else if (games[currentGame].gameStatus == paused) {
        string pausedMsg = "PAUSED";
        glColor3f(1, 1, 0);
        glRasterPos2i(235, 448);
        for (char c : pausedMsg) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
}

//======================================================================================================================

void displayGameOver() {
    //TODO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% GET RID OF THIS LINE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//TODO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% GET RID OF THIS LINE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    mainMenuBtn.draw();
    string mainMenuMsg = "Back to Menu";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(225, 65);
    for (char c : mainMenuMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    string gameSummary = "Game Summary";
    glColor3f(1, 1, 1);
    glRasterPos2i(215, 120);
    for (char c : gameSummary) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    string gameOutcomeMsg = "+ You       your game";
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 170);
    for (char c : gameOutcomeMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    string outcome;
    if (games[currentGame].gameStatus == over) {
        outcome = "lost";
        glColor3f(1, 0.0, 0.0);
    } else if (games[currentGame].gameStatus == won) {
        outcome = "won";
        glColor3f(0, 1, 0.0);
    }
    glRasterPos2i(88, 170);
    for (char c : outcome) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    string scoreMsg = "+ Final Score: " + to_string(games[currentGame].getHighScore());
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 195);
    for (char c : scoreMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    string pelletsMsg = "+ Pellets Eaten: " + to_string(games[currentGame].getHighScore() / 10);
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 220);
    for (char c : pelletsMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    string livesRemMsg = "+ Lives Remaining: " + to_string(games[currentGame].getLives());
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 245);
    for (char c : livesRemMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    string livesUsedMsg = "+ Lives Used: " + to_string(3 - games[currentGame].getLives());
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 270);
    for (char c : livesUsedMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    string collisionsMsg = "+ Collisions with Ghosts: " + to_string(3 - games[currentGame].getLives());
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 295);
    for (char c : collisionsMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    std::chrono::duration<double> elapsed = finishTimer - startTimer;
    string timeMsg = "+ Elapsed Time (Seconds): " + to_string(elapsed.count());
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 320);
    for (char c : timeMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

}

//======================================================================================================================

void displayHighScore() {

    mainMenuBtn.draw();
    string mainMenuMsg = "Back to Menu";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(225, 65);
    for (char c : mainMenuMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    string highScoreTitleMsg = "Scores";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(250, 120);
    for (char c : highScoreTitleMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glColor3f(1.0, 1.0, 1.0);
    int y = 170;
    glRasterPos2i(50, y);
    for (char c : Game::displayHighScore()) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        if (c == '\n') {
            y += 25;
            glRasterPos2i(50, y);
        }
    }
}

//======================================================================================================================

void displayInstructions() {

    mainMenuBtn.draw();
    string mainMenuMsg = "Back to Menu";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(225, 65);
    for (char c : mainMenuMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    string instructionsMsg = "Controls";
    glColor3f(1, 1, 1);
    glRasterPos2i(245, 120);
    for (char c : instructionsMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    string pacManMsg = "+ Player/PacMan:";
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 170);
    for (char c : pacManMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    pacman.setCenter(175, 165);
    pacman.draw();

    string ghostsMsg = "+ Enemies/Ghosts:";
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 195);
    for (char c : ghostsMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    blinky.setCenter(175,190);
    pinky.setCenter(200,190);
    inky.setCenter(225,190);
    clyde.setCenter(250,190);
    blinky.draw();
    pinky.draw();
    inky.draw();
    clyde.draw();

    string pelletsMsg = "+ Pellets/Food:";
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 220);
    for (char c : pelletsMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    Path p1;
    p1.drawPellet(175, 215, 3);
    p1.drawPellet(195, 215, 3);
    p1.drawPellet(215, 215, 3);
    p1.drawPellet(235, 215, 3);
    p1.drawPellet(255, 215, 3);
    p1.drawPellet(275, 215, 3);
    p1.drawPellet(295, 215, 3);

    string objectiveMsg = "+ Objective: Move the PacMan in all directions to continue\nconsuming pellets.  Avoid ghosts!";
    glColor3f(1, 1, 1);
    int y = 270;
    glRasterPos2i(50, y);
    for (char c : objectiveMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        if (c == '\n') {
            y += 25;
            glRasterPos2i(63, y);
        }
    }

    string arrowMsg = "+ Arrow Keys: Use the arrow keys to move the PacMan around the board.";
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 345);
    for (char c : arrowMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

    string spaceMsg = "+ Pause: Press the space bar to pause and resume the game.";
    glColor3f(1, 1, 1);
    glRasterPos2i(50, 370);
    for (char c : spaceMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
}

//======================================================================================================================

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */
    switch(screen) {
        case start: displayStart();
            break;
        case game: displayGame();
            break;
        case gameOver: displayGameOver();
            break;
        case highScore: displayHighScore();
            break;
        case instructions: displayInstructions();
    }

    glFlush();  // Render now
}

//======================================================================================================================

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    if (key == 27) {
        // escape
        glutDestroyWindow(wd);
        exit(0);
    }

    if (screen == game) {
        switch (key) {
            case 32: {
                if (games[currentGame].gameStatus == paused) {
                    games[currentGame].gameStatus = inProgress;
                } else if (games[currentGame].gameStatus == inProgress)
                    games[currentGame].gameStatus = paused;
                break;
            }
        }
    }

    glutPostRedisplay();

    return;
}

//======================================================================================================================

void kbdS(int key, int x, int y) {
    x = pacman.getCenter().x;
    y = pacman.getCenter().y;
    x = x/20;
    y = y/20;
    if (screen == game) {
        switch (key) {
            case GLUT_KEY_DOWN:
//                if (games[currentGame].gameBoard[(pacman.getCenter().x / 20)][(pacman.getCenter().y / 20) + 1].getType() != wall) {
//                pDir = 3;
//                }
                nextPDir = 3;
                break;
            case GLUT_KEY_LEFT:
//                if (games[currentGame].gameBoard[(pacman.getCenter().x / 20) - 1][(pacman.getCenter().y / 20)].getType() != wall) {
//                pDir = 0;
//                }
                nextPDir = 0;
                break;
            case GLUT_KEY_RIGHT:
//                if (games[currentGame].gameBoard[(pacman.getCenter().x / 20) + 1][(pacman.getCenter().y / 20)].getType() != wall) {
//                pDir = 1;
//                }
                nextPDir = 1;
                break;
            case GLUT_KEY_UP:
//                if (games[currentGame].gameBoard[(pacman.getCenter().x / 20)][(pacman.getCenter().y / 20) - 1].getType() != wall) {
//                pDir = 2;
//                }
                nextPDir = 2;
                break;
        }
    }

    glutPostRedisplay();

    return;
}

//======================================================================================================================

void cursor(int x, int y) {
    if (screen == start && y > 265 && y < 295 && x > 205 && x < 355) {
        startBtn.setFillColor(255/255.0, 0, 0);
    } else {
        startBtn.setFillColor(255,238,0);
    }

    if (screen == start && y > 315 && y < 345 && x > 205 && x < 355) {
        highScoBtn.setFillColor(255/255.0, 0, 0);
    } else {
        highScoBtn.setFillColor(250/255.0,192/255.0,203/255.0);
    }

    if (screen == start && y > 365 && y < 395 && x > 205 && x < 355) {
        instructionsBtn.setFillColor(255/255.0, 0, 0);
    } else {
        instructionsBtn.setFillColor(0.5,1,1);
    }

    if (screen == start && y > 415 && y < 445 && x > 205 && x < 355) {
        exitBtn.setFillColor(255/255.0, 0, 0);
    } else {
        exitBtn.setFillColor(1,0.5,0);
    }

    if ((screen == highScore || screen == gameOver || screen == instructions) && y > 45 && y < 75 && x > 205 && x < 355) {
        mainMenuBtn.setFillColor(255/255.0, 0, 0);
    } else {
        mainMenuBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    }

    if (screen == game) {
        // have myCircle move with the mouse
        //myCircle.setCenter(x, y);
    }

    glutPostRedisplay();
}

//======================================================================================================================

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && y > 265 && y < 295 && x > 205 && x < 355) {
        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,sizeof(buffer),"%m/%d/%Y - %I:%M",timeinfo);
        string dateTimeStr(buffer);

        Game g(dateTimeStr, 0);

        games.push_back(g);
        currentGame++;
        pacman.setCenter(280, 410);

        blinky.setCenter(240,290);

        pinky.setCenter(300,290);

        inky.setCenter(220,230);

        clyde.setCenter(320,230);
        screen = game;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && y > 315 && y < 345 && x > 205 && x < 355) {
        screen = highScore;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && y > 365 && y < 395 && x > 205 && x < 355) {
        screen = instructions;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && y > 415 && y < 445 && x > 205 && x < 355) {
        glutDestroyWindow(wd);
        exit(0);
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (screen == highScore || screen == gameOver || screen == instructions) && y > 45 && y < 75 && x > 205 && x < 355) {
        screen = start;
    }

    glutPostRedisplay();
}

//======================================================================================================================

void timer(int extra) {

    if (screen == game) {
        if (games[currentGame].gameStatus != paused) {

            if (games[currentGame].runFromStartingPositions) {
//            string ready = "Ready";
//            string set = "Set";
//            string go = "GO!";
//            glColor3f(1, 0, 0);
//            glRasterPos2i(210, 200);
//            for (char c : ready) {
//                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//            }
                sleep(1);
//            for (char c : set) {
//                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//            }
                sleep(1);
//            for (char c : go) {
//                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
//            }
                //sleep(1);
                pDir = 0;
                nextPDir = 0;
                games[currentGame].runFromStartingPositions = false;
                if (games[currentGame].firstPlay) {
                    startTimer = std::chrono::high_resolution_clock::now();
                    games[currentGame].firstPlay = false;
                }
            }

            if (games[currentGame].gameStatus == over || games[currentGame].gameStatus == won) {
                games[currentGame].saveHighScore(games[currentGame].getHighScore(), games[currentGame].getPlayer());

                screen = gameOver;
                finishTimer = std::chrono::high_resolution_clock::now();
                sleep(2);
            }

            games[currentGame].gameStatus = won;
            for (int y = 0; y < games[currentGame].gameBoard.size(); y++) {
                for (int x = 0; x < games[currentGame].gameBoard[0].size(); x++) {
                    if (games[currentGame].gameBoard[x][y].getType() == pellet) {
                        games[currentGame].gameStatus = inProgress;
                    }
                }
            }
            if (games[currentGame].getLives() == 0 && games[currentGame].gameStatus != won) {
                games[currentGame].gameStatus = over;
            }

            //games[currentGame].gameStatus = won;//--------------------------------------------------------------------------------------------------------------

            //pac coords
            int x, y;
            x = pacman.getCenter().x;
            y = pacman.getCenter().y;
            x = x / 20;
            y = y / 20;
            bool moved = false;

            if (games[currentGame].gameStatus == inProgress) {
                //Left
                if (nextPDir == 0) {
                    if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                        games[currentGame].moveLeft(games[currentGame].gameBoard[x][y])) {
                        games[currentGame].moveLeft(games[currentGame].gameBoard[x][y]);
                        pacman.move(-20, 0);
                        pDir = 0;
                        moved = true;
                    }
                }
                //Right
                if (nextPDir == 1) {
                    if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                        games[currentGame].moveRight(games[currentGame].gameBoard[x][y])) {
                        games[currentGame].moveRight(games[currentGame].gameBoard[x][y]);
                        pacman.move(20, 0);
                        pDir = 1;
                        moved = true;
                    }
                }
                //Up
                if (nextPDir == 2) {
                    if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                        games[currentGame].moveUp(games[currentGame].gameBoard[x][y])) {
                        games[currentGame].moveUp(games[currentGame].gameBoard[x][y]);
                        pacman.move(0, -20);
                        pDir = 2;
                        moved = true;
                    }
                }
                //Down
                if (nextPDir == 3) {
                    if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                        games[currentGame].moveDown(games[currentGame].gameBoard[x][y])) {
                        games[currentGame].moveDown(games[currentGame].gameBoard[x][y]);
                        pacman.move(0, 20);
                        pDir = 3;
                        moved = true;
                    }
                }

                //--------------------------------------------------------------------------------------------------------------

                if (!moved) {
                    //Left
                    if (pDir == 0) {
                        if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                            games[currentGame].moveLeft(games[currentGame].gameBoard[x][y])) {
                            games[currentGame].moveLeft(games[currentGame].gameBoard[x][y]);
                            pacman.move(-20, 0);
                        }
                    }
                    //Right
                    if (pDir == 1) {
                        if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                            games[currentGame].moveRight(games[currentGame].gameBoard[x][y])) {
                            games[currentGame].moveRight(games[currentGame].gameBoard[x][y]);
                            pacman.move(20, 0);
                        }
                    }
                    //Up
                    if (pDir == 2) {
                        if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                            games[currentGame].moveUp(games[currentGame].gameBoard[x][y])) {
                            games[currentGame].moveUp(games[currentGame].gameBoard[x][y]);
                            pacman.move(0, -20);
                        }
                    }
                    //Down
                    if (pDir == 3) {
                        if (games[currentGame].gameBoard[x][y].getType() == pacMan &&
                            games[currentGame].moveDown(games[currentGame].gameBoard[x][y])) {
                            games[currentGame].moveDown(games[currentGame].gameBoard[x][y]);
                            pacman.move(0, 20);
                        }
                    }
                }
            }

            //=============================================== INKY ===============================================================

            if (games[currentGame].gameStatus == inProgress) {
                //Inky coords
                int inkyX, inkyY;
                inkyX = inky.getCenter().x;
                inkyY = inky.getCenter().y;
                inkyX = inkyX / 20;
                inkyY = inkyY / 20;

                //Left
                if (inkyDir == 0 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[inkyX][inkyY].getType() == ghost &&
                        games[currentGame].moveLeft(games[currentGame].gameBoard[inkyX][inkyY])) {
                        games[currentGame].moveLeft(games[currentGame].gameBoard[inkyX][inkyY]);
                        inky.move(-20, 0);
                    } else if (!games[currentGame].moveLeft(games[currentGame].gameBoard[inkyX][inkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 1) {
                            randDir = rand() % 4;
                        }
                        inkyDir = randDir;
                    }
                }
                    //Right
                else if (inkyDir == 1 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[inkyX][inkyY].getType() == ghost &&
                        games[currentGame].moveRight(games[currentGame].gameBoard[inkyX][inkyY])) {
                        games[currentGame].moveRight(games[currentGame].gameBoard[inkyX][inkyY]);
                        inky.move(20, 0);
                    } else if (!games[currentGame].moveRight(games[currentGame].gameBoard[inkyX][inkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 0) {
                            randDir = rand() % 4;
                        }
                        inkyDir = randDir;
                    }

                }
                    //Down
                else if (inkyDir == 3 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[inkyX][inkyY].getType() == ghost &&
                        games[currentGame].moveDown(games[currentGame].gameBoard[inkyX][inkyY])) {
                        games[currentGame].moveDown(games[currentGame].gameBoard[inkyX][inkyY]);
                        inky.move(0, 20);
                    } else if (!games[currentGame].moveDown(games[currentGame].gameBoard[inkyX][inkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 2) {
                            randDir = rand() % 4;
                        }
                        inkyDir = randDir;
                    }
                }
                    //Up
                else if (inkyDir == 2 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[inkyX][inkyY].getType() == ghost &&
                        games[currentGame].moveUp(games[currentGame].gameBoard[inkyX][inkyY])) {
                        games[currentGame].moveUp(games[currentGame].gameBoard[inkyX][inkyY]);
                        inky.move(0, -20);
                    } else if (!games[currentGame].moveUp(games[currentGame].gameBoard[inkyX][inkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 3) {
                            randDir = rand() % 4;
                        }
                        inkyDir = randDir;
                    }
                }
            }

            //=============================================== CLYDE (Orange) =======================================================

            if (games[currentGame].gameStatus == inProgress) {
                //Clyde coords (Orange)
                int clydeX, clydeY;
                clydeX = clyde.getCenter().x;
                clydeY = clyde.getCenter().y;
                clydeX = clydeX / 20;
                clydeY = clydeY / 20;

                //Left
                if (clydeDir == 0 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[clydeX][clydeY].getType() == ghost &&
                        games[currentGame].moveLeft(games[currentGame].gameBoard[clydeX][clydeY])) {
                        games[currentGame].moveLeft(games[currentGame].gameBoard[clydeX][clydeY]);
                        clyde.move(-20, 0);
                    } else if (!games[currentGame].moveLeft(games[currentGame].gameBoard[clydeX][clydeY])) {
                        randDir = rand() % 4;
                        while (randDir == 1) {
                            randDir = rand() % 4;
                        }
                        clydeDir = randDir;
                    }

                }
                    //Right
                else if (clydeDir == 1 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[clydeX][clydeY].getType() == ghost &&
                        games[currentGame].moveRight(games[currentGame].gameBoard[clydeX][clydeY])) {
                        games[currentGame].moveRight(games[currentGame].gameBoard[clydeX][clydeY]);
                        clyde.move(20, 0);
                    } else if (!games[currentGame].moveRight(games[currentGame].gameBoard[clydeX][clydeY])) {
                        randDir = rand() % 4;
                        while (randDir == 0) {
                            randDir = rand() % 4;
                        }
                        clydeDir = randDir;
                    }
                }
                    //Down
                else if (clydeDir == 3 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[clydeX][clydeY].getType() == ghost &&
                        games[currentGame].moveDown(games[currentGame].gameBoard[clydeX][clydeY])) {
                        games[currentGame].moveDown(games[currentGame].gameBoard[clydeX][clydeY]);
                        clyde.move(0, 20);
                    } else if (!games[currentGame].moveDown(games[currentGame].gameBoard[clydeX][clydeY])) {
                        randDir = rand() % 4;
                        while (randDir == 2) {
                            randDir = rand() % 4;
                        }
                        clydeDir = randDir;
                    }
                }
                    //Up
                else if (clydeDir == 2 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[clydeX][clydeY].getType() == ghost &&
                        games[currentGame].moveUp(games[currentGame].gameBoard[clydeX][clydeY])) {
                        games[currentGame].moveUp(games[currentGame].gameBoard[clydeX][clydeY]);
                        clyde.move(0, -20);
                    } else if (!games[currentGame].moveUp(games[currentGame].gameBoard[clydeX][clydeY])) {
                        randDir = rand() % 4;
                        while (randDir == 3) {
                            randDir = rand() % 4;
                        }
                        clydeDir = randDir;
                    }
                }
            }

            //=============================================== BLINKY (Red) =======================================================

            if (games[currentGame].gameStatus == inProgress) {
                //Blinky coords (Orange)
                int blinkyX, blinkyY;
                blinkyX = blinky.getCenter().x;
                blinkyY = blinky.getCenter().y;
                blinkyX = blinkyX / 20;
                blinkyY = blinkyY / 20;

                //Left
                if (blinkyDir == 0 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[blinkyX][blinkyY].getType() == ghost &&
                        games[currentGame].moveLeft(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        games[currentGame].moveLeft(games[currentGame].gameBoard[blinkyX][blinkyY]);
                        blinky.move(-20, 0);
                    } else if (!games[currentGame].moveLeft(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 1) {
                            randDir = rand() % 4;
                        }
                        blinkyDir = randDir;
                    }

                }
                    //Right
                else if (blinkyDir == 1 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[blinkyX][blinkyY].getType() == ghost &&
                        games[currentGame].moveRight(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        games[currentGame].moveRight(games[currentGame].gameBoard[blinkyX][blinkyY]);
                        blinky.move(20, 0);
                    } else if (!games[currentGame].moveRight(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 0) {
                            randDir = rand() % 4;
                        }
                        blinkyDir = randDir;
                    }
                }
                    //Down
                else if (blinkyDir == 3 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[blinkyX][blinkyY].getType() == ghost &&
                        games[currentGame].moveDown(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        games[currentGame].moveDown(games[currentGame].gameBoard[blinkyX][blinkyY]);
                        blinky.move(0, 20);
                    } else if (!games[currentGame].moveDown(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 2) {
                            randDir = rand() % 4;
                        }
                        blinkyDir = randDir;
                    }
                }
                    //Up
                else if (blinkyDir == 2 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[blinkyX][blinkyY].getType() == ghost &&
                        games[currentGame].moveUp(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        games[currentGame].moveUp(games[currentGame].gameBoard[blinkyX][blinkyY]);
                        blinky.move(0, -20);
                    } else if (!games[currentGame].moveUp(games[currentGame].gameBoard[blinkyX][blinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 3) {
                            randDir = rand() % 4;
                        }
                        blinkyDir = randDir;
                    }
                }
            }

            //=============================================== PINKY (Pinky) =======================================================

            if (games[currentGame].gameStatus == inProgress) {
                //Pinky coords (Orange)
                int pinkyX, pinkyY;
                pinkyX = pinky.getCenter().x;
                pinkyY = pinky.getCenter().y;
                pinkyX = pinkyX / 20;
                pinkyY = pinkyY / 20;

                //Left
                if (pinkyDir == 0 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[pinkyX][pinkyY].getType() == ghost &&
                        games[currentGame].moveLeft(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        games[currentGame].moveLeft(games[currentGame].gameBoard[pinkyX][pinkyY]);
                        pinky.move(-20, 0);
                    } else if (!games[currentGame].moveLeft(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 1) {
                            randDir = rand() % 4;
                        }
                        pinkyDir = randDir;
                    }

                }
                    //Right
                else if (pinkyDir == 1 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[pinkyX][pinkyY].getType() == ghost &&
                        games[currentGame].moveRight(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        games[currentGame].moveRight(games[currentGame].gameBoard[pinkyX][pinkyY]);
                        pinky.move(20, 0);
                    } else if (!games[currentGame].moveRight(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 0) {
                            randDir = rand() % 4;
                        }
                        pinkyDir = randDir;
                    }
                }
                    //Down
                else if (pinkyDir == 3 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[pinkyX][pinkyY].getType() == ghost &&
                        games[currentGame].moveDown(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        games[currentGame].moveDown(games[currentGame].gameBoard[pinkyX][pinkyY]);
                        pinky.move(0, 20);
                    } else if (!games[currentGame].moveDown(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 2) {
                            randDir = rand() % 4;
                        }
                        pinkyDir = randDir;
                    }
                }
                    //Up
                else if (pinkyDir == 2 && !games[currentGame].resetCalled) {
                    int randDir;
                    if (games[currentGame].gameBoard[pinkyX][pinkyY].getType() == ghost &&
                        games[currentGame].moveUp(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        games[currentGame].moveUp(games[currentGame].gameBoard[pinkyX][pinkyY]);
                        pinky.move(0, -20);
                    } else if (!games[currentGame].moveUp(games[currentGame].gameBoard[pinkyX][pinkyY])) {
                        randDir = rand() % 4;
                        while (randDir == 3) {
                            randDir = rand() % 4;
                        }
                        pinkyDir = randDir;
                    }
                }
            }

            //--------------------------------------------------------------------------------------------------------------

            if (games[currentGame].resetCalled) {
                games[currentGame].resetCalled = false;
                pacman.setCenter(280, 410);
                blinky.setCenter(240, 290);
                pinky.setCenter(300, 290);
                inky.setCenter(220, 230);
                clyde.setCenter(320, 230);
                if (games[currentGame].getLives() > 0){
                    games[currentGame].runFromStartingPositions = true;
                }
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

//======================================================================================================================

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner

    /* create the window and store the handle to it */
    wd = glutCreateWindow("paC++" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}