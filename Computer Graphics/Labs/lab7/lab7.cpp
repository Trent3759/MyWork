/*==================================================================================================
PROGRAMMER:				Yang Wang
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		09/29/2016
DESCRIPTION:			Demo: Drawing Pixels RGB
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					lab7.cpp, (myCPPproj.sln, ...)
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
#include <fstream>
using namespace std;


float autumnArray[512][512][3];

void display() {
	glPointSize(1);		// change point size back to 1

	ifstream myFile;
	myFile.open("C:\\Temp\\autumn.txt");

	if (myFile.is_open()){

		float r, g, b;

		int height = 0;
		int width = 0;

		while (myFile >> r >> g >> b){

			autumnArray[height][width][0] = r;
			autumnArray[height][width][1] = g;
			autumnArray[height][width][2] = b;

			if (!(width % 512)){
				height++;
				width = 0;
			}
			width++;
		}
		glRasterPos2f(-(512/2),-(512/2));
		glDrawPixels(512, 512, GL_RGB, GL_FLOAT, autumnArray);
	}
	else {
		cout << "File failed to open. Please try again. ";
	}

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

}


//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background clor: white 
	gluOrtho2D(-300, 300, -300, 300);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	display();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************


void main()
{
	glutInitWindowSize(600, 600);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Hex Drawing");	// create a titled window

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}


