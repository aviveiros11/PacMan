#include "graphics.h"
#include "shapes.h"
#include <string>
#include "Game.h"
using namespace std;

enum mode {start, game, gameOver, highScore};

mode screen;
GLdouble width, height;
int wd;

Tangle startBtn;
Tangle highScoBtn;

Tangle wall1;

void init() {
    width = 560;
    height = 560;

    screen = start;

    startBtn.setDimensions(30, 150);
    startBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    startBtn.setBorderColor(143/255.0, 42/255.0, 69/255.0);
    startBtn.setCenter(280, 280);

    highScoBtn.setDimensions(30, 150);
    highScoBtn.setFillColor(255/255.0, 189/255.0, 136/255.0);
    highScoBtn.setBorderColor(143/255.0, 42/255.0, 69/255.0);
    highScoBtn.setCenter(280, 330);

    //==================================================================================================================

    wall1.setDimensions(20, 560);
    wall1.setFillColor(0, 0, 1.0);
    wall1.setCenter(280, 10);

    //==================================================================================================================
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
    wall1.draw();
}

void displayGameOver() {

}

void displayHighScore() {

    string test = "test";

    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(233, 335);
    for (char c : Game::displayHighScore()) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
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
    if (screen == game) {
        switch (key) {
            case GLUT_KEY_DOWN:
                //myRectangle.move(0, 10);
                break;
            case GLUT_KEY_LEFT:
                //myRectangle.move(-10, 0);
                break;
            case GLUT_KEY_RIGHT:
                //myRectangle.move(10, 0);
                break;
            case GLUT_KEY_UP:
                //myRectangle.move(0, -10);
                break;
        }
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {
    if (screen == start) {

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

    glutPostRedisplay();
}

void timer(int extra) {

    if (screen == start) {

    }

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    Game g;
    cout << g << endl;

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Graphics Practice!" /* title */ );

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