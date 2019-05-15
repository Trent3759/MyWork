/*==================================================================================================
PROGRAMMER:				Yang Wang
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		09/02/2016
DESCRIPTION:			Demo: drawing star.
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					points.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <iostream>
#include <GL/glut.h>				// include GLUT library
#include <math.h>
using namespace std;

int SELECTION;


void drawStar() {
	glEnable(GL_LINE_STIPPLE);

	if (SELECTION == 1) {
		//do no pattern
	}
	else if (SELECTION == 2) {
		glLineStipple(1, 0x00C0);
	}
	else if (SELECTION == 3) {
		glLineStipple(1, 0x8174);
	}

	
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, 80);
	glVertex2i(-30, -60);
	glVertex2i(70, 0);
	glVertex2i(-70, 0);
	glVertex2i(30, -60);
	glEnd();


	glPointSize(1);		// change point size back to 1

	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex2i(x, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex2i(0, y);
	glEnd();


}



void menu(){
	cout << "Options" << endl;
	cout << "1. Solid Line" << endl;
	cout << "2. Pattern 1" << endl;
	cout << "3. Pattern 2" << endl;

	cout << endl << "Enter your selection: ";

	cin >> SELECTION;
}





//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background clor: white 
	gluOrtho2D(-150, 150, -150, 150);  // specify a viewing area
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


