#include "graphics.h"
#include "shapes.h"
#include <string>
#include <random>
#include "Game.h"
#include <unistd.h>
using namespace std;

enum mode {start, game, gameOver, highScore};
//enum Direction {left, right, up, down};

int pDir = 0;

int gDir = 0;

int randDir;

bool runFromStart = true;

mode screen;
GLdouble width, height;
int wd;
Game g;
Circle pacman(8);
Circle blinky(8);
Circle pinky(8);
Circle inky(8);
Circle clyde(8);

Tangle startBtn;
Tangle highScoBtn;
Tangle mainMenuBtn;

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
    startBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    startBtn.setCenter(280, 280);

    highScoBtn.setDimensions(30, 150);
    highScoBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    highScoBtn.setCenter(280, 330);

    mainMenuBtn.setDimensions(30, 150);
    mainMenuBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    mainMenuBtn.setCenter(280, 60);

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

void displayStart() {

    string message = "Welcome to paC++";
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
    string highScoMsg = "High Scores";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(233, 335);
    for (char c : highScoMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

}

void displayGame() {

    for(int y = 0; y < g.gameBoard.size(); y++){
        for (int x = 0; x < g.gameBoard[0].size(); x++){
            if (g.gameBoard[x][y].getType() == pellet) {
                g.gameBoard[x][y].drawPellet((20 * x), 10 + (20 * y), 3);
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
    thirdQuadRec3.draw();
    thirdQuadRec4.draw();
    thirdQuadRec5.draw();
    thirdQuadRec6.draw();
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

    string score = "Score: " + to_string(g.getHighScore());
    glColor3f(1, 1, 1.0);
    glRasterPos2i(210, 140);
    for (char c : score) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    string lives = "Lives: " + to_string(g.getLives());
    glColor3f(1, 1, 1.0);
    glRasterPos2i(300, 140);
    for (char c : lives) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
}

void displayGameOver() {

}

void displayHighScore() {

    mainMenuBtn.draw();
    string mainMenuMsg = "Back to Menu";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(225, 65);
    for (char c : mainMenuMsg) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glColor3f(1.0, 0.0, 0.0);
    int y = 90;
    glRasterPos2i(233, y);
    for (char c : Game::displayHighScore()) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        if (c == '\n') {
            y += 25;
            glRasterPos2i(233, y);
        }
    }
}

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
    }

    glFlush();  // Render now
}

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
            case 'l': {
                break;
            }
            case 's': {
                break;
            }
        }
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    x = pacman.getCenter().x;
    y = pacman.getCenter().y;
    if (screen == game) {
        switch (key) {
            case GLUT_KEY_DOWN:
                pDir = 3;
                break;
            case GLUT_KEY_LEFT:
                pDir = 0;
                break;
            case GLUT_KEY_RIGHT:
                pDir = 1;
                break;
            case GLUT_KEY_UP:
                pDir = 2;
                break;
        }
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {
    if (screen == start && y > 265 && y < 295 && x > 205 && x < 355) {
        startBtn.setFillColor(255/255.0, 0, 0);
    } else {
        startBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    }

    if (screen == start && y > 315 && y < 345 && x > 205 && x < 355) {
        highScoBtn.setFillColor(255/255.0, 0, 0);
    } else {
        highScoBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    }

    if (screen == highScore && y > 45 && y < 75 && x > 205 && x < 355) {
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

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && y > 265 && y < 295 && x > 205 && x < 355) {
        screen = game;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start && y > 315 && y < 345 && x > 205 && x < 355) {
        screen = highScore;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == highScore && y > 45 && y < 75 && x > 205 && x < 355) {
        screen = start;
    }

    glutPostRedisplay();
}

void timer(int extra) {


    if (screen == game) {
        if (g.resetCalled == true) {
            g.resetCalled = false;
            pacman.setCenter(280, 410);
            blinky.setCenter(240,290);
            pinky.setCenter(300,290);
            inky.setCenter(220,230);
            clyde.setCenter(320,230);
            runFromStart = true;
        }


        //pac coords
        int x, y;
        x = pacman.getCenter().x;
        y = pacman.getCenter().y;
        x = x/20;
        y = y/20;

        //ghost coords
        int gX, gY;
        gX = inky.getCenter().x;
        gY = inky.getCenter().y;
        gX = gX/20;
        gY = gY/20;
        //Left
        if (pDir == 0) {
            if (g.gameBoard[x][y].getType() == pacMan && g.moveLeft(g.gameBoard[x][y])){
                g.moveLeft(g.gameBoard[x][y]);
                pacman.move(-20,0);
            }
        }
        //Right
        if (pDir == 1) {
            if (g.gameBoard[x][y].getType() == pacMan && g.moveRight(g.gameBoard[x][y])){
                g.moveRight(g.gameBoard[x][y]);
                pacman.move(20,0);
            }
        }
        //Up
        if (pDir == 2) {
            if (g.gameBoard[x][y].getType() == pacMan && g.moveUp(g.gameBoard[x][y])){
                g.moveUp(g.gameBoard[x][y]);
                pacman.move(0,-20);
            }
        }
        //Down
        if (pDir == 3) {
            if (g.gameBoard[x][y].getType() == pacMan && g.moveDown(g.gameBoard[x][y])){
                g.moveDown(g.gameBoard[x][y]);
                pacman.move(0,20);
            }
        }

        //==============================================================================================================

        //Left
        if (gDir == 0) {
            if (g.gameBoard[gX][gY].getType() == ghost && g.moveLeft(g.gameBoard[gX][gY])){
                g.moveLeft(g.gameBoard[gX][gY]);
                inky.move(-20,0);
            } else if (!g.moveLeft(g.gameBoard[gX][gY])) {
                randDir = rand() % 4;
                while (randDir == 1) {
                    cout << "test1" << endl;
                    randDir = rand() % 4;
                }
            }
        }
        //Right
        else if (gDir == 1) {
            if (g.gameBoard[gX][gY].getType() == ghost && g.moveRight(g.gameBoard[gX][gY])){
                g.moveRight(g.gameBoard[gX][gY]);
                inky.move(20,0);
            } else if (!g.moveRight(g.gameBoard[gX][gY])) {
                randDir = rand() % 4;
                while (randDir == 0) {
                    cout << "test2" << endl;
                    randDir = rand() % 4;
                }
            }
        }
        //Down
        else if (gDir == 3) {
            if (g.gameBoard[gX][gY].getType() == ghost && g.moveDown(g.gameBoard[gX][gY])){
                g.moveDown(g.gameBoard[gX][gY]);
                inky.move(0,20);
            } else if (!g.moveDown(g.gameBoard[gX][gY])) {
                randDir = rand() % 4;
                while (randDir == 2) {
                    cout << "test3" << endl;
                    randDir = rand() % 4;
                }
            }
        }
        //Up
        else if (gDir == 2) {
            if (g.gameBoard[gX][gY].getType() == ghost && g.moveUp(g.gameBoard[gX][gY])){
                g.moveUp(g.gameBoard[gX][gY]);
                inky.move(0,-20);
            } else if (!g.moveUp(g.gameBoard[gX][gY])) {
                randDir = rand() % 4;
                while (randDir == 3) {
                    cout << "test4" << endl;
                    randDir = rand() % 4;
                }
            }
        }
        gDir = randDir;
        cout << gDir << endl;
    }

    glutPostRedisplay();
    glutTimerFunc(200, timer, 0);
}

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