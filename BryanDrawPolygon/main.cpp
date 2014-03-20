#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // no console window pop-up
#ifdef _APPLE_
#include<GLUT/glut.h>
#else
#include <GL\glut.h>
#endif
#include "Polygon.h"

void reshapeScreen(int w, int h) {
	// prevent the window height from going below 0
	if(h == 0)
		h=1;
	float ratio = 1.0 * w / h;

	// use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// reset the Matrix
	glLoadIdentity();

	// set the viewport to the size of the window
	glViewport(0, 0, w, h);

	// correct the screen perpsective
	glOrtho(0, w, 0, h, 0, w);
}

void renderPolygons(void) {
	// set clearing color 
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// first polygon - triangle - yellow
	Point c1(100,50,0);
	Color fc1(1.0, 1.0, 0.0, 0.0);
	Polygon tri(40, c1, 3, 1, GL_LINE_LOOP, fc1);
	tri.draw();

	// square - hollow - light blue(cyan)
	Point c2(100,150,0);
	Color fc2(0.0, 1.0, 1.0, 0.0);
	Polygon squ(40, c2, 4, 8, GL_LINE_LOOP, fc2);
	squ.draw();

	// pentagon - hollow - gray
	Point c3(100,250,0);
	Color fc3(0.5, 0.5, 0.5, 0.0);
	Polygon pent(40, c3, 5, 3, GL_LINE_LOOP, fc3);
	pent.draw();

	//hexagon - not hollow - red
	Point c4(200,50,0);
	Color fc4(1.0, 0.0, 0.0, 0.0);
	Polygon hex(40, c4, 6, 3, GL_POLYGON, fc4);
	hex.draw();

	// nonagon - hollow - green
	Point c5(200,150,0);
	Color fc5(0.0, 1.0, 0.0, 0.0);
	Polygon nin(40, c5, 9, 5, GL_LINE_LOOP, fc5);
	nin.draw();

	// tridecagon - hollow - purple
	Point c6(300,300,0);
	Color fc6(1.0, 0.0, 1.0, 0.0);
	Polygon thri(90, c6, 13, 3, GL_LINE_LOOP, fc6);
	thri.draw();

	glutSwapBuffers();
}

int main(int argc, char *argv[]) {
	//initalize GLUT and create the View Window
	glutInit(&argc, argv);
	// set the Window's position on the screen
	glutInitWindowPosition(100,100);
	// set the size of the window view
	glutInitWindowSize(500,500);
	// initialize the display of the window
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	// Now actually create the window
	glutCreateWindow("Bryan Gawinski - Draw Polygon");

	// register the display callback function
	glutDisplayFunc(renderPolygons);
	glutReshapeFunc(reshapeScreen);

	// enter the GLUT event processing
	glutMainLoop();

	return 1;
}
