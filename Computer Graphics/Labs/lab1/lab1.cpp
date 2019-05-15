/*==================================================================================================
PROGRAMMER:			Yang Wang
COURSE:				CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:	8/28/2016
DESCRIPTION:			Demo: drawing points.
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					points.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <GL/glut.h>				// include GLUT library
#include <math.h>

//***********************************************************************************
void drawSmiley()
{
	glColor3f(1, 0, 0);
	glPointSize(10.0);

	for (int i = 0; i <= 1000; i++)
	{
		glBegin(GL_POINTS);
		float x = (cos((2 * i*3.14) / 300)) * 140;
		float y = (sin((2 * i*3.14) / 300)) * 140;
		glVertex2i(x, y);
		glEnd();
	}
	for (int i = 0; i<300; i++) //mustache
	{
		glBegin(GL_POINTS);
		float x = sin((2 * i*3.14) / 300) * 100;
		float y = -cos((2 * i*3.14) / 300) * 100;
		if (y < 0) {
			glVertex2i(x, y);
		}
		glEnd();
	}

	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i(((150 - 10) / 3)*-1, 50);
	glVertex2f(((150 - 10) / 3), 50);
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

	drawSmiley();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void main()
{
	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Smile Drawing");	// create a titled window

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}
