#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Board.h"
#include "tests.h"

using namespace std;

void renderGame () {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Board game_board = Board();
	game_board.draw();

	glutSwapBuffers();
}

void resizeWindow (int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	glOrtho(-0.3, 3.3, -0.3, 6.3, 0, 1.0);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv) {
	//init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,400);
	glutCreateWindow("ffviii_Card_game");

	//register callbacks
	glutDisplayFunc(renderGame);

	glutReshapeFunc(resizeWindow);

	//enter GLUT event processing cycle
	glutMainLoop();

	return 1;

}