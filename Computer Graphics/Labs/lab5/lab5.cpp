/*==================================================================================================
PROGRAMMER:				Yang Wang
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		09/21/2016
DESCRIPTION:			Demo: Drawing Bitmap Text
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					lab5.cpp, (myCPPproj.sln, ...)
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

string INPUT;


void drawStar() {
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

	glColor3f(0, 1, 0);
	glRasterPos2i(0, 50);
	

	for (int i = 0; i < INPUT.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, INPUT[i]);
	}



}



void menu(){
	cout << "Please enter a message: ";
	getline(cin, INPUT);
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

	drawStar();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************


void main()
{
	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Hex Drawing");	// create a titled window


	myInit();									// setting up

	menu();

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}


