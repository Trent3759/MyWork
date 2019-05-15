/*==================================================================================================
PROGRAMMER:				Yang Wang
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		10/12/2016
DESCRIPTION:			Demo: Writing text at mouse location
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					lab9.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <string>
#include <iostream>
#include <GL/glut.h>				// include GLUT library

using namespace std;

int MouseButton = 1;
string INPUT;
int rasterX;
int rasterY;


void typingText() {
	glPointSize(1);		// change point size back to 1

	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex2i(x, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex2i(0, y);
	glEnd();

	glRasterPos2i(0, 150);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'Y');

	glRasterPos2i(150, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'X');

	if (MouseButton == 1) glColor3f(0, 0, 1);
	if (MouseButton == 2) glColor3f(1, 0, 0);
	
	glRasterPos2i(rasterX, rasterY);
	
	for (int i = 0; i < INPUT.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, INPUT[i]);
	}
}


//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background clor: white 
	gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background
	typingText();
	glFlush(); // flush out the buffer contents
}

//***********************************************************************************

void type(unsigned char key, int x, int y){
	INPUT += key;
	rasterX = x - 200;
	rasterY = 200 - y;
	glutPostRedisplay();
}

void changeColor(int key, int state, int x, int y){
	if (key == GLUT_LEFT_BUTTON){
		MouseButton = 1;
		glutPostRedisplay();
	}
	else if (key == GLUT_RIGHT_BUTTON){
		MouseButton = 2;
		glutPostRedisplay();
	}
}


void move(int x, int y) {
	rasterX = x - 200;
	rasterY = 200 - y;
	glutPostRedisplay();
}

void main()
{
	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Text Writing");	// create a titled window


	myInit();									// setting up
	glutMouseFunc(changeColor);
	glutMotionFunc(move);
	glutKeyboardFunc(type);
	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}


